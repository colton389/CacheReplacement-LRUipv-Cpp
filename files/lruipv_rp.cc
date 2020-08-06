/**
 * Copyright (c) 2018 Inria
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Daniel Carvalho
 */

#include "mem/cache/replacement_policies/lruipv_rp.hh"

#include <cassert>
#include <memory>
#include <vector>
#include <iterator>

#include "params/LRUIPVRP.hh"
#include "lruipv_rp.hh"

LRUIPVRP::LRUIPVRP(const Params *p)
    : BaseReplacementPolicy(p)
{
}

struct LRUIPVReplData : ReplacementData
{
	/** Tick on which the entry was last touched. */
	Tick lastTouchTick;						

	/* Used to track it's current index in the vector */
	std::shared_ptr<int> pos;

	/**
	* Default constructor. Invalidate data.
	*/
	LRUIPVReplData() : lastTouchTick(0)  {}
};

std::vector<std::shared_ptr<LRUIPVReplData>> IPVector;			// This vector will contain pointers to each replacement_data object currently in the cache

/* [0 0 2 8 4 1 4 1 8 0 14 8 12 13 14 9 5] */

/* Called whenever there is a hit or miss to update the pos of each entry */
void
updatePos(std::shared_ptr<LRUIPVReplData> replacement_data)								// 2 parts for this
{																// (1) identify new index and increment everything = to and above it	TODO
	int n = *replacement_data->pos;											// (2) set pos of the accessed date equal to tar	TODO
	std::shared_ptr<int> tar;			// saves the target index so we know which ones wo increment

	if(n == 0 || n == 1 || n == 9) {
	// case represents the current node that the data is in
	//	case 0:			// If there is a hit on data in these nodes, that data goes to node 0
	//	case 1:
	//	case 9:
		tar = std::make_shared<int> (0);
	} else if(n == 5 || n == 7) {
		tar = std::make_shared<int> (1);
	} else if(n == 2) {
		tar = std::make_shared<int> (2);
	} else if(n == 4 || n == 6) {
		tar = std::make_shared<int> (4);
	} else if(n == 3 || n == 8 || n == 11) {
		tar = std::make_shared<int> (8);
	} else if(n == 15) {
		tar = std::make_shared<int> (9);
	} else if(n == 12) {
		tar = std::make_shared<int> (12);
	} else if(n == 13) {
		tar = std::make_shared<int> (13);
	} else if(n == 10 || n == 14) {
		tar = std::make_shared<int> (14);
	} else {
		tar = std::make_shared<int> (5); 
		replacement_data->pos = tar;
		IPVector.push_back(replacement_data);
	}
	

	for (int i = 0; i < IPVector.size(); i++) {			// Updates the before inserting replacement_data into it's new index		
		if(IPVector[i]->pos >= tar)
			*IPVector[i]->pos += 1;
	}

	// Places the data into its new index
        replacement_data->pos = tar;
}

/* Sets pos to be greater than 15 */
void
LRUIPVRP::invalidate(const std::shared_ptr<ReplacementData>& replacement_data)
const
{
    // Reset last touch timestamp
    std::static_pointer_cast<LRUIPVReplData>(
        replacement_data)->lastTouchTick = Tick(0);
	
	// sets pos above 15
	*std::static_pointer_cast<LRUIPVReplData>(replacement_data)->pos = 16;
}

/* call updatePos, passing the replacement_data as the argument */
void
LRUIPVRP::touch(const std::shared_ptr<ReplacementData>& replacement_data) const
{
	// Cast replacement data
    std::shared_ptr<LRUIPVReplData> LRUIPV_replacement_data =
        std::static_pointer_cast<LRUIPVReplData>(replacement_data);

    // Update last touch timestamp
    std::static_pointer_cast<LRUIPVReplData>(
        replacement_data)->lastTouchTick = curTick();

	updatePos(LRUIPV_replacement_data);
}

/* Call updatePos to increment all POS >= 5, then create new replacement_data with pos=5, and insert them into IPVector */
void
LRUIPVRP::reset(const std::shared_ptr<ReplacementData>& replacement_data) const
{
	// Cast replacement data
    std::shared_ptr<LRUIPVReplData> LRUIPV_replacement_data =
        std::static_pointer_cast<LRUIPVReplData>(replacement_data);

    // Set last touch timestamp
    std::static_pointer_cast<LRUIPVReplData>(
        replacement_data)->lastTouchTick = curTick();

	// Sets its index to 5 and inserts it into the IPVector
	updatePos(LRUIPV_replacement_data);
}

/* Search for candidate with the highest pos*/		// TODO possibly change it so that it is looking through IPVector instead of candidates TODO find victim's location in IPVector so it can be removed
ReplaceableEntry*
LRUIPVRP::getVictim(const ReplacementCandidates& candidates) const
{
    // There must be at least one replacement candidate
    assert(candidates.size() > 0);

    // Visit all candidates to find victim
    ReplaceableEntry* victim = candidates[0];
    for (const auto& candidate : candidates) {
        // Update victim entry if necessary
        if (std::static_pointer_cast<LRUIPVReplData>(
                    candidate->replacementData)->pos >
                std::static_pointer_cast<LRUIPVReplData>(
                    victim->replacementData)->pos) {
            victim = candidate;
        }
    }

    return victim;
}

std::shared_ptr<ReplacementData>
LRUIPVRP::instantiateEntry()
{
    return std::shared_ptr<ReplacementData>(new LRUIPVReplData());
}

LRUIPVRP*
LRUIPVRPParams::create()
{
    return new LRUIPVRP(this);
}
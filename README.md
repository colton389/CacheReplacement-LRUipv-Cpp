# LRUipv-Cpp
The goal of this  implement a cache replacement policy, i.e., LRUIPV (LRU with insertion and
promotion vector) for the last level cache in gem5, and compare it performance with the built-in cache
replacement policies LRU and TreePLRU of gem5.

Included below are the console commands that were used to test each replacement policy across the different benchmarks.

BFS_randLocalGraph_J_5_120000 COMMANDS
LRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRURP()" --l2_assoc=16
TreePLRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="TreePLRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="TreePLRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="TreePLRURP()" --l2_assoc=16
LRUIPV
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRUIPVRP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRUIPVRP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_randLocalGraph_J_5_120000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRUIPVRP()" --l2_assoc=16

BFS_rMatGraph_J_5_90000 COMMANDS
LRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRURP()" --l2_assoc=16
TreePLRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="TreePLRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="TreePLRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="TreePLRURP()" --l2_assoc=16
LRUIPV
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRUIPVRP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRUIPVRP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/BFS_opt -o "benchmark/inputs/BFS_rMatGraph_J_5_90000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRUIPVRP()" --l2_assoc=16

MST_randLocalGraph_WE_5_100000 COMMANDS
LRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRURP()" --l2_assoc=16
TreePLRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="TreePLRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="TreePLRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="TreePLRURP()" --l2_assoc=16
LRUIPV
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRUIPVRP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRUIPVRP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_randLocalGraph_WE_5_100000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRUIPVRP()" --l2_assoc=16

MST_rMatGraph_WE_5_35000 COMMANDS
LRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRURP()" --l2_assoc=16
TreePLRU
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="TreePLRURP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="TreePLRURP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="TreePLRURP()" --l2_assoc=16
LRUIPV
1. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=256kB --l2_rpp="LRUIPVRP()" --l2_assoc=16
2. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=1MB --l2_rpp="LRUIPVRP()" --l2_assoc=16
3. ./build/X86/gem5.opt configs/example/se.py -c benchmark/bin/MST_opt -o "benchmark/inputs/MST_rMatGraph_WE_5_35000" --cpu-type=AtomicSimpleCPU --caches --l1i_size=35kB --l1d_size=32kB --l2cache --l2_size=4MB --l2_rpp="LRUIPVRP()" --l2_assoc=16

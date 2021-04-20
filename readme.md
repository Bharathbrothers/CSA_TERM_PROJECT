Here we describe the whole project with all the step by step instructions.

Problem: Development of a Trace driven Cache memory simulator
Language: C/C++/Java
Description: This project is to design a trace-driven simulator for cache memory.
The input to the simulator will be a trace file and a configuration file. The trace file contains a trace of the physical address of each instruction, next instruction, and an address of data. The format of the trace file is provided in Example 1, where the first address is the physical address of current instruction, the next address is the physical address of the next instruction, and the next field is data address if the data is located in memory or it is # if the data is non-memory type. The simulator is expected to read from the trace file and perform the three primary function of cache placement, locate, and replacement. As part of the simulator design, it is expected to implement the desired algorithms for each of these functions. The simulator should be configurable by the user using the input configuration file. The configuration file contains information about the essential parameters of cache architecture. Some of the essential parameters include cache memory size, block size, set size, mapping technique, replacement policies among others. As part of this project, you are expected to design a simulator for the Level 1 cache. However, as a bonus, you are encouraged to do the multilevel cache simulator.
Example 1: Trace and Configuration files
cache trace file.trc
//beginning of the file
// double slash for comment line
1000 1004 4001
1004 1008 #
.............
.............
//end of file
cache configure.cfg
//beginig of file
// double slash for comment line
cache_size = 2 MB
block_size = 65 B
word_size = 4 B

1

mapping = 0 // mapping: direct map 0, set associative 1, fully associative 2
.............
.............
//end of file
Simulator Output: The simulator is supposed to generate a sufficient number of statistics for the purpose of cache architecture study and research. Towards this, the designer is expected to produce a sufficient number of statistics on different parameters. The most important statistic being the total number of cache reference, total miss, and a total hit.
Project Outcome: A complete working simulator, a set of the test case, implementation of one of the real-life cache memories (example cache of i5, i7, or ARM A8).

Link-1:
Link-2:

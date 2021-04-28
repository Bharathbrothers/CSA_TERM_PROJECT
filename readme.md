Here we describe the whole project with all the step by step instructions.

## Problem: Development of a Trace driven Cache memory simulator
### Language: C/C++/Java

### Description: This project is to design a trace-driven simulator for cache memory.

> The input to the simulator will be a trace file and a configuration file. The trace file contains a trace of the physical address of each instruction, next instruction, and an address of data. The format of the trace file is provided in Example 1, where the first address is the physical address of current instruction, the next address is the physical address of the next instruction, and the next field is data address if the data is located in memory or it is # if the data is non-memory type. The simulator is expected to read from the trace file and perform the three primary function of cache placement, locate, and replacement.

> As part of the simulator design, it is expected to implement the desired algorithms for each of these functions. The simulator should be configurable by the user using the input configuration file. The configuration file contains information about the essential parameters of cache architecture. Some of the essential parameters include cache memory size, block size, set size, mapping technique, replacement policies among others. As part of this project, you are expected to design a simulator for the Level 1 cache. However, as a bonus, you are encouraged to do the multilevel cache simulator.


Example 1: Trace and Configuration files
cache trace file.trc
//beginning of the file
// double slash for comment line

## trace file has been updated.
```
402593:	48 85 c0             	test   %rax,%rax
402596:	74 05                	je     40259d <__strcat_chk@plt-0x23>
402598:	e8 c3 08 00 00       	callq  402e60 <__sprintf_chk@plt+0x10>
402588:	48 83 ec 08          	sub    $0x8,%rsp
40258c:	48 8b 05 4d ba 2d 00 	mov    0x2dba4d(%rip),%rax        # 6ddfe0 
.............
.............
//end of file
```

```
cache configure.cfg
//beginig of file
// double slash for comment line
cache_size = 2 MB
block_size = 64 B
word_size = 4 B

1

mapping = 0 // mapping: direct map 0, set associative 1, fully associative 2
.............
.............
//end of file
```

> Simulator Output: The simulator is supposed to generate a sufficient number of statistics for the purpose of cache architecture study and research. Towards this, the designer is expected to produce a sufficient number of statistics on different parameters. The most important statistic being the total number of cache reference, total miss, and a total hit.


> Project Outcome: A complete working simulator, a set of the test case, implementation of one of the real-life cache memories (example cache of i5, i7, or ARM A8).

LINKS: [Link-1](https://cseweb.ucsd.edu/classes/fa07/cse240a/project1.html) [LINK-2](https://www.walletfox.com/course/parseconfigfile.php)
[PRESENTATION](https://docs.google.com/presentation/d/1N7Y7w3Yhc3V5PC2zSHRcRKKsccwfdyKE3SO33aIMu58/edit?usp=sharing)


### TO-DO:
- [X] BASIC INPUT READING FROM BOTH FILES
- [X] PLACING THE BLOCKS INTO CACHE WHICH IS VECTOR UNTIL IT FILLS
- [ ] UPDATING BLOCKS INTO STRUCTS BY CREATING STRUCT OBJECTS
- [ ] CACHE REPLACEMENT BY 3 METHODS
  - [ ] LRU by checking for *least recently used or the previous requests*
  - [ ] FIFO by *replacing from beginning of cache vector(old ones first replaced)*
  - [ ] RANDOM by *selecting a random block in cache*  
- [ ] CALCULATING HIT AND MISS RATIO FROM ABOVE by *taking cache into a set and checking in O(1) for the present element*
- [ ] MAPPING TECHNIQUES (better to implement one set associative function with k as input or parameter based on value we call these functions as all are variants of set associative mapping)
  - [ ] DIRECT by *cache block = mod of main block (this is nothing but 1 set associative where each block will be in 1 set)*
  - [ ] FULLY ASSOCIATIVE *can be placed anywhere as whole cache is one set(this is nothing but n set associative where all blocks in cache are in 1 set)*
  - [ ] SET ASSOCIATIVE *cache set = mod of main block*
 - [ ] IMPLEMENTING IN SIMPLESCALAR SIMULATOR *not sure whether we will do it completely or not*     

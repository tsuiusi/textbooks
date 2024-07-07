# Chapter 4: Memory Management
> wahoo! i'ma gonna win! i'ma wario!

Some definitions:
* Memory hierarchy: self explanatory
* Memory manager: manages the hierarchy, part of the OS
    * Keeps track of which part is in use, allocating memory to processes, deallocating, manage swapping between memory and disk when not enough RAM
    * Usually in the kernel

## Basic memory management
Two classes of memory management systems:
1. Those that move processes back and forth between main memory and disk during execution (swapping and paging)
2. Those that don't

Swapping and paging are artifacts caused by lack of RAM.

> Now Microsoft recommends having at least 128 MB for a single-user Windows XP system.
What a time to be alive

### Monoprogramming (no swapping/paging)
* One program at a time, share memory between program and OS
* 3 models (basic)
    1. Mainframes and minicomputers, obselete
    2. Palmtop computers and embedded systems
    3. Early PCs (MS-DOS) where portion of the system in ROM is called the BIOS (basic I/O system)
* Single threaded

![memmanmodels](memmanmodels.png)

### Multiprogramming with fixed partitions
* Multiple processes, at the same time
* Rarely used anymore? 
* Partition memory, queue processes in the smallest partition big enough to hold it
* Disadvantage is when large queues become empty but the small queues are extremely packed
* Counter for no. skips can be implemented to speed up queues

![partitionqueues](partitionqueues.png)

### Relocation and Protection
* Problems introduced by multiprogramming
* Protection problem: protecting the memory from unauthorized access
* Relocation problem: when a program is linked (combined into a single address space) the linker where each program begins in memory
    * Doesn't always solve protection problem if malware constructs new instruction and jumps to it
    * Absolute memory addresses used rather than relative, no way to stop a program from building an instruction that RWs to memory
* IBM's solution was to use a 4bit protection code for every 2KB of memory, so the hardware traps any processes running that has the wrong code
* Only the OS can change the codes

Another solution is to use a **base** and a **limit** hardware register
* The base register loads the address of the start of partition, limit loaded with length
* Each memory automatically has base register contents appended to it (CALL 100 -> CALL 100k + 100 if base = 100k)
* Slow, obselete

## Swapping
In batch systems, jobs are loaded into partitions and stay there until they're done. In timesharing systems, however, there might not be enough RAM to hold the processes, so the disk must be used to keep extra processes
* Swp memory and virtual memory
* See diagram
* Can compact all the processes and move them down as far as possible in a process called *memory compaction*; not often done because it requires a lot of CPU time

![swap](swapmemory.png)



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

![memmanmodels](src/memmanmodels.png)

### Multiprogramming with fixed partitions
* Multiple processes, at the same time
* Rarely used anymore? 
* Partition memory, queue processes in the smallest partition big enough to hold it
* Disadvantage is when large queues become empty but the small queues are extremely packed
* Counter for no. skips can be implemented to speed up queues

![partitionqueues](src/partitionqueues.png)

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

![swap](src/swapmemory.png)

Memory is allowed to grow either via switching holes (like hermit crabs) or allocated extra memory when it starts; else they're blocked/killed.

![extramemory](src/extramemory.png)

### Memory management with bitmaps
When memory is assigned dynamically, the OS must manage it, either via **bitmaps** or **free lists** (basically a linked list).

Bitmaps:
* Memory divided up into allocation units in the byte-kilbyte range
* Corresponding to each unit in the bitmap is a 1 or 0 (T/F)
* The smaller the unit, the larger the bitmap 
* Good for fixed-size memory
* Issue is that if you want to add another process of size *k*, you need to find *k* consecutive units and that's slow

![bitmap](src/bitmapallocation.png)

### Memory management with linked lists
What did I say?

Linked lists:
* Entries:
    * Hole/Process
    * Start address
    * Length
    * Pointer to next entry
* Algorithms used to allocate memory to newly created processes
    * First fit
    * Next fit

First fit:
* Scan list of segments until you get the first hole that fits the process
* Break hole into two - one for process, one for unused memory

Next fit:
* Same thing, but keeps track of where the next suitable hole is
* Slightly worse

Best fit:
* Searches the whole list for the hole that fits the best
* Slower
* First fit generates larger holes on average

There's also worst fit, to take the biggest hole possible, but that's not good

Quick fit: 
* Maintain separate lists for common sizes (standards)
* Expensive, but very fast

## Virtual memory
When programs are too big to fit into memory (like ImageNet dataset)

**Overlays**: splitting the program into pieces, and running them sequentially
* Operations done by the system
* Virtual memory: the combined size may exceed the actual available physical size, rest is kept on disk
* Works with multiprogramming devices

### Paging
* On any computer there exists a set of memory addresses that programs can produce
* When the program uses an instruction (e.g MOV REG, 1000), it does this to copy the contents of 1000 to REG
* **Virtual addresses** - these program-generated addresses, form **virtual address space**
* When virtual memory is used, they don't go to the memory bus; instead, they go to a Memory Management Unit that maps the virtual addresses onto physical memory addresses

![mmu](src/mmu.png)

Virtual Address Space:
* Divided up into units - **pages**; corresponding units in physical memory - **page frames**
* Always the same size, transfers between RAM and disk are always in page units
* MMU maps the instructions between virtual and physical memory space
* A **present/absent bit** keeps track of which pages are physically present in memory
* If the program tries to use an unmapped page, the MMU notices the fact and causes the CPU to trap the OS - **page fault**
    * The OS takes a little-used page frame, writes the contents to the disk, and puts the new page in its place
* Page table is used to keep track of everything

![memmapping](src/memmapping.png)
![mmuinternals](src/mmuinternals.png)

### Page tables
Virtual address is split into a virtual page numer (higher order bits) and an offset (lower order bits) 
* The offset deterines the size of the partition (like when you boot Arch)
* VPN is used to find page frame number

The page table must be a) very big and b) very fast
* Each process has its own page table
* Addresses are at least 32 bits, very big
* Must be done on every memory reference, bottleneck
* Can either be switched constantly or entirely kept in the main memory - all hardware points to start of table, works from there

### Multilevel page tables
Very popular.

Split the whole virtual address into the PT1 field, PT2 field, and offset field
1. MMU first uses PT1 to index into the top-level page table and obtain the first entry
2. Then it uses PT2 to extract entry 3, which corresponds to a specific address inside that 4M chunk, which contains the page frame number of the page containing the address
3. If that page is in memory, the page frame number taken from the second-level page table is combined with the offset to construct a physical address; else, it causes a page fault (not there)

![multilevelpt](multilevelpt.png)
* Only 4 page tables are needed - top leve, second levels for 0-4M, 4-8M, and the last 4M
* Can be expanded to any levels, but tradeoffs make the effectiveness vary

### Structure of a PT entry
> Highly machine dependent, but information is basically the same
![typicalentry](src/typicalentry.png)
* Page frame number
* Present/absent bit: whether the page/entry is valid/exists
* Protection: access rights, 1=read only/0=rw; more bits = more options
* Modified: page usage, bit used when OS decides to reclaim a frame; modified -> dirty, not -> clean
* Referenced: set whenever the page is referenced (RW), choosing which page to evict when fault occurs
* Last bit is used for disabling caching

### Translation lookaside buffers
> Table of contents so the OS doesn't have to go through the whole process every time, but checking the corresponding page fram.
* Virtual address presented to the TLB -> valid match -> page frame taken from TLB
* Speeds up paging
* If it doesn't exist, it does a normal lookup

TLBs are stored inside the MMU and contains a much smaller no. entries (usually 8-64)

TLB management:
* Making them more efficient/error robust
* Sometimes the OS guesses which pages are used next to preload them onto the TLB
* More caches?

### Inverted page tables
* One entry per page frame in real memory
* Indexed by page frame, not virtual page number
* TLB can hold the heavily used pages, and with a hash table hashed onto the virtual address, all the virtual pages in memory with the same hash value are chained together

![invertedcomparison](src/invertedcomparison.png)

## Page Replacement Algorithms
> Choosing which page to replace when all the pages frames are full

### Optimal page replacement algorithm
* Page with the highest label should be removed
* Unrealizable - no way of knowing which instruction will be used when, which page is next referenced
* But we can use this to compare other algorithms against. The theoretical optimum.

### Not recently used page replacement 
* Status bits (as described above) are used to hold statistics 
* 4 classes for the combinations of referenced (T/F) and modified (T/F) 

||Referenced|Modified|
|Class 0|F|F|
|Class 1|F|T|
|Class 2|T|F|
|Class 3|T|T|

**Not recently used** removes a page at random from the lowest-numbered nonempty class.

### First in, last out page replacement
* Page at the head is removed, but not very useful since the head might be the most frequently used
* Not very commonly used

### Second chance page replacement
* Modification of FIFO
* Inspecting the R bit of the oldest page - if it's one, then it's put onto the end

### Clock page replacement
![clockreplacement](src/clockreplacement.png)
* Same thing as above, but more efficient as it's in a circular list
* Head is given by the pointer

### Least recently used
* Not cheap
* Linked list of all pages in memory required, most recently used in front and vice versa
* For every reference, everything needs to be updated, which makes it annoying
* Implemented with special hardware that holds the values in a matrix

### LRU in software
* 

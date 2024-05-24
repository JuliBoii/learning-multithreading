# Computer with Multiple Processors

- Several ways to achieve this
- Multiple sockets
  - 2 or more processor chips in the computer
- Multiple processor cores
  - Several processors within the same silicon chip
- Hyper-threads
  - Duplicate some of the circuitry within a processor core
  - Enough to run a separate thread, with its own execution stack

---

## Memory

- The problems mentioned for Computers with Single Processor, are still there
- Processor speed has increased hugely
- Memory performance has not kept up
- Designers had to find new ways to improve performance
  - One approach was to more registers
    - Many more registers for storing data and code in the processor
  - Another approach was to add more caches
    - Additional caches between processors and main memory

---

### Multiple Levels of Cache

- Level 1 cache
  - Private to each processor core
  - As close to the core as possible
- Level 2 cache
  - Usually private to each core
  - Some architectures where Level 2 caches are shared between neighboring cores 
- Level 3 cache
  - Shared by all the cores on the same socket, in the same chip

---

### Cache Controller

- Coordinates the caches
  - The same data should have the same value in all caches
  - The same data should have the same value in all cores
  - "Cache coherency"
    - The shared data is coherent across all cores and caches
- Monitors caches for data changes
  - A core modifies data in its level 1 cache
  - The data is updated in the core's level 2 cache
  - The data is updated in the level 3 cache
  - The data is updated in the other core's caches

---

### Typical Cache Sizes and Latency

- Intel "Coffee Lake" architecture (2018)
  - Level 1 cache 32kB data, 32kB instructions per core
  - Level 2 256kB data per core
  - Level 3 cache 2-12MB data shared by all cores
- Latency measures the time taken to retrieve data
  - Level 1 cache 4 cycle
  - Level 2 cache 12 cycle
  - Level 3 cache 26-37 cycle
  - Main memory ~300 cycles

---

## Optimization

- Pre-fetcher
  - Looks at incoming instructions
  - Fetches data before it is needed
- Store buffer
  - This is between the core and the level 1 cache
  - Modified data is written to this buffer
- The core can proceed to the next instruction
  - Does not need to wait for the L1 cache
- These optimizations provide huge improvements
  - Avoid blocking the core when there is a cache miss

---

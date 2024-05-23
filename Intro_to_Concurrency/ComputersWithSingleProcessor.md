# Computer with Single Processor (1980's)

- We need to know a bit about how computers work
  - In order to write multithreaded programs that are:
    - Safe
    - Efficient
  - To understand what our multithreaded programs are actually doing
- Big and complicated subject, so this is the bare minimum

- In the 1980s, a simple computer had
  - A CPU (Central Processing Unit)
    - Does the actual processing:
      - Number crunching
      - Data Manipulation
    - Has memory cells inside it, called registers
      - Store information about the instruction which the processor is currently processing
        - That would be the instruction from a program
    - The processor will fetch each instruction from main memory
      - And store it in one of its registers
    - To store a value, the processor has to send it to the RAM
  - RAM (Random Access Memory)
    - Main memory
      - The entire program instructions are loaded up into main memory
        - When the program starts
      - Along with any data
        - Either data which is created when the program starts
        - Or data which comes into existence, as the program executes
  - Among various other components

---

## Single-threaded Program on Computer with Single Processor

- A program runs on a single processor
  - The program's instructions are loaded from memory
  - The instructions are executed on the processor
- Registers store information needed to execute the current instruction
  - Stack pointer
    - Accessing local data, which is on the program stack
  - Operand arguments
    - Such as the numbers which are being added together
  - etc.
    - Some other administrative information
- Data is loaded from memory into processor registers as needed
- If modified, the new value is then written back to memory
- _It is actually possible to get these single processor systems to run multiple task_
  - Done by time slicing
- _It is also possible to have threading on a single processor, also with time slicing_

---

## Multi-threaded Program on Computer with Single Processor

- Implement by "time slicing"
- Each thread runs on the CPU for a short time, e.g.
  - Thread A starts, runs for a short period, then pauses
  - Thread B starts, runs for a short period, then pauses
  - Thread C starts, runs for a short period, then pauses
  - Thread B runs again from where it left off, then pauses
  - Thread C runs again from where it left off, then pauses
- This is done very quickly
- The threads appear to run concurrently

---

## Thread Scheduler

- A scheduler controls how threads execute
  - Similar to the operating system's scheduler for processes
- Pre-emptive task switching
  - A thread can run for a certain time
  - The scheduler will interrupt the thread when it has used up its time slot
  - Another thread can then run
  - The scheduler will make interrupted thread "sleep"

---

### Thread Scheduling

- Threads may start in any order
- A thread may be interrupted at any time
- A thread may be restarted at any time
- _**Not safe to assume when you will, or will not, be running**_
- While a thread is sleeping, another thread may run
  - This can run the same code as the inactive thread
  - It can access data which it shares with the inactive thread
- The execution of the threads is interleaved
  - Thread B starts and is interrupted
  - Thread A starts and is interrupted
  - Thread C starts and is interrupted
  - Thread A executes some more instructions and is interrupted
  - Thread B executes some more instructions and is interrupted

---

### Disadvantage of Time Slicing

- Requires a "context switch"
- Save the processor state for the current thread
  - Current values of processor registers
  - Program's instruction pointer
  - etc.
- Load the saved processor state for the next thread
  - Values of processor registers when stopped, etc
  - May also have to reload the thread's instructions and data
- The processor cannot execute any instructions during a context switch

---

# Computer with Single Processor and Cache (1990's)

---

## Cache

- CPUs became much fast at processing instructions
- However, RAM access speed did not improve very much
- The CPU could not process instructions during data transfers
  - The CPU spent a lot of time waiting for RAM to respond
  - Memory latency became a problem
    - latency: how long does it takes before something happens
- Computers started using small amounts of "cache" memory

- Cache Memory
  - Physically close the CPU
  - Stores copies of current and recently used data
  - Reduces the time spent communicating with main memory
- Use "static" RAM
  - This is faster than the "dynamic" RAM used in main memory
  - More expensive
  - Uses more power
  - Usually much smaller than main memory

---

## Cache Fetch

- The CPU wants to fetch data
- Does the cache have a copy of the data?
  - Yes
    - There is a "cache hit"
    - The CPU uses that copy
  - No
    - There is a "cache miss"
    - The data is fetched from main memory

---

## Cache Write

- The CPU wants to store data
- It writes the data to the cache
- The data in the cache is written to main memory
  - The CPU can continue working while this happens

---

## Cache Controller

- The process is managed by a "cache controller"
- The data is transferred in fixed-size blocks
  - Known as "cache lines"
  - Typically 64 bytes on modern hardware (8 words)
- Each cache line relates to an address in main memory

---
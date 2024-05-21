# Intro to Concurrency

---

## Concurrency

- Perform two activities at the same time
  - Conceptually different
- e.g. A program which executes a long-running task
  - Fetching data over the network
  - Performing a lengthy computation
- The program displays "feedback" to the user
  - "Hourglass" cursor
  - Progress counter
- The task and the feedback are performed at the same time

---

### Concurrency and Operating Systems

- Standard in operating systems for many years
- Computers run many programs at the same time
  - Compiler generates code
  - Word-processor waits for next keystroke
  - Mail program fetches a new email

---

### Hardware Concurrency

- Modern computers have multiple processors
  - Multiple CPU chips
  - CPU chips which contains multiple processor "cores"
- Different processors can perform different activities at the same time
  - Even within the same program
- These are known as "hardware threads"
  - Each processor follows its own "thread of execution" through the code
  - 1 hardware thread <=> 1 processor core

---

### Software Concurrency

- Modern operating systems support "software threading"
- A program can perform multiple activities at the same time
  - These activities are managed by the operating system
- Typically there are more software threads than hardware threads
  - Some threads may have to stop and wait for something
  - While they are waiting, another thread which is ready can run

---

## Concurrency Motivation

- Why is concurrency so important?
  - Had been used by mainframes since the 1960's
  - Became wider concern in the mid 1990's
- Four main industry trends:
  - Rise of the internet
    - Server throughput had to increase dramatically
  - Popularity of Windows
    - Separation of concerns (responsiveness)
  - Popularity of games and multimedia
    - Fast numeric computation
  - Availability of multicore processors
    - Effective use of hardware

---

### Server Throughput

- Single-threaded server
- Performs each activity as a single "process"
  - An instance of an executing program
- A server process waits for a client to connect to it
- When a client connects, the server creates a new process
  - The child process handles the client
  - The server waits for the next connection
- The server may need to communicate with a child process
  - Control its execution
  - Exchange data with it
- This requires "Interprocess Communication" (IPC)
- Single-threading causes overhead
  - process creation
  - setting up IPC
  - _Meaning that it involves quite a lot of extra memory usage and increased execution time._
- Reduces scalability
  - As you add more and more server processes, the number of users you can handle does not increase as much as you like it to.

---

### Separation of Concerns

- Single-threaded program to edit documents
- The user starts a long-running action
  - e.g. Indexing or formatting a large document
- The program cannot respond to GUI events immediately
  - It is executing code to perform the action
- The user interface ignores mouse clicks, key presses, etc.
  - If the program is covered up by another application and then uncovered, it turns into a grey box
- Eventually the action ends
  - The program processes all the stored-up GUI events
  - Usually with undesirable consequences!
  - Poor user experiences

---

### Fast Numeric Computation

- Used to require specialized hardware
  - Supercomputers and transputers with large numbers of processors
  - Parallel processing architecture
  - Specialized programming languages
  - Very expensive!
- Now feasible on modern general-purpose hardware
  - Much lower cost
  - Supported by standard programming languages
- But not with single-threaded programs!

---

### Effective Use of Hardware

- Demand for faster and more powerful computers
  - Make the processor bigger
  - Raise the clock frequency
- Hardware engineers approaching physical limits
  - Speed at which electrons can move through silicon
  - Heat generated
- Hardware designers began using "cores" instead
  - Several processors on the same silicon chip
- A single-threaded program can only run on one core at a time
  - Only uses a fraction of the system's potential

---

### Benefits of Concurrency

- Server throughput
  - The child and server run in the same process
  - No overhead from creating processes
  - Can have direct access to each other's data
- Separation of concerns
  - A program can respond to GUI events while performing a long-running task
  - Improves the user experience
- Fast numeric computation
- Effective use of Hardware
  - A program can execute on different cores at the same time

---

## Single-threaded Concurrency

- Each activity requires a separate process
  - has one execution path or "thread" through the program's code
- May need "interprocess communication"
  - Message queue, pip, semaphore, shared memory, network socket, etc.
- e.g. Program which displays a progress counter
- Each process has its own private memory space
  - Cannot accidentally alter another process's data
- Processes can be run on different computers over a network
- Creating a new process can be slow on some systems
- IPC (Interprocess Communication)
  - Adds complication
  - Can be slow to set up
  - No direct support in C++

---

## Multi-threaded Concurrency

- A single process performs all activities
- Each activity has its own execution path or "thread"
- Concurrency is achieved by starting a new thread for each activity

---

## Threads

- Each thread is an independent execution environment
  - Has its own execution stack
  - Has its own processor state
- Threads are "light weight processes"
  - Less overhead to start up
  - Smaller task switching overhead
  - Easy to share data between threads
- All the threads in a process share its memory space
  - Can access global data
  - Pointers can be passed between threads
- _**Lack of data protection between threads**_
  - Can cause data inconsistency and data corruption
  - _Requires careful programming_

---

## Advantages of Concurrency

- Improves responsiveness of the program
  - The user is never left starting at a "stuck" program
- Improves throughput
  - Processing large amounts of data in parallel takes less time
- Allows separation of logically distinct operations
  - e.g. mail program starts new threads
  - Compose an email
  - New fetch messages, etc.
- Takes full advantage of modern hardware
  - Threads can be distributed among processor cores

---

## Disadvantages of Concurrency

- _**Adds complexity to programs**_
  - Code is harder to write and harder to understand
  - Bugs are more likely
  - Requires careful programming
- _**May not result in faster programs**_
  - Data protection overhead
  - Thread coordination overhead
- **Use only when the benefits outweigh the costs!**

---
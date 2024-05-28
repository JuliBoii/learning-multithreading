# Multiple Threads

---

## Starting multiple threads

- We can start multiple threads
  - Implementation for C++11 compilers
```c++
// Start 3 threads
std::thread thr1(hello);
std::thread thr2(hello);
std::thread thr3(hello);

// Wait for them to finsih
thr1.join();
thr2.join();
thr3.join();
```
- If you have a C++20 compiler
  - You can just use `jthread()`
  - Which will call `join()` internally
```c++
std::jthread thr1(hello);
std::jthread thr2(hello);
std::jthread thr3(hello);
```
- The threads will be executing in sequence, not concurrently

---

## Data Sharing Between Threads

- The threads in a program share the same memory space
  - It is very easy to share data between the threads
- The only requirement is that the data is visible to the thread functions
  - Global or static variable, for global thread functions
  - Static class member, for class member thread functions
  - Local variable captured by lambda expressions (by reference)
    - _**Has to be by reference**_
- Threads interleave their execution
- Threads can interfere with each other's actions
- Modifying shared data can cause data corruption
  - _**This is the main source of bugs in concurrent programs**_

---

## _**Data Race**_

- A "data race" occurs when:
  - Two or more threads access the same memory location
  - And at least one of the threads modifies it
  - _Potentially conflicting accesses to the same memory location_
- **Only safe if the threads are synchronized**
  - One thread accesses the memory location at a time
  - The other threads have to wait until it is safe for them to access it
  - In effect, the threads execute sequentially while they access it
- A data race causes undefined behavior
  - The program is not guaranteed to behave consistently

---

## Race Condition

- The outcome is affected by timing changes
  - e.g. One client clears a database table
  - Another client inserts an entry into the same table
- A data race is a special case of a race condition
  - The outcome depends on when threads are scheduled to run

---

## Memory Location

- In C++, a "memory location" is a scalar object:
  - A built-in variable
  - A pointer
  - An element in a container
- Or a scalar sub-object:
  - A struct or class member which is a scalar object
- Also, an obscure case:
  - A series of contiguous bitfields within the same word
  - Unless they contain a zero-length bitfield (!)

---

## Compound Objects

- C++ STL containers are memory locations
  - Multiple threads modifying the same object may conflict
  - Should be synchronized
- For our own types, we can choose the behavior
  - Classes can provide their own synchronization
  - Easier to work with
  - Calling a sequence of member functions may be problematic
  - Usually better to implement them as memory locations

---
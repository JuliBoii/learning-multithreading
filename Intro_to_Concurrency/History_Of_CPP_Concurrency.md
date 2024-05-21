# Brief History of C++ Concurrency

---

## Multi-threading with C API's

- At first, no direct support for threads in C++
- Programmers could only use threads through C interfaces
  - pthreads library
    - For POSIX systems
  - Windows API
    - Provided access to threads in the "Base Services"
  - Various Unix API's
    - System calls provided access to operating system's thread support
    - Varied between providers
  - OpenMP
    - Process C-style array loops in parallel

---

## Multi-threading with C++ API's

- Later, C++ libraries appeared
  - ACE
    - Cross-platform networking library with support for threads
  - Boost
    - Project to develop new features for C++
    - Basically a wrapper around the operating system's threading facilities
    - Provided a consistent interface
    - Used as basis for C++11's thread support
  - Poco
    - More modern and lightweight version of ACE

---

## Multi-threading with Standard C++

- C++ added support for concurrency in 2011
- Programmers can write threaded code which is:
  - Portable and efficient
  - Has well-defined semantics
  - Allows fine-grained controls at low levels
- Standard Library changes
  - Features added to create and manage threads
  - All classes and functions made thread-safe
- We will only consider standard C++ features in this course

---

## Multi-threading with C++11

- The `std::thread` class is the base level of concurrency
  - Rather low-level implementation
  - Maps onto a software thread
  - Managed by the operating system
  - Similar to Boost threads, but with some important differnces
    - No thread cancellation
    - Different argument passing semantics
    - Different behavior on thread destruction

### Multi-threading with later C++

- C++14
  - Read-write locks
- C++17
  - Many standard algorithms can execute in parallel
- C++20
  - Joining threads
  - Thread cancellation
  - Coroutines, semaphores, latches and barriers
- C++23
  - Improved support for coroutines

---

## Threads and Tasks

- The words are often used interchangeably
- In this course:
  - A thread is:
    - A software thread
    - An object of the C++ `std::thread` class
  - A task is:
    - A higher-level abstraction
    - Some work that should be performed concurrently
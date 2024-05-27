# Managing A Thread

---

## Detaching a Thread

- Instead of calling `join()`, we can call `detach()`
  - The two threads will execute, completely independent of each other
    - The parent thread will continue executing
    - The child thread will run until it completes
  - Or the program terminates
  - Analogous to a "daemon" process
- When an execution thread is detached
  - The `std::thread` object is no longer associated with it
  - The destructor will no call `std::terminate()`

---

## Exception in Parent Thread

- The destructors are called for every object in scope
  - Including `std::thread's` destructors
  - This checks whether `join()` or `detach()` have been called
  - If neither, it calls `std::terminate()`
- We must call either `join()` or `detach()` before the thread is destroyed
  - In all paths through the code

---

### Try/Catch Solution

- The obvious solution is to add a try/catch block
```c++
{
  std::thread thr(func);
  try {
    ...             // Code which might throw an exception
    thr.join();     // No exception if we got here - call join() as usual
  }
  catch (std::exception& e) {
    thr.join();     // Call join() before thr's destructor is called
  }
}           // Calls ~thr()
```

---

### RAII Solution

- A better solution is to use the RAII idiom
  - Wrap the `std::thread` object inside a class
  - The class's destructor calls `join()` on the `std::thread` object
- An `std::thread` object can only be joined once
- The `joinable()` member function
  - Returns `false`
    - If `join()` or `detach()` have already been called
  - Or if the thread object is not associated with an execution thread
- Return `true` if we need to call `join()`

---

### Code using RAII Class

- The destructors are called in reverse order
  - The `thread_guard's` destructor is called first
  - If necessary, it calls `thr.join()` and waits for the execution thread to finish
  - The `thread_guard's` `std::thread` member is then destroyed
  - It is not associated with an execution thread
  - Its destructor does not call `std::terminate()`
- This applies in normal execution
  - And when an exception is thrown

---

## Stopping Threads

- Execution threads can be interrupted or stopped
  - Killed, cancelled, terminated
- In general, abruptly terminating a thread is not a good idea
  - As threads may need to:
    - Write data to a file
    - Close connections
    - Release locks, etc.
- `std::thread` does not support this
  - The Williams book has an `interruptible_thread` class
  - It is also possible to get the native_handle() for the thread of execution
    - The operating system can be used to stop the underlying execution thread

---

## C++20 and `std::jthread`

- Destructor does not call `std::terminate()`
  - Calls `join()` if necessary
- Supports cooperative interruption
  - Meaning, you can ask a jthread to suspend itself

---
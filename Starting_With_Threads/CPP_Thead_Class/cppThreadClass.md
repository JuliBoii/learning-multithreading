# The C++ Thread Class

---

## `std::thread` Class

- Implemented using RAII
    - Similar to `std::unique_ptr`, `std::fstream`, etc
    - The constructor acquires a resource
    - The destructor releases the resource
- An `std::thread` object has ownership of an execution thread
    - Meaning we cannot copy thread objects
        - Because that means we would have two objects bound to the same system resource
        - Only one object can be bound to an execution thread at a time
    - Meaning that threads are move only

---

## `std::thread` and Move Semantics

- Move-only class
    - `std::thread` objects cannot be copied
- Move operations
    - Transfer ownership of the execution thread
        - Ex: If we move object `a` into object `b`
          `b = std::move(a);`
            - Object `b` becomes the owner of the execution thread
            - Thus, need to call `join` on object `b` not object `a`
            - Object `a` is now empty
    - The moved-from object is no longer associated with an execution thread

---

## Passing a `std::thread` object

- Must-use pass by move
```c++
// Function taking a thread object as argument
void func(std::thread thr);

// Pass a named object
// Use std::move() to cast it to rvalue
std::thread thr(...);
func(std::move(thr));

// Pass a temporary object
func(std::thread(...));
```
---

## Returning a `std::thread` Object

- The compiler will automatically move it for us
```c++
// Function returning a std::thread object
std::thread func() {
  // Return a local variable
  std::thread thr(...);
  return thr;
  
  // It is a bad idea to put a call to std::move() here,
  // because that may confuse the compiler
  // return std::move(thr);
  
  // Return a temp object
  return std::thread(...);
}

```

## Threads and Exceptions

- Each thread has its own execution stack
- This stack is "unwound" when the thread throws an exception
  - The destructor for all objects in scope are called
  - The program moves up the thread's stack until it finds a suitable handler
  - If no handler is found, the program is terminated
- Other threads in the program cannot catch the exception
  - Including the parent thread and the main thread
- Exceptions can only be handled in the thread where they occur
  - Use a try/catch block in the normal way

---
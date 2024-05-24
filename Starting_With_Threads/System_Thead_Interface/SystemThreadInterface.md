# System Thread Interface

- `std::thread` uses the system's thread implementation
- We may need to use the thread implementation directly
- Some functionality is not available in standard C++
- Thread priority
  - Give a thread higher or lower share of processor time
- Thread affinity
  - "Pin" a thread on a specific processor core

---

## `native_handle()`

- Each execution thread has a "handle"
  - Used internally by the system's thread implementation
  - Needed when making calls into the implementation API
- Returned by the `native_handle()` member function
```c++
// Get the handle associated with an std::thread object
thr.native_handle();
```

---

## `std::thread` ID

- Each execution thread has a thread identifier
  - Used internally by the system's implementation
- Guaranteed to be unique
  - If two thread identifiers are equal, the related objects are identical
  - Could be used to store `std::thread` objects in associative containers
  - _A new thread may get the ID of an earlier thread which has completed_
```c++
// Return the identifier of the current thread
std::this_thread::get_id();

// Return the identifier assocaiated with an std::thread object
thr.get_id();
```

---

## Pausing Threads

- We can pause a thread or make it "sleep"
```c++
std::this_thread::sleep_for();
```
- Takes an argument of type `std::chrono::duration`
```c++
// C++14
std::this_thread::sleep_for(2s);

// C++11
std::this_thread::sleep_for(std::chrono::seconds(2));
```
- This also works with single-threaded programs
  - Pauses the thread which executes `main()`

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
std::thread thr(…);
func(std::move(thr));

// Pass a temporary object
func(std::thread(…));
```
---

## Returning a `std::thread` Object

- The compiler will automatically move it for us
```c++
// Function returning a std::thread object
std::thread func() {
  // Return a local variable
  std::thread thr(…);
  return thr;
  
  // It is a bad idea to put a call to std::move() here,
  // because that may confuse the compiler
  // return std::move(thr);
  
  // Return a temp object
  return std::thread(…);
}

```
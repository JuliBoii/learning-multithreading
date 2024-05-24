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

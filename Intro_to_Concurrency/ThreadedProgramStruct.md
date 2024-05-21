# Threaded Program Structure

---

## Single-threaded C++ Program Structure

- Non-threaded C++ programs have a single thread
  - When this thread start, it executes the code in `main()`
  - `main()` is the entry point function for the thread
- `main()` can call other functions
  - These run in the `main` thread
- When `main()` returns, the thread ends
  - The program ends when the main thread ends

---

## Multi-threaded C++ Program Structure

- Multi-threaded C++ program also have a main thread
  - The main thread starts additional threads
  - These could, in turn, start further threads
- Each thread has its own entry point function
  - When the thread starts, it executes the code in this function
  - When teh function returns, the thread ends
  - The main thread continues to execute its own code
  - It does not wait for the other threads, unless we explicitly tell it to

---

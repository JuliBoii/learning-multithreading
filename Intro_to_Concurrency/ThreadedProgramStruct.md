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

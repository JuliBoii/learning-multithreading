# Launching a Thread

---

- We need to create an `std::thread` object
  - The class is defined in `<thread>`
- The constructor starts a new execution thread
  - This will execute immediately
- The parent thread will continue its own execution

---

## Thread Entry Point

- `std::thread's` constructor takes a callable object
  - The thread's entry point function
- The execution thread will invoke this function
- The entry point function:
  - Can be any callable object
  - Cannot be overloaded
  - Any return value is ignored

---

### "Hello, Thread" Program

_There is no reason as to why one would write the following, unless for an example, as in this case._
```c++
#include <thread>

// Callable object - thread entry point
void hello() {
  std::cout << "Hello, Thread\n";
}

// Create an std::thread object
// Pass the entry point function to the constructor
std::thread thr(hello);
```

---

### Thread Termination

- The parent thread completes its execution
  - The `std::thread` object goes out of scope
  - Its destructor is called
- This can happen while the child is still running
  - "Zombie" thread?
  - By default, the destructor, calls `std::terminate()`
  - This terminates all threads, including `main()`

---

### Join a Thread

- `std::thread` has a `join()` member function
- This is a "blocking" call
  - Does not return until the thread has completed execution
  - The parent has to stop and wait for the thread to complete
- Prevents `std::thread's` destructor calling `std::terminate()`
- This is known as "joining" the thread
  - The program can continue after the `std::thread` object is destroyed

---

## "Hello, Functor" Program

- We can use any callable object
- For example, an object of a "functor" class
  - Overloads the `()` operator
- Pass the object to `std::thread's` constructor
- The object's `()` operator will be the entry point function

---

### Functor as Entry Point

```c++
// Functor class with overloaded () operator
class Hello {
    public:
      void operator()() { std::cout << "Hello, Functor!\n"; }
};

// Creates an object of the functor class
Hello hello;

// Pass the onject to std::thread's constructor
std::thread thr(hello);

// Wait for the thread to complete
thr.join();
```

---

## Lambda Expression as Entry Point

- We can use a lambda expression
```c++
// Capture by reference
std::thread thr([]() { std::cout << "Hello, Lambda Thread!\n"; });
```

---

## Thread Function with Arguments

- We can pass arguments to the entry point function
- We list them as extra arguments to the constructor
```c++
// Thread entry point function
void hello(std::string);

// hello() takes a string argument
std::thread thr(hello, "Hello, Thread!\n");
```
- The `std::thread` object owns the arguments
  - lvalue arguments are passed by value
  - rvalue arguments are passed by move

--- 

## Thread Function with Pass by Move

- To pass by move, we must provide a rvalue
  - The argument must have a move constructor
```c++
// Callable object - thread entry point
void func(std::string&&);

std::string str = "abc";

// Wrap the argument in a call to std::move()
std::thread thr(func, std::move(str));
```

---

## Thread Function with Reference Argument

- Use a reference wrapper
  - Wrap the argument in a call to `std::ref()`
  ```c++
  // Callable object - thread entry point
  void hello(std::string&);
  
  std::string str = "abc";
  
  // Wrap the argument in a call to std::ref()
  std::thread thr(hello, std::ref(str)); 
  ```
- Use `std::cref()` for a const reference
- _**Beware of dangling references!**_

---

## Member Function as Entry Point

- We can use a member function as the entry point
- Requires an object of the class
```c++
// Class which has the member fucntion
class Greeter {
    public:
      void hello();
};

// An object of the class
Greeter greeter;

// Pass a pointer to the member function and a pointer to the object
std::thread thr(&greeter::hello, &greeter);
```

---
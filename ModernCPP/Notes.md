# Multithreading Course Notes

---

## Universal Initializers

- Initializer(s) within a pair of braces
  - Can be used with any type
    - examples
    ```c++
    int x{7};                              // Equivalent to int x = 7;
    std::string str{"Let us begin"};       // Equivalent to std::string str = "Let us begin";
    ```
- Narrowing conversions are not allowed
    ```c++
      int x = 7.7      // Legal, although compilers may warn
      int x{7.7};       // illegal
    ```
  
- It can be used with compound types
    ```c++
      std::vector<int>vec{4, 3, 2, 1, 7, 4};     // std::vector variable with elements
    ```

---

## `std::chrono` Durations

- Types which represent time intervals
  - Defined in `<chrono>`
  - in the `std::chrono` namespace

```c++
// Namespace alias to simplify the code
namespace sc = std::chrono;

sc::seconds             // 1 second
sc::milliseconds        // 1/1000 second
sc::microseconds        // 1/1000000 seconds

sc::seconds(2);             // 2 second interval
sc::milliseconds(20);       // 20 millisecond interval
sc::microseconds(50);       // 50 microsecond interval
```
---

### `std::chrono` literals

- C++14 provides literals for these time intervals in the `std::chrono::literals` namespace
- This is an inline namespace

```c++
using namespace std::literals;

2s      // 2 second interval
20ms    // 20 milliseconds
50us    // 50 microseconds
```

---

## The `auto` Type Specifier

- The compiler deduces the type from the initializer
```c++
auto x = 6;     // Equivalent to int x = 6;
auto x{6};      // Equivalent to int x{6};
```

- This is very useful with complicated types
```c++
std::vector<std::string>vec;

// Equivalent to std::vector<std::string>::iterator it = vec.begin();
auto it = vec.begin();
```

- In modern C++, there are some cases where the type cannot be known by the programmer.
  - In those cases, it is best to use `auto`

---

### `auto` Specifier and Qualifiers

- `auto` will only give the underlying type
```c++
auto x = 6;     // x deduced as non-const
```

- Meaning it will ignore:
  - const, reference, etc.
```c++
const std::string& str = "Hello";   // Refernce to const
...
auto hello str;     // hello has type std::string
                    // it is a mutable copy of str
```

- if we need them, we must add them ourselves
```c++
const auto& str = hello;     // hello is a const reference to std::string
```

---

### `auto` Specifier and `for` loops

- We can use `auto` to simplify loops
```c++
std::vector<int> vec;
...
for (auto it = vec.begin(); it != vec.end(); ++it) {
  std::cout << *it << ",";      // Prints out each element
}

for (auto it = vec.begin(); it != vec.end(); ++it) {
  *it +=2;      // Add 2 to each element of vec
} 
```

---

### Range for loops

- Special syntax for iterating over containers
```c++
for (auto i : vec) {
  std::cout << i << ", ";       // Prints out each element of v
}

// We need to use a reference to modify the elements
for (auto& i : vec) { i += 2; } // Add 2 to each element of v
```

- To visit each element once, in order, without adding or removing elements
- Otherwise, use a traditional loop

---

## Lambda Expression

- Similar to "closures" in other languages
- Can be thought of as "local functions"
  - Anonymous functions
  - Defined inline in a single statement
- Ideal for short, simple helper functions which are only used once
- Useful for passing a function arguments
  - More convenient than functors or function pointers
- Can also be returned by functions
- Very useful as predicates for algorithm calls

---

### Lambda Expression Syntax

- Similar to functions
- Put `[]` instead of the function name
- Write the arguments in the usual way
- Write its body inline
  - The semicolon at the end of the lambda expression is necessary
    ```c++
    [](int arg) { return 2 * arg; };
    ```

---

### Return Type

- Deduced by the compiler in C++14
  - The return type must be the same in all paths
  - In C++17, can differ
    - It has been relaxed
    - For example:
      - You can have a branch which returns `int`
      - And a branch which returns `string`.
- In C++11, deduced for a single statement which returns a value
  ```c++
    [](int arg) { return 2 * arg; };
  ```
- Otherwise, must be specified with a trailing return type
  ```c++
    [](int arg)->int { return 2 * arg; return arg; };
  ```
  
---

### Callable Object

- A lambda expression is a callable object
- To invoke it, put () after the body, with any arguments
```c++
// Invoke the lambda with argument 3
[](int arg) { return 2 * arg; }(3);
```

- It can be stored in a variable of type `auto`
  - Since it is a class that is defined by the compiler
```c++
// Store the lambda in a variable
// The compiler will provide the type (not know to us)
auto lam = [](int arg){ return 2 * arg; };
```

---

## Capture

- A lambda expression can "capture" a local variable
  - Makes it available in the lambda's body
  - put the name of the variable(s) inside the `[]`
  - The lambda body contains an immutable copy of the local variable
  ```c++
    int n = 2;
  
    // Captures the local variable n
    [n] (int arg) { return(n * arg); };
  ```

---

### Capture by Reference

- The lambda can change a captured variable
- Put `&` before the variable's name
  ```c++
    int n = 2;
  
    // Captures the local variable n by reference
    [&n] (int arg) { return(++n * arg); };
  ```
  - Now it will be able to modify `n`.

---

### Implicit Capture

- Captures all variables in scope
  - `[=]` captures all variables by value
  - `[&]` captures all variables by reference
    - _This can be a bit dangerous, since we can modify anything by accident_
- We can be more selective
  - `[=, &x]` captures `x` by reference, all others by value
  - `[&, =a, =b]` captures `a` and `b` by value, all others by reference

---

### Lambda Expressions in Member Functions 
#### _Working with Classes_

- To access the data members, capture `this`
```c++
[this]() { return m_data % 2; };    // Captures all data memebers
```

- The object is captured as a reference to `*this`
- The lambda expression is able to modify data members
```c++
[this](int arg) { return(++m_data * arg); };
```

---

### Lambda Expression Example

```c++
// Call count_if() algorithm using a lmabda expression as predicate
auto n_even = std::count_if(vec.begin(), vec.end());

// THe lambda definition goes inside the call!
[](int n) {
  return (n % 2 == 0);
};
```

---

## Move Semantics

- C++11 optimization for copying objects
  - In some cases, the data can be moved into the target
  - Similar to moving files between folders
  - Ex. `mv /some/path other/path`
- This is an important optimization, since C++ copies by default
- Also, if you store data in a C++ standard container
  - that will also be copied

---

### The Solution

- Consider how it could be executed more efficiently
```c++
std::vector<std::string> vec(1000000);  // Vector of 1 million strings
...                                     // Populate vec
func(vec);          // Move vec's data into the function argument
..                  // vec is not used again
```

- When `func()` is called:
  - No memory is allocated
  - The elements are moved from `vec` into the function argument
  - After the function call, `vec` is an empty vector

---

### Some Terminology
#### lvalue and rvalue before C++

- A value can either be a lvalue or a rvalue
- A lvalue may appear on the left of an assignment
- A rvalue can only appear on the right
```c++
x = 2;      // x is an lvalue, 2 is an rvalue
2 = x;      // Not legal C

x = func(); // x is an lvalue, func() is an rvalue
func() = x; // Not legal C, but can be legal C++
```

---

#### lvalue and rvalue in C++

- In C++, a lvalue represents a named memory location
  - It has a name
  - We can take its address using the `&` operator
  - `x` is an lvalue   `// name is x, &x is legal`
- Anything else is a rvalue
  - `2` is an rvalue    `// 2 has no name, &2 is not legal`
  - `func()` is an rvalue    `// return value form function call has no name`
  - `// &func() is not legal`

---

### The Solution?

- Make `func()'s` argument an rvalue reference
```c++
void func(std::vector<std::string>&& arg);

std::vector<std::string> vec(1000000);  // Vector of 1 million strings
func(vec);  // Does not compile
```

- A lvalue cannot be moved

---

### `std::move`

- `std::move()` will cast its argument to rvalue
```c++
// Casts vec to an rvalue
func(std::move(vec));
```

- This will move `vec's` data into the function argument
- This should only be done if `vec's` data is expendable
  - After calling `func()`, `vec's` data may be empty or unusable
  - If we want to use `vec` again, we must re-assign its data
- When we use `std::move()` our variable no longer owns the data
  - When the function returns, the data may be gone or the variable may not be in a usable state.
    - May even be in a usable state on some compilers, but not others
- So the only sensible thing to do is either
  - to wait and allow that variable to be destroyed
- If one wants to use the data, then
  - one can do that provided one reassign it or reinitialize it.

---

## Rvalue References and Overloading

- Function can be overloaded on the value type
  - Different behavior for lvalue and rvalue
  ```c++
    void func(const Test& test);        // Called when we pass an lvalue
    void func(Test&& test);             // Called when we pass an rvalue
  ```
  
- Usually, the lvalue version will be called
  - When we pass a variable
- The rvalue overload will be called
  - If we pass a literal or a temporary object
  - If we use `std::move()` to cast a variable

---

### Move Semantics and Ownership

- Consider these overloads
  ```c++
    void func(const Test& test);        // Called when we pass an lvalue
    void func(Test&& test);             // Called when we pass an rvalue
  ```
  
- lvalue argument
  - Refers to an object outside `func()`
  - The function can inspect this object
  - It can make its own copy of the object
- rvalue arguments
  - Not owned by any variable
  - Or the variable has lost ownership after a call to `std::move()`
  - The "test" object becomes the owner

---

### Move Operators

- C++11 has two new special member functions
  - The arguments are rvalue references
- Overload of the copy constructor
```c++
// Move constructor
Test(Test&& other) noexcept;
```
- Overload of the assignment operator
```c++
// Move assignment operator
Test& operator = (Test&& other) noexcept;
```
- These operators are called during move operations
  - Any object is only moveable if the class defines move operators

---

### Move-only Types

- Some types can be moved, but not copied
  - `std::fstream`, `std::iostream`
  - `std::unique_ptr`
  - (Classes used in multi-threading)
- These types follow th RAII idiom
  - Only one object can own a given resource instance at a time
  - The object acquires ownership in the constructor
  - The object releases ownership in the destructor
  - The resource instance can be moved from one object to another

---

#### `std::fstream`

- `std::fstream` has a file handle as a data member
  - The constructor opens the file
  - The destructor closes the file
- A `std::fstream` object cannot be copied, but it can be moved
  - A moved-from object no longer owns the file handle
  - The moved-to object becomes the owner of the file handle
  - The file will be closed when the moved-to object is destroyed

---

### Delete and Defaulted Operators

- In C++11, special member functions can be deleted
```c++
Test(const Test& other) = delete;   // Deleted copy constructor
```
- This prevents an object from being copied
  - The function is defined, but cannot be called
- Special member functions can also be defaulted
```c++
Test(const Test& other) = default;      // Default copy constructor
```
- This causes the compiler to generate a default member function
  - e.g. The default copy constructor copies all the class members

---

### Pass by Value... or by Move?

- In older C++, the argument is always copied by default
```c++
// This fucntion makes its own copy of test
void func(Test test);
```
- In C++11, the argument can be moved if
  - It is an rvalue
  - And the type defines move operators
- Otherwise it will be copied
  - Provides compatibility with old code
- All STL containers are moveable
  - And almost all other C++ library types
  - Built-in types are regarded as moveable (but are always copied)

---

## Lambda-local Variables

- Variables which are local to the lambda body
- Declared in the capture specifier
  - Implicitly `auto`
  - Must be initialized
- Requires C++14
```c++
// y is local to the lambda body
[y = 2](int x) {
  return x+y;
};
```
- Can be initialized from captured variables
- No special syntax is needed
```c++
// Local variable z in this scope
int z = 1;

// Lambda body's local varibale y
[y = z + 1](int x) {
    return x + y;
};
```

---

### Lambda-local Variable and Capture by Move

- Lambda-local variable can be move initialized
```c++
std::vector<std::string>strings(5);

// Lambda expression which captures "strings"
// by moving it into "vec_strings"
[vec_strings = std::move(strings)] {
  ...
}
```
- This allows capture by move
  - the type of `vec_strings` is deduced as `std::vector<std::string>`
  - `std::vector's` move constructor is called to initialize `vec_strings`
  - The vector elements are now owned by `vec_strings`
# Data Race Consequences

---

## Incorrect Results

```c++
int x = 5;      // Shared variable x

int y = 2*x + 3;    // Calculate the value of y(1)
int z = 3*x + 2;    // Calculate the value of z(1)
```
- Thread A evaluates `y`
  - Thread B interleaves and changes the value of `x` to 6
  - Thread A uses the new value of `x` to evaluate `z`
  - The calculated values of `y` and `z` are inconsistent
- This can even occur inside a statement
```c++
y = x*x + 2*x + 1;      // Another thread could change the value of x
```

---

## Incorrect Program Flow

```c++
int x = 3;

if (x > 0) {            // Test whether it is safe to use x(1)
    z = sqrt(x);        // Use x(2)
    ...
}
```
- Thread A checks that `x > 0`
  - Thread B interleaves and changes the value of `x` to a negative number
  - Thread A uses the new, negative value of `x`
  - A runtime error occurs which "shouldn't be possible"

```c++
if (x > 0 && x < 10) {      // Check x is within bounds x(1)
    switch(x) {             // Use x(2)
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        ...
        case 9:
            func9();
            break;
    }
}
```
- The compiler may optimize this as a branch table
  - An array of function pointers
  - `table[1]` holds the address of `func1()`
  - ...
  - `table[9]` holds the address of `func9()`
  - When `x == 1`, the program executes the code in `table[1]`
- Thread A checks that `x` is within bounds
- Thread B interleaves and sets `x` to 10
- Thread A executes the code at `table[10]`
  - Arbitrary code!

---

## Torn Writes and Reads

- A "torn" write
  - Can occur when writing data requires multiple operations
  - Another writing thread interleaves between the write operations
- Ex.
```text
Thread A and B write to a memory location     ->      0x????

Thread A starts writing 0x1234                ->      0x12??

Thread B interleaves and writes 0x4567        ->      0x4567

Thread A continues to writing 0x1234          ->      0x4534

The memory location contains part of          ->      0x4534
Thread A's number and part of Thread B's
number
```
- A "torn" read
  - Can occur when reading and writing data requires multiple operations
  - A writing thread interleaves between the read operations
```text
Thread A reads from a memory location           ->      0x4321

Thread A starts reading 0x4321                  ->      0x4321

Thread B interleaves and writes 0x9876          ->      0x9876

Thread A continues reading                      ->      0x9876

Thread A has read 0x4376                        ->      0x4376

Thread A has read part of the original
value and part of the new value
```

---

## Improper Construction

- Thread A creates a shared object
  - It calls the class's constructor
- Thread B interleaves
  - Thread B also calls the class's constructor, at the same memory location
- We have a torn write
  - The object will be initialized with a mixture of values from each thread

- Partially constructed object
```c++
// Vector of polymorphic objects
std::vector<Base *> vec;

// The Base constructor adds the object to the vector
Base::Base() {
    vec.push_back(this);
}

// The Derived constructor calls the Base constructor first
// Then it initialzes the Derived member
Derived::Derived() : Base(), ...
```
- Thread A calls Derived's constructor
  - Derived's constructor calls Base's constructor
  - Base's constructor pushes the Base part of the object onto the vector
- Thread B interleaves
  - Thread B accesses the element in `vec`
  - The Derived constructor has not completed
  - Thread B will see a partially constructed object
- Thread A initializes the Derived part of the object

---

## Improper Destruction

- Destructor of reference-counted object
```c++
*ref_count--;           // (1)
if (*ref_count == 0) {  // (2)
    delete p;
    delete ref_count;
}
```
- Thread A decrements the counter
  - Thread B interleaves and decrements the counter
  - Thread A checks the counter and may release the members
  - Thread B checks the counter and may release the members
- If `ref_count` was initially 2
  - `p` and `ref_count` could be deleted twice
- If `ref_count` was initially 1
  - `p` and `ref_count` may not be deleted at all

---

## Managing Data Races

- There are no "benign" data races
  - All data races in C++ are potentially dangerous
- Can be very difficult to detect and replicate
  - Intermittent errors
  - Sensitive to environments
  - Often dependant on timing coincidences or system load
- The only good solution is to prevent data races from occurring

---

## Shared Data

- Avoid sharing data between different threads
- If unavoidable, synchronize the threads
  - Impose an ordering on how the threads access the shared data
- This has substantial costs
  - Increased execution time
    - Running in sequence, not concurrently
  - Increased program complexity

---

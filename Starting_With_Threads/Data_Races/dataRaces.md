# Data Races

---

## **_Data Race_**

- Two or more threads access the same memory location
  - And at least one of the threads modifies it
  - And the threads are not synchronized when they access the memory location

---

## Output

- The output will be scrambled up, like so:
  - Looking at `coutDataRaces.cpp` in this case
```c++
axyzbc

abc
abc
abc
abc
dxyz
xyz
xyz
xyz
ef
def
def
def
def
```
- What has gone wrong?
  - Threads can be interrupted during output
  - Other threads can run and write their output
  - The output from different threads is interleaved

---

## Data Race Consequences

- In this program, the data race caused interleaved output
  - `std::cout` is a special case
  - Nothing worse than output interleaving can happen
- The consequence of a data race can be much more serious
  - Incorrect Results
  - Incorrect Program Flow
    - Program logic does not follow the behavior it should
  - "Torn" writes and reads
  - Objects which are improperly constructed or destroyed

---
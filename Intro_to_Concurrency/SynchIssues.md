# Synchronization Issues

- Different threads execute on different cores
- They may share data
- This can cause synchronization issues

---

## Example

- Core 1's thread modifies the shared data
- Core 1 writes the new value to its store buffer
- Core 2's thread wants to use the shared data
- Core 2 pre-fetches the shared data, or loads it from cache
- Core 2 gets the old value
- Core 2's thread does its computation, using the old value
- Core 1's store buffer writes the new value to cache

---

## Solution?

- Core 1's thread modifies the shared data
- Core 1 writes the new value to its store buffer
- Core 1's store buffer writes the new value to cache
- Core 2's thread wants to use the shared data
- Core 2 pre-fetches the shared data, or loads it from cache
- Core 2 gets the old value
- Core 2's thread does its computation, using the old value

---

# Reference Manager

## Summary

This program implements a reference manager that simulates pointer assignment and garbage collection for strings. It allows users to create, assign, and query pointers to strings, as well as perform garbage collection to free unused strings. The program manages reference counts for each string and ensures that memory is properly freed when no pointers reference a string.

## Problem Description

- The program maintains an array of up to 100 pointers to strings.
- Users can:
  - Create a new string and assign it to a pointer.
  - Reassign pointers to reference other strings.
  - Query the string referenced by a pointer.
  - Trigger garbage collection to free strings with zero references.
  - Exit the program, which triggers cleanup of all remaining strings.

## Assumptions

- Pointer indices must be between 0 and 99.
- All input queries follow the specified format.
- Strings must be exactly the specified length and contain no spaces.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./we3_solution
   ```

3. Use the following commands as input:
   - `c p n str` — Create a string of length `n` and assign it to pointer `p`.
   - `s p1 p2` — Set pointer `p1` to reference what `p2` references.
   - `q p` — Print the string referenced by pointer `p` or `NULL` if none.
   - `g` — Run garbage collection.
   - `e` — Exit the program and clean up all memory.

## Example

**Input:**
```
c 0 3 abc
c 1 3 def
s 0 1
q 0
g
e
```

**Output:**
```
def
abc
def
```
# Dynamic Hashing

## Summary

This program implements a dynamic hash table that supports insertion, removal, and lookup of unsigned integers. The hash table automatically resizes: it doubles the number of buckets when the number of elements exceeds the number of buckets, and halves the number of buckets (down to a minimum of 10) when the number of elements drops below one quarter of the number of buckets. The implementation uses separate chaining with linked lists to handle collisions.

## Problem Description

- The hash table supports the following operations:
  - Insert an unsigned integer if it is not already present.
  - Remove an unsigned integer if it is present.
  - Query whether an unsigned integer is present.
  - Report the current number of elements.
  - Report the current number of buckets.
  - All operations are performed via a command-line interface.

## Assumptions

- The initial number of buckets is provided by the user and must be greater than 0.
- The table resizes dynamically as described above.
- All queries must follow the specified format.
- Input is well-formed and follows the specified format.
- There is no time bound for this problem.

## How to Run

1. Compile and link the program using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./we4_solution
   ```

3. Use the following commands as input:
   - `I e` — Insert unsigned integer `e` into the table (if not present).
   - `R e` — Remove unsigned integer `e` from the table (must be present).
   - `Q e` — Query whether unsigned integer `e` is in the table.
   - `B` — Output the current number of buckets.
   - `S` — Output the current number of elements.
   - `STOP` — Terminate the program.

4. To clean up object files and the executable, run:
   ```
   make clean
   ```

## Example

**Input:**
```
10
I 5
I 7
Q 5
R 5
Q 5
B
S
STOP
```

**Output:**
```
found
not found
number of buckets: 10
number of elements: 1
```
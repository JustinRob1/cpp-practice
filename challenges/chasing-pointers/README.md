# Chasing Pointers

## Summary

Given a starting index and an array of integers, the program repeatedly follows the value at the current index as the next index to visit. The process continues until it either encounters a negative value (which is printed as output) or detects a cycle (in which case it prints "There was a cycle").

## Problem Description

- Input:
  - The first line contains two integers, `S` (the starting index) and `A` (the length of the array).
  - The next line contains `A` integers, representing the array.
- Process:
  - Start at index `S`.
  - At each step, use the value at the current index as the next index.
  - If a negative value is encountered, print it and stop.
  - If a cycle is detected (an index is visited more than once), print "There was a cycle" and stop.

## Assumptions

- 0 ≤ S < A
- The array contains at least one element.
- The input is well-formed and follows the specified format.
- Array indices are zero-based.

## How to Run

1. Compile the program using g++:
   ```
   g++ chasing.cpp -o chasing -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./chasing
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
2 5
1 3 4 -1 2
```

**Output:**
```
-1
```
# Spread

## Summary

Given a list of integers, the program computes the difference between the largest and smallest values in the list (the spread).

## Problem Description

- Input:
  - The first line contains an integer `n`, the number of elements in the list.
  - The next line contains `n` integers.
- Output:
  - A single integer representing the difference between the maximum and minimum values in the list.

## Assumptions

- 1 ≤ n ≤ 1,000
- Each integer is in the range [0, 1,000,000,000].
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ spread.cpp -o spread -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./spread
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5
3 8 1 9 4
```

**Output:**
```
8
```
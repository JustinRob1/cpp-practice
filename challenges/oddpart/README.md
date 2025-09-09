# Odd Part

## Summary

Given a positive integer `n`, the program computes the largest odd divisor of `n` by repeatedly dividing `n` by 2 until the result is odd.

## Problem Description

- Input:
  - A single positive integer `n`.
- Output:
  - A single integer representing the largest odd divisor of `n`.

## Assumptions

- 1 ≤ n ≤ 2,147,483,647 (fits in a 32-bit unsigned integer)
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ oddpart.cpp -o oddpart -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./oddpart
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
12
```

**Output:**
```
3
```
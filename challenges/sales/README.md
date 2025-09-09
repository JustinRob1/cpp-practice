# Sales

## Summary

Given a sorted list of item prices and a target price `T`, the program determines whether there exists a pair of distinct items whose prices sum to exactly `T`. It outputs "YES" if such a pair exists, and "NO" otherwise.

## Problem Description

- Input:
  - The first line contains two integers, `n` (the number of items) and `T` (the target price).
  - The next line contains `n` integers in strictly increasing order, representing the prices of the items.
- Output:
  - A single line: "YES" if there exists a pair of distinct items whose prices sum to `T`, otherwise "NO".

## Assumptions

- 2 ≤ n ≤ 250,000
- 0 ≤ T ≤ 2 × 10⁹
- 0 ≤ p₁ < p₂ < ... < pₙ ≤ 10⁹
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ sales.cpp -o sales -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./sales
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5 10
1 2 4 6 9
```

**Output:**
```
YES
```
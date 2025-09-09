# Call Centre

## Summary

Given the number of calls received by a call centre over `n` consecutive days. You are then required to answer `q` queries, each asking for the total number of calls received between two given days (inclusive).

## Problem Description

- Input:
  - The first line contains two integers, `n` (number of days) and `q` (number of queries).
  - The next line contains `n` integers, where the `i`-th integer represents the number of calls received on day `i`.
  - The following `q` lines each contain two integers, `a` and `b`, representing a query for the total number of calls from day `a` to day `b` (1-based indices).

- Output:
  - For each query, output the sum of calls received from day `a` to day `b`, inclusive, on a new line.

## Assumptions

- 1 ≤ n, q ≤ 100,000
- 1 ≤ a ≤ b ≤ n
- The number of calls per day is a non-negative integer.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ callcentre.cpp -o callcentre -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./callcentre
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5 3
2 4 6 8 10
1 3
2 5
4 4
```

**Output:**
```
12
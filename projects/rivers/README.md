# Rivers

## Summary
Given a set of rivers where each river may connect to another river (or the ocean), and a series of queries, the program determines the largest river that two given rivers both connect to (their lowest common ancestor in the river system).

## Problem Description

- Input:
  - The first line contains two integers, `n` (the number of rivers) and `q` (the number of queries).
  - The next line contains `n` space-separated integers indexed from 1 to n, where each integer `a_j` (0 ≤ a_j ≤ j−1) indicates that river `j` connects to river `a_j` (with river 0 being the ocean).
  - The following `q` lines each contain two integers `u` and `v` (0 ≤ u, v ≤ n), representing a query for the river where rivers `u` and `v` connect.

- Output:
  - For each query, output a single integer `k` representing the river where rivers `u` and `v` connect.

## Assumptions

- 1 ≤ n ≤ 100,000
- 1 ≤ q ≤ 1,000
- The first river in all inputs is 0 (the ocean).
- No river connects to a river with a higher index than itself.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ rivers.cpp -o rivers -Wall -std=c++11 -g
   ```

2. Run the executable:
   ```
   ./rivers
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5 2
0 1 2 2 3
4 5
2 3
```

**Output:**
```
2
2
```
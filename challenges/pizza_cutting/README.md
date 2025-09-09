# Pizza Cutting

## Summary

Given two integers `n` and `m`, the program determines whether it is possible to cut a pizza into exactly `m` slices using only cuts that always divide the pizza into `n` equal pieces at each step. The output is "GOOD" if it is possible, and "BAD" otherwise.

## Problem Description

- Input:
  - The first line contains two integers, `n` and `m`.
- Output:
  - Print "GOOD" if it is possible to cut the pizza into exactly `m` slices using the described method, otherwise print "BAD".

## Assumptions

- 1 ≤ n, m ≤ 2,147,483,647 (both fit in a 32-bit unsigned integer)
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ pizza_cutting.cpp -o pizza_cutting -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./pizza_cutting
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
2 8
```

**Output:**
```
GOOD
```
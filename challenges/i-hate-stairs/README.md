# I Hate Stairs

## Summary

Given a sequence of floor numbers, the program calculates the total number of stairs climbed, counting only the increases in floor numbers as you move through the sequence. For each step to a higher floor, the difference is added to the total; steps to the same or lower floor are ignored.

## Problem Description

- Input:
  - The first line contains an integer `n`, the number of floors visited.
  - The next line contains `n` integers, representing the sequence of floor numbers visited in order.
- Output:
  - A single integer representing the total number of stairs climbed (sum of all increases between consecutive floors).

## Assumptions

- 1 ≤ n ≤ 100,000
- Floor numbers are integers.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ increase.cpp -o increase -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./increase
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5
1 2 2 4 3
```

**Output:**
```
3
```
# Mountain Climbing

## Summary

Given the heights of ledges on a mountain, the required rest time between climbing bursts, and a time limit to reach the top, the program determines the minimum burst value (maximum distance that can be climbed in one go) needed to reach the highest ledge within the given time limit.

## Problem Description

- Input:
  - The first line contains three space-separated positive integers: `length` (number of ledges), `rest` (seconds to rest between bursts), and `limit` (total seconds allowed to climb).
  - The second line contains `length` space-separated positive integers representing the heights of the ledges.
- Output:
  - A single integer representing the minimum burst value required to reach the highest ledge within the time limit.

## Assumptions

- `limit` is guaranteed to be at least the last height in the array.
- You must rest the same amount of time even if your latest climb was not for the full burst.
- The time complexity of the program is O(length * log(limit)).
- Input is well-formed and follows the specified format.

## How to Run

1. Compile and link the programs using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./we7_solution
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5 2 20
1 3 6 10 15
```

**Output:**
```
6
```
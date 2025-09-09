# Planning Practice

## Summary

Given a set of available time intervals within a 24-hour day and a required total number of hours `t`, the program determines the minimum number of days needed to accumulate at least `t` hours, using only the overlapping portion of all provided intervals each day. If it is impossible to schedule any hours (i.e., the intervals do not overlap), the program outputs "IMPOSSIBLE".

## Problem Description

- Input:
  - The first line contains two integers, `n` (the number of intervals) and `t` (the total required hours).
  - The next `2n` integers represent the start and end times of each interval (in hours, within 0 to 24).
- Output:
  - The minimum number of days required to accumulate at least `t` hours, or "IMPOSSIBLE" if it cannot be done.

## Assumptions

- 1 ≤ n ≤ 12
- 1 ≤ t ≤ 10,000
- 0 ≤ interval start < interval end ≤ 24
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ planning_practice.cpp -o planning_practice -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./planning_practice
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
2 5
9 17 10 15
```

**Output:**
```
1
```
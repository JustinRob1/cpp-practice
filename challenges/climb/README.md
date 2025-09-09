# Climb

## Summary

Given a sequence of waypoints representing elevations, the program determines, for each waypoint, the length of the longest strictly increasing sequence starting at that point. The output is a list where each entry indicates how many consecutive waypoints (including the current one) can be visited by always moving to a higher elevation.

## Problem Description

- Input:
  - The first line contains an integer `n`, the number of waypoints.
  - The next line contains `n` integers, representing the elevations of the waypoints in order.
- Output:
  - A single line with `n` integers, where the `i`-th integer is the length of the longest strictly increasing sequence starting at waypoint `i`.

## Assumptions

- 1 ≤ n ≤ 100,000
- Elevations are integers.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ climb.cpp -o climb -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./climb
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
5
1 2 3 2 4
```

**Output:**
```
2 1 0 1
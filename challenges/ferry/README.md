# Ferry

## Summary

Given two lists of times when cars arrive at the west and east banks of a river, the program simulates a ferry that transports cars across the river. The ferry starts on the west bank and can carry one car at a time. Crossing from west to east takes 100 seconds, and from east to west takes 100 seconds. The goal is to determine the minimum total time required to transport all cars across the river, given their arrival times.

## Problem Description

- Input:
  - The first line contains two integers, `n` and `m`, the number of cars arriving at the west and east banks, respectively.
  - The next `n` lines contain the arrival times of cars at the west bank.
  - The following `m` lines contain the arrival times of cars at the east bank.
- Output:
  - A single integer representing the minimum total time required to transport all cars across the river.

## Assumptions

- 0 ≤ n, m ≤ 100,000
- Arrival times are non-negative integers and are given in non-decreasing order.
- The ferry starts on the west bank.
- The ferry can carry only one car at a time.
- Crossing the river in either direction takes 100 seconds.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ ferry.cpp -o ferry -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./ferry
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
2 2
0 200
100 300
```

**Output:**
```
600
```
# Leap

## Summary

Given a year as input, the program determines whether it is a leap year according to the Gregorian calendar rules. A year is a leap year if it is divisible by 4 but not by 100, or if it is divisible by 400.

## Problem Description

- Input:
  - A single integer representing the year.
- Output:
  - Print "yes" if the year is a leap year, otherwise print "no".

## Assumptions

- The input year is a positive integer.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ leap.cpp -o leap -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./leap
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
2000
```

**Output:**
```
yes
```
# Multiply

## Summary

Given two large numbers represented as arrays of their digits (in reverse order), the program multiplies them and outputs the product as an array of digits (also in reverse order). This approach allows multiplication of numbers that may not fit into standard integer types.

## Problem Description

- Input:
  - The first line contains two integers, `m` and `n`, the number of digits in the first and second numbers, respectively.
  - The next `m` integers represent the digits of the first number, from least significant to most significant.
  - The following `n` integers represent the digits of the second number, from least significant to most significant.
- Output:
  - A single line with `m + n` integers, representing the digits of the product, from least significant to most significant.

## Assumptions

- 1 ≤ m, n ≤ 100,000
- Digits are provided in reverse order (least significant digit first).
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ multiply.cpp -o multiply -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./multiply
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
3 2
3 4 2
4 6
```

**Output:**
```
2 0 3 1 1
```
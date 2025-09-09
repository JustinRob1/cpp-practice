# Idols

## Summary

Given an array of positive integers, the program identifies all "idols" (elements that are greater than all elements to their right). It then reverses the groups of elements between each pair of idols and outputs both the list of idols and the modified array.

## Problem Description

- Input:
  - The first line contains a single integer `n` (1 ≤ n ≤ 100,000), the length of the array.
  - The second line contains `n` space-separated positive integers, each no greater than 1,000,000.
- Output:
  - The first line contains all idols in the order they appear in the initial array.
  - The second line contains the space-separated representation of the array after all groups between idols have been reversed.

## Assumptions

- Input is well-formed and follows the specified format.
- The function `reverse(int* begin, int* end)` reverses all entries between the pointers, including the entry pointed to by `begin` but not by `end`.

## How to Run

1. Compile the program using g++:
   ```
   g++ idols.cpp -o idols -Wall -std=c++11 -g
   ```

2. Run the executable:
   ```
   ./idols
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
7
2 3 9 5 4 7 1
```

**Output:**
```
9 7 1
3 2 9 4 5 7 1
```
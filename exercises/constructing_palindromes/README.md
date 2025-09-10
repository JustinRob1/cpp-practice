# Constructing Palindromes

## Summary

Given a string of lowercase letters, the program determines the length of the longest palindrome that can be constructed using the letters of the string. It does this by counting the frequency of each character and calculating the maximum possible palindrome length.

## Problem Description

- Input:
  - The first line contains an integer `n`, the length of the string.
  - The second line contains a string `s` of length `n`, consisting of lowercase English letters.
- Output:
  - A single integer representing the length of the longest palindrome that can be constructed from the letters of `s`.

## Assumptions

- 1 ≤ n ≤ 100,000
- The string contains only lowercase English letters (`a`-`z`).
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ constructing_palindromes.cpp -o constructing_palindromes -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./constructing_palindromes
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
7
abccccd
```

**Output:**
```
5
```
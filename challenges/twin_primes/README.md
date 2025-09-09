# Twin Primes

## Summary

This program solves the "Twin Primes" problem. It provides two functionalities: checking if a given number is prime, and printing the first `k` twin prime pairs. A twin prime pair consists of two prime numbers that differ by 2 (i.e., pairs of the form (p, p + 2)).

## Problem Description

- Input:
  - The first input is a character: `'p'` to check for primality, or `'t'` to print twin primes.
  - The second input is an integer:
    - If the first input is `'p'`, the integer `n` is the number to check for primality.
    - If the first input is `'t'`, the integer `k` is the number of twin prime pairs to print.
- Output:
  - If the input is `'p n'`, output `"prime"` if `n` is prime, otherwise `"not prime"`.
  - If the input is `'t k'`, output the first `k` twin prime pairs, one pair per line.

## Assumptions

- 0 ≤ n ≤ 100,000 for primality checking.
- 1 ≤ k ≤ 1,000 for twin prime pairs.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ twin_primes.cpp -o twin_primes -std=c++11 -Wall -g
   ```

2. Run the executable:
   ```
   ./twin_primes
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
p 7
```

**Output:**
```
prime
```

**Input:**
```
t 3
```

**Output:**
```
3 5
5 7
11 13
```
# Makefile Dependencies

## Summary

Given a list of targets and their dependencies (as in a Makefile), and a sequence of `make` commands, the program simulates the build process. For each `make` command, it determines which targets need to be built (recursively building dependencies as needed) and outputs the build order. If a target is already up to date, it reports that as well.

## Problem Description

- Input:
  - The first line contains two integers, `n` (number of targets) and `m` (number of make commands).
  - The next `n` lines each describe a target and its dependencies in the format:  
    `k <targetname>: <list of dependencies>`
    where `k` is the number of dependencies.
  - The following `m` lines each contain a make command:  
    `make <targetname>`
- Output:
  - For each make command, output the build order of targets (space-separated, ending with the requested target), or a message that the target is up to date if it was already built.

## Assumptions

- 1 ≤ n, m ≤ 20,000
- The sum of all dependencies is at most 200,000.
- All file names are unique, contain no spaces, and have at most 12 characters.
- No cycles exist in the dependency graph.
- No file is named "make".
- Input is well-formed and follows the specified format.

## How to Run

1. Compile the program using g++:
   ```
   g++ makefile_dependencies.cpp -o makefile_dependencies -Wall -std=c++11 -g
   ```

2. Run the executable:
   ```
   ./makefile_dependencies
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
3 2
2 foo: bar baz
1 bar: qux
0 baz:
make foo
make foo
```

**Output:**
```
qux bar baz foo
make: `foo' is up to date.
```
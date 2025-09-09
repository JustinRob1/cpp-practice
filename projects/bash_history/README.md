# Bash History

## Summary

Given a sequence of simulated shell commands (`cd <directoryname>`, `cd ..`, and `ls <filename>`), the program tracks directory navigation and file listings, then outputs the contents of each unique directory in lexicographic order, with files in each directory also listed in lexicographic order.

## Problem Description

- Input:
  - The first line contains an integer `n` (1 ≤ n ≤ 100,000), the number of commands.
  - The next `n` lines each contain one of the following commands:
    - `cd <directoryname>`
    - `cd ..`
    - `ls <filename>`
- Output:
  - For each unique directory, output a line in the format:  
    `<pathname> <filename 1> <filename 2> ... <filename k>`  
    where `<pathname>` is the full path from the root, and files are listed in lexicographic order.  
    The lines appear in lexicographic order of the full pathname.

## Assumptions

- The command `cd ..` will not appear when in the root directory.
- File and directory names are unique within a given directory.
- File and directory names consist of 1–10 alphanumeric characters, with no spaces.
- Input is well-formed and follows the specified format.
- There is no specific running time bound for the program.

## How to Run

1. Compile the program using g++:
   ```
   g++ bash_history.cpp -o bash_history -Wall -std=c++11 -g
   ```

2. Run the executable:
   ```
   ./bash_history
   ```

3. Provide input as specified in the problem description.

## Example

**Input:**
```
7
ls file1
cd dirA
ls file2
cd ..
cd dirB
ls file3
ls file4
```

**Output:**
```
/ file1
/dirA file2
/dirB file3 file4
```
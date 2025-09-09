# Matrix Class

## Summary

This program implements a Matrix class in C++ that supports dynamic creation and manipulation of matrices. The class provides constructors for initializing matrices with a constant value or from an array, supports deep copying, and includes overloaded operators for matrix addition, subtraction, multiplication, negation, transposition, element access, and input/output. The program also includes a driver that allows users to interactively create and manipulate matrices using a set of commands.

## Problem Description

- The Matrix class allows:
  - Creating a matrix with specified dimensions and initial value.
  - Creating a matrix from a flat array of values.
  - Copying matrices (deep copy).
  - Adding, subtracting, and multiplying matrices.
  - Negating and transposing matrices.
  - Accessing and modifying individual elements.
  - Printing and reading matrices from standard input/output.

- The driver program accepts commands to perform these operations interactively.

## Assumptions

- All matrices must have at least one row and one column.
- The user must follow the command format as described below.
- Matrix dimensions must be compatible for the requested operations.
- Input values for matrices must be valid floating-point numbers.
- Large matrices may result in long running times.

## How to Run

1. Compile and link the programs using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./we5_solution
   ```

3. Use the following commands as input:

   - `C mat_name rows columns (-c) -i init`  
     Create a new matrix with all elements set to `init`. Add `-c` for a const matrix.

   - `C mat_name rows columns (-c) -a init1 init2 ... init(rows×columns)`  
     Create a new matrix from an array of values. Add `-c` for a const matrix.

   - `A my_matrix1 my_matrix2 result`  
     Add two matrices and store the result.

   - `S my_matrix1 my_matrix2 result`  
     Subtract the second matrix from the first and store the result.

   - `M my_matrix1 my_matrix2 result`  
     Multiply two matrices and store the result.

   - `N my_matrix result`  
     Negate a matrix and store the result.

   - `T my_matrix result`  
     Transpose a matrix and store the result.

   - `B my_matrix row column`  
     Output a specific element of a matrix.

   - `BA my_matrix row column value`  
     Assign a value to a specific element of a matrix.

   - `P my_matrix`  
     Print a matrix.

   - `R my_matrix val1 val2 ... val(rows×columns)`  
     Read values into a matrix from standard input.

   - `D my_matrix new_matrix`  
     Create a new matrix as a copy of an existing matrix.

   - `Q`  
     Quit the program.

4. To clean up object files and the executable, run:
   ```
   make clean
   ```

## Example

**Input:**
```
C A 2 2 -i 1
C B 2 2 -i 2
A A B C
P C
Q
```

**Output:**
```
3 3
3 3
```
# Graph Concepts

## Summary

Given a description of a graph (as a list of vertices and edges), the program computes the number of connected components in the graph. The graph is represented using an adjacency list, and depth-first search (DFS) is used to explore and count the connected components.

## Problem Description

- Input:
  - Each line describes either a vertex or an edge:
    - Vertex: `V,ID,Lat,Lon`  
      `ID` is an integer vertex identifier, `Lat` and `Lon` are floating-point coordinates.
    - Edge: `E,start,end,name`  
      `start` and `end` are vertex IDs, and `name` is the street name (may contain spaces, no commas).
  - All vertices and edges are provided in a text file.

- Output:
  - A single integer representing the number of connected components in the graph.

## Assumptions

- Each vertex ID is unique.
- Every vertex ID used in an edge must have been defined previously.
- The input is well-formed and follows the specified format.
- The time complexity of counting components is O(V + E), where V is the number of vertices and E is the number of edges.

## How to Run

1. Compile and link the programs using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./we6_solution
   ```

3. Provide the input file using input redirection:
   ```
   ./we6_solution < input_file
   ```

   Where `input_file` contains the graph description.

4. To clean up object files and the executable, run:
   ```
   make clean
   ```

## Example

**Input (input_file):**
```
V,1,53.5,-113.5
V,2,53.6,-113.6
E,1,2,Main Street
```

**Output:**
```
1
```
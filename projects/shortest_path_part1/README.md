# Assignment Part 1: Shortest Path on Edmonton Road Network

## Summary

This project implements a server that computes the shortest path between two points on the Edmonton road network using Dijkstra's algorithm. The road network is represented as a weighted directed graph, where vertices correspond to intersections and edges correspond to road segments with weights equal to the Manhattan distance between intersections. The server reads requests specifying start and end coordinates, finds the corresponding vertices, computes the shortest path, and outputs the sequence of coordinates along the path.

## Problem Description

- The program reads the Edmonton road network from a file (`edmonton-roads-2.0.1.txt`) and builds a weighted directed graph.
- Each vertex represents an intersection, identified by an integer and associated with latitude and longitude.
- Each edge represents a road segment, weighted by the Manhattan distance between its endpoints.
- The server accepts requests of the form:
  ```
  R pt1_lat pt1_long pt2_lat pt2_long
  ```
  where `pt1_lat` and `pt1_long` are the latitude and longitude of the starting point, and `pt2_lat` and `pt2_long` are those of the ending point.
- The server finds the corresponding vertices for the given coordinates, computes the shortest path using Dijkstra's algorithm, and outputs:
  - The number of nodes on the shortest path.
  - The coordinates of each node along the path.
  - The character 'E' to indicate the end of the request.
- The user must acknowledge each line of output by typing 'A'.

## Assumptions

- The file `edmonton-roads-2.0.1.txt` exists in the directory.
- No street name has a comma.
- No two vertex lines have the same identifier.
- Vertex identifiers fit in a 32-bit integer.
- The coordinates provided in the request exist in the road network file.
- There is not always a unique least cost path between two points.
- Input is well-formed and follows the specified format.

## How to Run

1. Compile and link the programs using the provided Makefile:
   ```
   make
   ```

2. Run the executable:
   ```
   ./server
   ```

3. Type a request of the form:
   ```
   R pt1_lat pt1_long pt2_lat pt2_long
   ```
   where the coordinates correspond to points in the road network.

4. For each line of output, type the character 'A' to acknowledge receipt.

5. The program will print 'E' to indicate the end of the request.

6. To clean up object files and the executable, run:
   ```
   make clean
   ```

## Example

**Input:**
```
R 5343099 -113491331 534765 -113490040
```

**Output:**
```
N <number_of_nodes>
W <lat1> <lon1>
W <lat2> <lon2>
...
E
```
(Type 'A' after each line except the last.)

## Makefile Targets

- `make` (default): Builds the project.
- `make server`: Links all the object files.
- `make digraph.o`: Compiles `digraph.cpp` and `digraph.h` to create `digraph.o`.
- `make dijkstra.o`: Compiles `dijkstra.cpp` and `dijkstra.h` to create `dijkstra.o`.
- `make server.o`: Compiles `server.cpp` to create `server.o`.
- `make clean`: Removes object files and the executable.
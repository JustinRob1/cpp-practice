# Name: Justin Robertson
# SID: 1702786
# CCID: jtrober1
# CMPUT 275, Winter 2022

# Weekly Exercise #6: Graph Concepts

CC = g++
C_FLAGS = -std=c++11 -Wall -g

we6_solution: digraph.o graph_concepts.o
	$(CC) $(C_FLAGS) digraph.o graph_concepts.o -o we6_solution

digraph.o: digraph.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph.cpp

graph_concepts.o: graph_concepts.cpp digraph.h
	$(CC) $(C_FLAGS) -c graph_concepts.cpp
run:
	make we6_solution
	./we6_solution < edmonton-roads-2.0.1.txt

clean:
	-rm *.o we6_solution

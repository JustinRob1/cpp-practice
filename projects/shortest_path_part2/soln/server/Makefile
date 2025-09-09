CC = g++
C_FLAGS = -std=c++11 -Wall -g

server: digraph.o server.o dijkstra.o
	$(CC) $(C_FLAGS) digraph.o server.o dijkstra.o -o server

digraph.o: digraph.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph.cpp

dijkstra.o: dijkstra.cpp dijkstra.h
	$(CC) $(C_FLAGS) -c dijkstra.cpp

server.o: server.cpp dijkstra.h wdigraph.h
	$(CC) $(C_FLAGS) -c server.cpp

clean:
	-rm *.o server

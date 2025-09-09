# Name: Justin Robertson
# SID: 1702786
# CCID: jtrober1
# CMPUT 275, Winter 2022

# Weekly Exercise #7: Climbing

CC = g++
C_FLAGS = -std=c++11 -Wall -g

we7_solution: climbing.o 
	$(CC) $(C_FLAGS) climbing.o -o we7_solution

climbing.o: climbing.cpp 
	$(CC) $(C_FLAGS) -c climbing.cpp

clean:
	-rm *.o we7_solution

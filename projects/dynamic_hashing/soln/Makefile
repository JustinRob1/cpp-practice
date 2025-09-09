# Name: Justin Robertson
# SID: 1702786
# CCID: jtrober1
# CMPUT 275, Winter 2022

# Weekly Exercise #4: Dynamic Hashing 

CC = g++
C_FLAGS = -std=c++11 -Wall -g

we4_solution: we4_test.o 
	$(CC) $(C_FLAGS) we4_test.o -o we4_solution

we4_test.o: we4_test.cpp hash_table.h
	$(CC) $(C_FLAGS) -c we4_test.cpp

clean:
	-rm *.o we4_solution

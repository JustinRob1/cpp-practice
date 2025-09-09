# Name: Justin Robertson
# SID: 1702786
# CCID: jtrober1
# CMPUT 275, Winter 2022

# Weekly Exercise #3: Reference Manager

CC = g++
C_FLAGS = -std=c++11 -Wall -g

we3_solution: we3_test.o ref_manager.o
	$(CC) $(C_FLAGS) we3_test.o ref_manager.o -o we3_solution

we3_test.o: we3_test.cpp ref_manager.h
	$(CC) $(C_FLAGS) -c we3_test.cpp

ref_manager.o: ref_manager.cpp ref_manager.h
	$(CC) $(C_FLAGS) -c ref_manager.cpp

clean:
	-rm *.o we3_solution

# Name: Justin Robertson
# SID: 1702786
# CCID: jtrober1
# CMPUT 275, Winter 2022

# Weekly Exercise #5: Matrix Class

CC = g++
C_FLAGS = -std=c++11 -Wall -g

we5_solution: we5_test.o matrix.o
	$(CC) $(C_FLAGS) we5_test.o matrix.o -o we5_solution

we5_test.o: we5_test.cpp matrix.h
	$(CC) $(C_FLAGS) -c we5_test.cpp

matrix.o: matrix.cpp matrix.h
	$(CC) $(C_FLAGS) -c matrix.cpp

clean:
	-rm *.o we5_solution

#include <iostream>
using namespace std;

/* 
    Descirption: Takes two query values representing two rivers and determines the largest river 
    that both connect to 

    Arguments: total_river_array (int*): points to the start of the array of values a[] from the description
    num_r (int): the number of rivers
    river1 (int), river2 (int): the two query values from a single query

    Returns: An integer representing the river where river1 and river2 connect
*/
int query(int* total_river_array, int num_r, int river1, int river2) {
	// The river where river1 and river2 connect
	int connect = 0;

	// Integer used as an index to iterate through the each river_array
	int count1 = river1 - 1;
	int count2 = river2 - 1;

	// Arrays representing all rivers that river1 and river2 connect to
	int *river_array1 = new int[river1 + 1];
	int *river_array2 = new int[river2 + 1];

	// Initialize each element of the arrays to 0
	for (int i = 0; i < river1 + 1; i++) {
		river_array1[i] = 0;
	}
	for (int i = 0; i < river2 + 1; i++) {
		river_array2[i] = 0;
	}

	// The last element of each array is the river itself
	river_array1[river1] = river1;
	river_array2[river2] = river2;

	// The index for the total_river_array
	int index = river1 - 1;

	// Iterate through the total_river_array and add each element
	// to river_array1 (starting from the end) until 0 is reached
	while (count1 > -1) {
		if (total_river_array[index] == 0) {
			break;
		} else {
			river_array1[count1] = total_river_array[index];
			index = total_river_array[index] - 1;
			count1--;
		}
	}

	// reset the index for the second river array
	index = river2 - 1;

	// Iterate through the total_river_array and add each element
	// to river_array2 (starting from the end) until 0 is reached
	while (count2 > -1) {
		if (total_river_array[index] == 0) {
			break;
		} else {
			river_array2[count2] = total_river_array[index];
			index = total_river_array[index] - 1;
			count2--;
		}
	}

	// Reset the index variables
	count1 = river1;
	count2 = river2;

	// Continually compared the elements, starting from the end of each array
	// until the two elements equal each other, which would be the first river they
	// connect to, or a 0 is reached in either array, then we would return 0;
	while (river_array1[count1] > -1 && river_array2[count2] > -1) {
		if (river_array1[count1] == river_array2[count2]) {
			connect = river_array1[count1];
			break;
		} else if (river_array1[count1] == 0 || river_array2[count2] == 0) {
			connect = 0;
			break;
		// Decrement index of river1 since the element is larger
		} else if (river_array1[count1] > river_array2[count2]) {
			count1--;
		// Decrement the index of river2 since the element is larger
		} else {
			count2--;
		}
	}

	// Must deallocate memory for two river arrays
	delete[] river_array1;
	delete[] river_array2;

	return connect;
}

int main() {
	// number of rivers
	int num_r;
	// number of queries
	int num_q;
	// Reprsents the two respective queries
	int river1;
	int river2;

	cin >> num_r;
	cin >> num_q;

	// Array to hold all the rivers
	int *total_river_array = new int[num_r];
	// Array to hold all of the queries
	int *query_array = new int[num_q * 2];

	for (int i = 0; i < num_r; i++) {
		cin >> total_river_array[i];
	}

	for (int i = 0; i < num_q * 2; i++) {
		cin >> query_array[i];
	}

	// Iterate through all elements of the query array and call the
	// function query for each pair of query values, print out the return
	// value
	for (int i = 0; i < num_q * 2; i+=2) {
		river1 = query_array[i];
		river2 = query_array[i+1];
		cout << query(total_river_array, num_r, river1, river2) << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

/* 
	Descirption: Takes two pointers that are pointing to endpoints of an array/subarray 
	and reverses all entries between these pointers including the entry pointed to by begin
	but not the entry pointed to by end

	Arguments: begin (*int): A pointer to the beginning of an idol group that will be reversed
	end (*int): A pointer to the end of an idol group that will be reversed

	Returns: None 
*/
void reverse(int* begin, int* end) {
	// move endpoints closer to eachother until
	// begin >= end
	while (begin < end){
		// swap *begin and *end by using
		// a temporary variable
		int temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}

int main() {
	int n;
	int i = 0;
	int j = 1;
	// number of idols
	int counter = 1;

	cin >> n;

	// holds the initial array
	int *num_array = new int[n];

	// holds the index number of the idols
	// to find the idol groups
	int *idol_array = new int[n + 1];

	// 0 must be the first element in the array because the first
	// group is a[0] to a[i - 1] where i is the first idol
	idol_array[0] = 0;

	for (int i = 0; i < n; i++){
	 	cin >> num_array[i];
	}

	// iterate through all elements of num_array to find
	// all of the idols
	while (i <= n - 1){
		// the last element of every array is always considered an idol
		if (i == n - 1){
			// print the final idol
			cout << num_array[i] << endl;
			// add index of idol to idol_array
			idol_array[counter] = i;
			break;
		}
		// If the current element is less than the next element
		// in the array, it is not an idol and we increment i to go to 
		// the next element
		else if (num_array[i] <= num_array[j]){
			i++;
			j = i + 1  ;
		}
		else {
			// If the current element is greater than every element
			// to its right, it is an idol.
			// Print the idol and add its index to idol_array
			// Increase counter (the number of idols)
			if (j == n - 1 and num_array[i] > num_array[j]){
				idol_array[counter] = i;
				counter++;
				cout << num_array[i] << " ";
				// Set i and j to check the next element
				// in the array
				i++;
				j = i + 1;
			}
			// if j != n - 1, increment j to check if the current
			// element is greater than the j + 1 element in the array
			else {
				j++;
			}
		}
	}

	// idol_array had to be initialized with n - 1 elements
	// but usually every element in the array is not an idol
	// Therefore, we must copy the elements of the old idol_array
	// to a new idol_array that only contains as many elements as
	// there are idols
	int *new_idol_array = new int[counter + 1];
	for (int i = 0; i < counter + 1; i++){
		new_idol_array[i] = idol_array[i];
	}
	// Must delete the old idol_array
	delete[] idol_array;
	
	// For every idol index in new_idol_array
	// reverse all idol groups (a[i+1] to a[j-1])
	// where i and j are the indexes of the idols
	for (int i = 0; i < counter + 1; i++){
		// Set the beginning and end pointers
		// of the subarray we want to reverse
		int begin = new_idol_array[i];
	 	int end = new_idol_array[i+1] - 1;

	 	// reverse the idol group before the first idol
	 	// a[0] to a [i - 1] where i is the index of the 
	 	// first idol
	 	if (i == 0){
	 		reverse(num_array+begin, num_array+end);
	 	}
	 	// For every other group, reverse a[i+1] to a[j-1]
	 	// where i and j are the indices of the idols in the array
	 	else {
	 		reverse(num_array+(begin+1), num_array+end);
	 	}
	}

	// Print out all elements of the reversed array 
	for (int i = 0; i < n; i++){
		if (i == n - 1){
			cout << num_array[i] << endl;
		}
		else {
			cout << num_array[i] << ' ';
		}
	}
}

#include <iostream>
using namespace std;

/* 
	Description: The function outputs either "YES" or "NO" indicating whether 
	there is a pair (i, j) in the price_array with 1 <= i < j <= n such 
	that pi + pj = T
*/
int main() {
	// Index at the beginning of the array
	int start = 0;
	int n;
	int T;
	string answer = "NO";

	cin >> n;
	cin >> T;

	// Index at the end of the array
	int end = n - 1;
	int *price_array = new int[n];

	// Input all integers into price_array
	for (int i = 0; i < n; i++) {
	 	cin >> price_array[i];
	}

	// Continually move the indexs closer together until
	// the start index is greater than the end index
	// If the start index becomes larger than the end
	// index then there is no pair (i, j) such that i + j = T
	while (start < end) {
		// If the sum any two integers in the array equals T
		// then a valid pair such that pi + pj = T
		if (price_array[start] + price_array[end] == T) {
			answer = "YES";
			break;
		// The sum of the element at index start and the element
		// at the end index is less than T, therefore we must increment
		// the start index to check the next element which is larger
		// than the current element
		} else if (price_array[start] + price_array[end] < T) {
			start++;
		// price_array[start] + price_array[end] > T
		// Therefore we must decrement the end index since the
		// previous element is less than the current element
		} else {
			end--;
		}
	}
	cout << answer << endl;
	return 0;
}

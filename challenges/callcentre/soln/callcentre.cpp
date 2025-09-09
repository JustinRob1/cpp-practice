#include <iostream>
using namespace std;

int main() {
	int n;
	int q;
	cin >> n;
	cin >> q;

	int *call_array = new int[n];
	int *q_array = new int[q * 2];
	int *diff_array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> call_array[i];
	}
	for (int i = 0; i < q * 2; i++) {
		cin >> q_array[i];
	}

	diff_array[0] = call_array[0];
	int sum = call_array[0];
	for (int i = 1; i < n; i++) {
		diff_array[i] = sum + call_array[i];
		sum += call_array[i];
	}

	for (int i = 0; i < q * 2; i+=2) {
		int start = q_array[i] - 1;
		int end = q_array[i  + 1] - 1;
		
		if (start == end) {
			cout << call_array[start] << endl;
		} else {
			cout << (diff_array[end] - diff_array[start - 1]) << endl;
		}
	}

	delete[] call_array;
	delete[] q_array;
	delete[] diff_array;
    return 0;
}

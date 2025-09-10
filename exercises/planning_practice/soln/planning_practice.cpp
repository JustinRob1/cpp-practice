#include <iostream>
using namespace std;

int main(){
	// Declare your variables
	int n;
	int t;

	// Read the input
	cin >> n;
	cin >> t;
	int *total_array = new int[n*2];

	for (int i = 0; i < (n*2); i++){
		cin >> total_array[i]; 
	}
	int bounds[2] = {0, 24};

	for (int i = 0; i < n * 2; i++){
		if (i == 0 or i % 2 == 0){
			if (total_array[i] > bounds[0] and total_array[i] <= bounds[1]){
			bounds[0] = total_array[i];
			}
		}
		else {
			if (total_array[i] < bounds[1] and total_array[i] >= bounds[0]){
			bounds[1] = total_array[i]; 
			}
		}
	}
	// Answer the question
	int diff = (bounds[1] - bounds[0]);
	int days = 0;
	int counter = 0;

	if (diff == 0){
		cout << "IMPOSSIBLE" << endl;
	}
	else { 
		while(counter < t){
			counter += diff;
			days++;
		}
		cout << days << endl;
	}

	return 0;
}

#include <iostream>

using namespace std;

int main() {
  // declare variables
	int S;
	int A;
	int i = 0;
	int counter = 0;
	bool flag = true;
  // read the input
	cin >> S;
	cin >> A;

	int * int_array = new int[A];
	int * previous_elements = new int[A + 1];
	previous_elements[0] = S;
  // solve the problem
	for (int i = 0; i < A; i++){
		cin >> int_array[i];
	}
	if (int_array[0] < 0){
		cout << int_array[0] << endl;
	}
	else {
		while (flag){
			previous_elements[counter] = int_array[i];
			int diff = int_array[i] - S;
			if (int_array[diff] < 0){
				cout << int_array[diff] << endl;
				flag = false;
			}
			else {
				for (int j = 0; j < counter; j++){
					if (int_array[diff] == previous_elements[j]){
						cout << "There was a cycle" << endl;
						flag = false;
					}
				}
				i = diff;
				counter++;
			}
		}
	}
  // print the output

  return 0;
}

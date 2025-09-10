#include <iostream>
using namespace std;

int main(){
	int n;
	int m;
	cin >> n;
	cin >> m;

	int* num_arr = new int[n];
	long long int* prods_above = new long long int[n];
	long long int* prods_below = new long long int[n];

	for (int i = 0; i < n; i++) {
		cin >> num_arr[i]; 
	}

	long long int prod = 1;
    for (int i = 0; i < n; i++) {
        if (i > m) {
            prod *= num_arr[i - m - 1];
            prods_below[i] = prod;
        } else if (i - m <= 0 && i + m >= n - 1) {
            prods_below[i] = 0;
        } else {
            prods_below[i] = 1;
        }
    }

    prod = 1;
    for (int i = n - 1; i > -1; i--) {
        if (i < n - m - 1) {
            prod *= num_arr[i + m + 1];
            prods_above[i] = prod;
        } else if (i - m <= 0 && i + m >= n - 1) {
            prods_above[i] = 0;
        } else {
            prods_above[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << prods_below[i] * prods_above[i] << endl;
        } else {
            cout << prods_below[i] * prods_above[i] << " ";
        }
    }  
    return 0;
}
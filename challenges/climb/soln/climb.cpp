#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int waypoints[n];
	for (int i = 0; i < n; i++) {
		cin >> waypoints[i];
	}

	for (int i = 0; i < n; i++) {
		if (waypoints[i] < waypoints[i + 1] && i != n - 1) {
			waypoints[i] = 1;
		} else {
			waypoints[i] = 0;
		}
	}

	int count = 0;
	for (int i = n - 1; i > -1; i--) {
		if (waypoints[i] == 1) {
			count++;
			waypoints[i] = count;
		} else {
			count = 0;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		cout << waypoints[i] << ' ';
	}
	cout << waypoints[n - 1] << endl;

	return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n; 
	int m;
	cin >> n;
	cin >> m;
	int west[n + 1];
	int east[m + 1];

	for (int i = 0; i < n; i++) {
		cin >> west[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> east[i];
	}
	west[n] = INT_MAX;
	east[m] = INT_MAX;

	int i = 0;
	int j = 0;
	int time = 0;
	char side = 'W';

	while (i != n || j != m) {
		if (west[i] <= east[j] && side == 'W') {
			if (time < west[i]) {
				time += west[i] - time;
			}
			time += 100;
			i++;
			side = 'E';
		} else if (west[i] <= east[j] && side == 'E') {
			if (time < west[i]) {
				time += west[i] - time;
			}
			time += 200;
			i++;
		} else if (west[i] >= east[j] && side == 'W') {
			if (time < east[j]) {
				time += east[j] - time;
			}
			time += 200;
			j++;
		} else {
			if (time < east[j]) {
				time += east[j] - time;
			}
			time += 100;
			j++;
			side = 'W';
		}
	}

	cout << time << endl;
	return 0;
}
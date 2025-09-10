#include <iostream>

using namespace std;

int main() {
  int n;
  int stairs = 0;

  cin >> n;

  int* floors = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> floors[i];
  }

  for (int i = 0; i < n; i++) {
    if (floors[i] < floors[i + 1]) {
      stairs += floors[i + 1] - floors[i];
    }
  }

  cout << stairs << endl;  
  
  return 0;
}

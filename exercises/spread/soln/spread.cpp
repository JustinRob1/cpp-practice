#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  long long array[1000];

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> array[i];
  }

  // now solve the problem and print the answer
  // hint: if your answer is stored in the variable answer, you can output using the code in the comment below:
  // cout << answer << endl;
  int max = 0;
  int min = pow(10, 9);

  for (int i = 0; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
    if (array[i] < min) {
      min = array[i];
    }
  }

  cout << max - min << endl;
  return 0;
}

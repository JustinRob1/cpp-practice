#include <iostream>
#include <cmath>

using namespace std;

int main() {
  unsigned int n;

  cin >> n;

  // calculate the answer
  unsigned int a = 0;
  unsigned int b = n;

  if (n % 2 != 0){
  }
  else {
      while (n >= pow(2, a)) {
        if ((int) n % (int) pow(2, a) == 0) {
          b = (n / pow(2, a));
        }
      a++;
    }
  }
  // print the output
  cout << b << endl;
  return 0;
}

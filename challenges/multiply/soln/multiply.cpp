#include <iostream>

using namespace std;

int main() {
  int n, m;
  // Read the input
  cin >> m >> n;
  int a[m];
  int b[n];
  int product[m+n];

  for (int i = 0; i < m+n; i++) {
  	product[i] = 0;
  }

  for (int i = m - 1; i > -1; i--) {
  	cin >> a[i];
  }

  for (int i = n - 1; i > -1; i--) {
  	cin >> b[i];
  }

  //Solve the problem
 
  for (int i = 0; i < m; i++) {
  	for (int j = 0; j < n; j++) {
  		product[i+j] += a[i]*b[j];
  		product[i+j+1] = product[i+j+1] + product[i + j] / 10;
  		product[i+j]%=10;
  	}
  }

  for (int i = m + n - 1; i > -1; i--) {
  	if (i != 0) {
  		cout << product[i] << " ";
  	} else {
  		cout << product[i] << endl;
  	}
  }
  
  return 0;
}

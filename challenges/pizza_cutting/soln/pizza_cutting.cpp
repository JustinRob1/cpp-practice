#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// declare your variables
 	unsigned int n;
  	unsigned int m;
  	unsigned int counter = 0;
  	string answer = "BAD";

  	// read the input
  	cin >> n;
  	cin >> m;

	// solve, good luck!
  	while(m >= pow(n, counter)) {
  		if(n == 1){
  			break;
  		}
  		else if(m == pow(n, counter)) {
  			answer = "GOOD";
  			break;
  		}
  		counter++;
  	}
	cout << answer << endl;
	return 0;
}

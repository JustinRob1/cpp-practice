#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int); 
void twinPrimes(int); 

int main() {
	char query;
	int num;
	cin >> query;
	cin >> num;

	if (query == 'p') {
		if (isPrime(num) == true) {
			cout << "prime" << endl;
		} 
		else {
			cout << "not prime" << endl;
		}

	}
	else if (query == 't') {
		twinPrimes(num);
	}
	return 0;
}

// Retuns true if n is prime and false otherwise
// Used to check for prime numbers in the function twinPrimes
bool isPrime(int n) {
	if (n <= 1){
		return true;
	}
	// One factor of a number must be less than or equal to the square
	// root of that number. Thus, the loop continues iterating up to the sqaure
	// root of the number
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0){
			return false;
		}
	}
	// The integer is prime if it is not a composite integer
	return true;
}

// Prints the first k twin prime pairs in order
void twinPrimes(int k) {
	// the first twin prime pair is 3 and 5
	int i = 3;
	while (k > 0) {
		if (isPrime(i) == true and isPrime(i + 2) == true) {
			cout << i << " " << i + 2 << endl;
			k--;
		}
		// The only even prime number is 2, so the loop can be 
		// incremented by 2 since we do not need to check even numbers
		i += 2;
	}
}

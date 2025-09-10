#include <iostream>
#include <cstring>
using namespace std;

int main(){
	// declare your variables
	int n;
	string s;
	int i = 0;
	int j;
	int freq_count[26] = {0};
	int longest = 0;
	int non_pairs = 0;
	// read the input
	cin >> n;
	cin >> s; 
	// solve, good luck!
	char char_s[s.length() + 1];
	strcpy(char_s, s.c_str());

	while (char_s[i] != '\0') {
		if (char_s[i] >= 'a' && char_s[i] <= 'z') {
			j = char_s[i] - 'a';
			freq_count[j]++;
		}
		i++;
	}
	for (i = 0; i < 26; i++){
		if (freq_count[i] == 1) {
			non_pairs++;
		}
		else if (freq_count[i] % 2 == 0){
			longest += (freq_count[i]);
		}
		else if (freq_count[i] % 2 != 0 and freq_count[i] > 1){
			non_pairs++;
			longest += (freq_count[i] - 1);
		}
	}

	if (non_pairs > 0){
		cout << longest + 1 << endl;
	}
	else {
		cout << longest << endl;
	}
	return 0;
}

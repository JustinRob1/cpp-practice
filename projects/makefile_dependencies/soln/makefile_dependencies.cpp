#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

/* 
    Description: Iterates through the elements in the vector associated with the target name 
    and recursively calls itself if any of the elements are also target names. Prints the 
    target name afterwards

    Arguments: target_name (string): The name of the target that is currently being recursed through
    history (map<string, vector<string>>&): a map of all of the target names with the value being
    a vector containing the list of dependencies
    built (set<string>&): a set containg all of the target names that have already been built

    Returns: The minimum value of burst
*/
void recur(string target_name, map<string, vector<string>>& history,
	set<string>& built) {
	// The the vector associated with the current target name containg
	// the dependencies
	vector<string> temp = history.at(target_name);

	// Iterate through the list of dependencies and call recur on the element
	// only if it is a valid target name (a key in the history map) or it has
	// not already been built
	for (auto itr = temp.begin(); itr != temp.end(); itr++) {
		if (history.find(*itr) == history.end() || built.find(*itr) != built.end()) {
		} else {
			recur(*itr, history, built);
		}
	}
	// Print the name of the target name being recursed and add it to the built set
	cout << target_name << " ";
	built.insert(target_name);
}

int main() {
	// a map of all of the target names with the value being
    // a vector containing the list of dependencies
	map<string, vector<string>> history;

	// a set containg all of the target names that have already been built
	set<string> built;

	int n, m;
	cin >> n;
	cin >> m;

	// Input all the target names and their respective dependencies
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		string target_name;
		cin >> target_name;
		// Remove the colon from the target name
		target_name.pop_back();

		// A temporary vector to hold the inputted dependencies to be later inserted
		// into the map
		vector<string> dep_vector;
		for (int i = 0; i < num; i++) {
			string dep;
			cin >> dep;
			dep_vector.push_back(dep);
		}
		// Insert the key-value pair of the target name and vector containing the list
		// of the respective dependencies
		history.insert(pair<string, vector<string>>(target_name, dep_vector));
	}

	// Loop through all the make commands and determine if the elements need to be
	// recursed through or not
	for (int i = 0; i < m; i++) {
		string make, target_name;
		cin >> make;
		cin >> target_name;

		// The target name has already been built previously
		if (built.find(target_name) != built.end()) {
			cout << "make: `" << target_name << "' is up to date." << endl;
		// The target name has not been built so iterate through all of
		// its dependencies
		} else {
			// The vector associated with the current target name containg
			// the dependencies
			vector<string> temp = history.at(target_name);
			// Iterate through the list of dependencies and call recur on the element
			// only if it is a valid target name (a key in the history map) or it has
			// not already been built
			for (auto itr = temp.begin(); itr != temp.end(); itr++) {
				if (history.find(*itr) == history.end() ||
					built.find(*itr) != built.end()) {
				} else {
					recur(*itr, history, built);
				}
			}
			// Print the target name and insert it into the built set
			cout << target_name << endl;
			built.insert(target_name);
		}
	}
	return 0;
}


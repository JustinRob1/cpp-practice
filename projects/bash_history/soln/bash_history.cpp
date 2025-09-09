#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int main() {
	int n;
	cin >> n;

	// Map to contain all the directories with a set as the value
	// that represents the files inside the directory
	map<string, set<string>> dir_map;

	// The current directory is always going to be the root directory
	string current_dir = "/";

	// Add the key-value pair of the root directory to the map
	set<string> file_set;
	dir_map.insert(pair<string, set<string>>("/", file_set));

	for (int i = 0; i < n; i++) {
		string query;
		cin >> query;
		if (query == "cd") {
			string dir_name;
			cin >> dir_name;
			// If s is .. then we move back to the previous directory
			if (dir_name == "..") {
				// String that holds the new current directory
				string temp = "";
				// Loop backwards through the characters of the current directory string
				// until the first / is encountered, then loop through the
				// current directory string up to the index of the / and add
				// all characters to temp, this will represent moving backwards
				// to the previous directory
				for (int i = (int)current_dir.size(); i > -1; i--) {
					if (current_dir[i] == '/' && i != 0) {
						for (int j = 0; j < i; j++) {
							temp += current_dir[j];
						}
						current_dir = temp;
						break;
					// If only one / is encountered, then we move back to the root
					// directory
					} else if (i == 0) {
						current_dir = "/";
					}
				}
			// If dir_name is not .. then it must be a subdirectory
			} else {
				// If we are currently in the root directory, then we only need
				// to add dir_name to "/", the current directory
				if (current_dir == "/") {
					// If the directory name is not already in the map, then we insert a new
					// key-value pair to it with a new empty set as the value
					// Update the current directory string as well
					if (dir_map.find("/" + dir_name) == dir_map.end()) {
						current_dir = "/" + dir_name;
						set<string> file_set;
						dir_map.insert(pair<string, set<string>>(current_dir, file_set));
					// The directory name is already in the map so we only update the directory
					// name (i.e go back to the previous directory)
					} else {
						current_dir = "/" + dir_name;
					}
				// We are not in the root directory so we must be in a sub directory
				} else {
					// If the directory name is not already in the map, then we insert a new
					// key-value pair to it with a new empty set as the value
					// Update the current directory string as well by adding a / between the
					// current directory name and the new directory name
					if (dir_map.find("/" + dir_name) == dir_map.end()) {
						current_dir = current_dir + "/" + dir_name;
						set<string> file_set;
						dir_map.insert(pair<string, set<string>>(current_dir, file_set));
					// The directory name is already in the map so we only update the directory
					// name (i.e go back to the previous directory)
					} else {
						current_dir = current_dir + "/" + dir_name;
					}
				}
			}
		// If the query is not cd them it must be ls
		} else {
			// Add the given file name to the current directory
			// we are in
			string file_name;
			cin >> file_name;
			dir_map[current_dir].insert(file_name);
		}
	}

	// Iterate through all the directory names (printing out each name)
	// in the map and print out all the file names that are contained
	// in each value set using a seperate for loop (space separated)
	map<string, set<string>>::iterator itr;
	for (itr = dir_map.begin(); itr != dir_map.end(); itr++) {
		cout << itr->first;
		set<string> file_set;
		file_set = itr->second;
		for (auto i = file_set.begin(); i != file_set.end(); i++) {
			cout << ' ' << *i;
		}
		cout << endl;
	}
	return 0;
}

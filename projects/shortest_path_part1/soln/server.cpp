#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>
#include <unordered_map>
#include "dijkstra.h"

using namespace std;

// Struct that holds the coordinates of the point
struct  Point  {
	long long lat;  // latitude of the point
	long long lon; // longtitude of the point
};

// Function prototypes
void readGraph(string filename, WDigraph& graph, unordered_map<int, Point>& points);
long long manhattan(const Point& pt1, const Point& pt2);

/* 
    Description: Reads Edmonton map data from the provided file and loads it into
    the WDigraph object passed to this function/ Stores vertex coordinates in Point
    struct and map each vertex identifier to its corresponding Point struct variable.

    Arguments: filename (string): the name of the file that describes a road network
	graph (WDigraph&): an instance of the weighted directed graph (WDigraph) class
	points (unordered_map<int, Point>&): a mapping between vertex identifiers and their
	coordinates

    Returns: None

*/
void readGraph(string filename, WDigraph& graph, unordered_map<int, Point>& points) {
	ifstream file;
	file.open(filename);
	string line;

	// Continually read lines until the end of the file
	while(getline(file, line)) {
		// If the first character in line is V then we only need to get
		// the first integer
		if (line[0] == 'V') {
			// Index of the first comma encountered
			size_t index1 = line.find(',');
			// Index of the second comma encountered
			size_t index2 = line.find(',', index1+1);
			// Index of the third comma encountered
			size_t index3 = line.find(',', index2+1);

			// The vertex id is the substring that starts at index1 + 1
			// and is length index2 - index1 - 1
			string str1 = line.substr(index1+1, index2 - index1 - 1);
			// The latitude is the substring that starts at index2 + 1
			// and is length index3 - index2 - 1
			string str2 = line.substr(index2+1, index3 - index2 - 1);
			// The longitude is the substring that starts at index3 + 1
			// up until the end of the line
			string str3 = line.substr(index3+1);

			// Convert the string to an integer so it can be added to
			// the graph
			int v = stoi(str1);
			graph.addVertex(v);

			// Convert the substrings to a double 
			double temp_lat = stod(str2);
			double temp_long = stod(str3);

			// Convert the doubles of the latitude and longitude to long long
			long long latitude = static_cast<long long>(temp_lat * 100000);
			long long longitude = static_cast<long long>(temp_long * 100000);

			// Insert the key value pair with the vertex identifier as the key and
			// the point as the value
			Point point = {latitude, longitude};
			points[v] = point;

		// If the first character in line is V then we need to get
		// the first and second integer
		} else if (line[0] == 'E') {
			// Index of the first comma encountered
			size_t index1 = line.find(',');
			// Index of the second comma encountered
			size_t index2 = line.find(',', index1+1);
			// Index of the third comma encountered
			size_t index3 = line.find(',', index2+1);

			// The first vertex id is the substring that starts at index1 + 1
			// and is length index2 - index1 - 1
			string str1 = line.substr(index1+1, index2 - index1 - 1);
			// The second vertex id is the substring that starts at index2 + 1
			// and is length index3 - index2 - 1
			string str2 = line.substr(index2+1, index3 - index2 - 1);

			// Convert both strings to integers so the edge can be added to the graph
			int v1 = stoi(str1);
			int v2 = stoi(str2);

			// Get the struct points that contain the respective longitude
			// and latitude of the two points
			Point point1 = points[v1];
			Point point2 = points[v2];

			// Calculate the manhatten distance between the two points
			long long distance = manhattan(point1, point2);

			// Add the edges with the corresponding edge costs to the graph
			graph.addEdge(v1, v2, distance);
		}
	}
}


/* 
    Description: Returns the Manhattan distance between the two given points

    Arguments: pt1 (const Point&): An instance of the struct Point representing the coordinates 
	of the first vertex

	pt2 (const Point&): An instance of the struct Point representing the coordinates of the 
	second vertex

    Returns: A long long representing the distance between the two given points 

*/
long long manhattan(const Point& pt1, const Point& pt2) {
	long long distance = abs(pt1.lon - pt2.lon) + abs(pt1.lat - pt2.lat);
	return distance;
}

int main () {
	char query;
	int start_lat, start_long, end_lat, end_long;
	cin >> query >> start_lat >> start_long >> end_lat >> end_long;
	
	WDigraph graph;
	// a mapping between vertex identifiers and their
	// coordinates
	unordered_map<int, Point> points;

	string file = "edmonton-roads-2.0.1.txt";
	// Read in the Edmonton roads file to initalize the graph
	readGraph(file, graph, points);
	int start_vertex, end_vertex;

	// Iterate through all the points in the points unordered map and get the 
	// vertex id for the start vertex and the end vertex
	for (auto iter = points.begin(); iter != points.end(); iter++) {
        if (start_lat == iter->second.lat || start_long == iter->second.lon) {
        	start_vertex = iter->first;
        }

        if (end_lat == iter->second.lat || end_long == iter->second.lon) {
        	end_vertex = iter->first;
        }
     }

    // Run dijkstra's to construct the search tree
	unordered_map<int, PIL> searchTree;
	dijkstra(graph, start_vertex, searchTree);

	// Read off a path
	list<int> path;
	int stepping = end_vertex;
	// Continue stepping through the path until we reach the 
	// start vertex
	while (stepping != start_vertex) {
		path.push_front(stepping);
		// Crawl up the search tree one step
		stepping = searchTree[stepping].first;
	}
	path.push_front(start_vertex);

	// Covert the list to an array in order to print of the
	// coordinates in the for loop below
	int path_arr[path.size()];
	int k = 0;

	for (int const &i: path) {
		path_arr[k++] = i;
	}

	// If the start vertex is not in the tree then print N 0
	char c;
	if (searchTree.find(start_vertex) == searchTree.end()) {
		cout << "N " << 0 << endl;
		cin >> c;
		cout << 'E' << endl;
	// The vertex is in the tree so we print the coordinates (lattiude and longitude)
	// of every vertex along the shortest cost path from the start vertex to the end 
	// vertex
	} else {
		cout << "N " << path.size() << endl;
		cin >> c;
		for (unsigned int i = 0; i < path.size(); i++) {
			int vertex = path_arr[i];
			cout << "W " << points[vertex].lat << " " << 
			points[vertex].lon << endl;
			cin >> c;
		}
		cout << 'E' << endl;
	}

	return 0;
}
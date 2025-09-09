#include <iostream>
#include <vector>
#include "digraph.h"

using namespace std;

/* 
    Description: Recursively calls dfs on the neighbours of the current node and updates
    the corresponding key value in the unordered_map to true if the node has not
    been visited yet

    Arguments: graph (const Digraph&): An object of the class Digraph that you want to
    find the number of connected components
    node (int): The current node that is being searched
    visited_map (unordered_map<int, bool>): An unordered map that keeps track of which 
    nodes have already been visitied

    Returns: None 
*/
void dfs(const Digraph& graph, int node, unordered_map<int, bool>& visited_map) {
	// Set the value in the visited_map to true for the current node
	visited_map[node] = true;

	// Iterate through all the neighbours of the current node and
	// recursively call dfs to set all the values to true in the visited_map
	for (auto itr = graph.neighbours(node); itr != graph.endIterator(node); ++itr) {
		// If the neighbour has not yet been visited, call dfs with it as an argument
		if (visited_map[*itr] == false) {
			dfs(graph, *itr, visited_map);
		}
	}
}

/* 
    Description: Takes a single parameter, which is an instance of the Digraph class,
	and returns the number of connected components in this graph

    Arguments: graph (const Digraph&): An object of the class Digraph that you want to

    Returns: num_components (int): The number of connected components in the graph object
*/
unsigned int count_components(const Digraph& graph) {
	// Get a vector of the vertices of the current graph
	// in order to get the number of nodes in the graph
	vector<int> vertices = graph.vertices();
	// unordered map to track the visited vertices
	unordered_map<int, bool> visited_map;

	// Initally set all values to false
	for (auto i : vertices) {
		visited_map[i] = false;
	}

	// Iterate through all the vertices and call dfs on the vertex
	// if it has not yet been visited
	int num_components = 0;
	for (auto i : vertices) {
		// If the vertex has not been visited yet, then it is part of a
		// connected component that not been searched yet, so increment
		// num_components by 1
		if (visited_map[i] == false) {
			dfs(graph, i, visited_map);
			num_components++;
		}
	}
	return num_components;
}

/* 
    Description: Reads the graph description from stdin and builds an instance of the Digraph
	class to represent the undirected graph

    Arguments: None

    Returns: graph (Digraph): The graph of class Digraph that was contrsucted from
    the description read in from stdin
*/
Digraph read_city_graph_undirected() {
	Digraph graph;
	string line;

	// Continually read lines until the end of the file
	while(getline(cin, line)) {
		// If the first character in line is V then we only need to get
		// the first integer
		if (line[0] == 'V') {
			// Index of the first comma encountered
			size_t index1 = line.find(',');
			// Index of the second comma encountered
			size_t index2 = line.find(',', index1+1);

			// The vertex id is the substring that starts at index1 + 1
			// and is length index2 - index1 - 1
			string str1 = line.substr(index1+1, index2 - index1 - 1);

			// convert the string to an integer so it can be added to
			// the graph
			int v = stoi(str1);
			graph.addVertex(v);
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

			// Convert both strings to integers so they can be added to the graph
			int v1 = stoi(str1);
			int v2 = stoi(str2);
			graph.addEdge(v1, v2);
			graph.addEdge(v2, v1);
		}
	}
	return graph;
}

/*
	Calls the other functions to read the description of a graph from stdin
	finds the number of components in that graph,and prints the number of 
	of connected components
*/
int main() {
	Digraph graph;
	graph = read_city_graph_undirected();
	unsigned int connected_comps = count_components(graph);
	cout << connected_comps << endl;
	return 0;
}

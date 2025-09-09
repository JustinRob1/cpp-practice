#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <list>
#include "wdigraph.h"


using namespace std;

// PIL is the value type of our search tree
typedef pair<int, long long> PIL;

// PIPIL is used to insert a key-value pair in our 
// search tree
typedef pair<int, PIL> PIPIL;


/* 
    Description: Computes least cost paths that start from a given vertex. 

    Arguments: graph (const WDigraph&): An instance of the weighted directed graph (WDigraph)
    class

	startVertex (int): A vertex in this graph which serves as the root of the search tree

	tree (unordered_map<int, PIL>&): A search tree to construct the least cost path from startVertex
	to some vertex

    Returns: None

*/

void dijkstra(const WDigraph& graph, int startVertex, unordered_map<int, PIL>& tree) {
    // Priority queue to represent a min heap 
    priority_queue<PIPIL, vector<PIPIL>, greater<PIPIL>> fires;

    // At time 0, the startVertex burns, we set the predecesor 
    // of startVertex to StartVertex (as it is the first vertex)
    fires.push(PIPIL(startVertex, PIL(startVertex, 0)));

    // while there is an active fire
    while (!fires.empty()) {
        // The root node
        auto earliestFire = fires.top();
        
        int v = earliestFire.first;
        int u = earliestFire.second.first;
        long long d = earliestFire.second.second;

        // Remove this fire
        fires.pop();

        // if v is alread burned then theres nothing to do
        if (tree.find(v) != tree.end()) {
            continue;
        }

        // Record that 'v' is burned at time 'd' by a fire startec from 'u'
        tree[v] = PIL(u, d);

        // Now start fires from all edges existing vertex 'v'
        for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
            int nbr = *iter;

            // 'v' catches on fire at time 'd' and the fire will reach 'nbr' at 
            // time d + (length of v->nbr edge)
            long long t_burn = d + graph.getCost(v, nbr);
            fires.push(PIPIL(nbr, PIL(v, t_burn)));
        }
    }
}

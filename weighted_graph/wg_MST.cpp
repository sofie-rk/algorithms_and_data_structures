// MINIMUM SPANNING TREE ALGORITHMS

#include "weighted_graph.h"
#include "queue"

#include <climits>
#include <vector>

using namespace std;

void WeightedGraph::primMST(int src) {

    // Use a priority queue to store vertices 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    // Use a vector to store keys, and initialize all to max
    vector<int> key(V, INT_MAX);

    // Use vector to store parent values
    vector<int> parent(V, -1);

    // Use vector to keep track if vertex is included
    vector<bool> inMST(V, false);

    // Insert src in priority queue, and make its key 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    // Until priority queue is empty
    while (!pq.empty()) {
        int i = 0;
        // CONTINUE HERE
    }   
}
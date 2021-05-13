// MINIMUM SPANNING TREE ALGORITHMS

#include "weighted_graph.h"
#include "queue"

#include <climits>
#include <vector>
#include <iostream>

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
        
        // The first vertex is the minimum key vertex,
        // extract it from the priority queue
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        list<pair<int,int>>::iterator i;

        for (i = adj[u].begin(); i != adj[u].end(); i++) {

            // vertex label v and weight
            int v = (*i).first;
            int weight = (*i).second;

            // if v is not in MST and weight of (u,v) is smaller 
            // than current key of v
            if (inMST[v] == false && key[v] > weight) {
                // Update key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }   

    // Print edges of MST
    for (int i=0; i<V; i++) {
        cout << parent[i] << " " << i << endl;
    }
}
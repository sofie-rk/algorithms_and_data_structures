#include "weighted_graph.h"

#include <list>
#include <iostream>

using namespace std;

WeightedGraph::WeightedGraph(int V) {
    this->V = V;
    adj = new list<pair<int,int>>[V];
}

void WeightedGraph::addEdge(int u, int v, int w) {
    // Add edge from u to v, with weight w
    adj[u].push_back(make_pair(v, w));
}

void WeightedGraph::printGraphInfo() {
    for (int u=0; u<V; u++) {
        cout << "Node " << u << " ->\t";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            cout << it->first << " " << it->second << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
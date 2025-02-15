#include <iostream>
#include <list>

using namespace std;
#include "graph.h"

Graph::Graph(int N) {
	this->N = N;
	adj = new list<int>[N];
}

void Graph::addEdge(int v, int u) {
	adj[v].push_back(u);
}

void Graph::printAdjList() {
	// Print the adjacency list of the graph
	cout << "\n\n*** ADJACENCY LIST OF THE GRAPH ***\n";
	// Go through all vertices in the graph
	for (int v = 0; v<N; ++v) {
		// Print vertex
		cout << v;

		// Go through all neighbors of v
		for (int neighbour : adj[v]) {
			cout << "\t-> " << neighbour;
		}
		cout << "\n";
	}
}

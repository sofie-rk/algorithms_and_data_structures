#include "graph.h"
#include <queue>

void Graph::DFSVisit(int v, bool visited[]) {
	// The current node is marked as visited and printed
	visited[v] = true;
	cout << v << " ";

	// Recursively visit all adjacent vertices of vertex v
	// Iterate through all neighbours in adjacency matrix adj, adj[v]
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i]) {
			// If vertex is not visited, visit
			DFSVisit(*i, visited);
		}
	}
}

void Graph::DFS(int v) {

    // Depth-first search
    cout << "\n\n...DEPTH FIRST SEARCH OF THE GRAPH...\n";

	// Mark all vertcies as not visisted
	bool* visited = new bool[N];
	for (int i=0; i<N; i++) {visited[i] = false;}

	// Recurisvely call DFS-visit
	DFSVisit(v, visited);
}


void Graph::BFS(int v) {

    cout << "\n\n,,,BREADTH-FIRST SEARCH ON THE GRAPH,,,\n";
	
	// Mark all vertices as not visited
	bool* visited = new bool[N];
	for (int i=0; i<N; i++){visited[i]=false;}

	// Create a queue Q
	queue<int> Q;

	// Mark current node as visited, and Q.enqueue(s)
	visited[v] = true;
	Q.push(v);

	// While the queue is not empty:
	while (!Q.empty()) {
		// Print first node in queue, and dequeue it
		v = Q.front();
		cout << v << " ";
		Q.pop();

		// Enqueue all adjacent nodes of node s that is not visited
		// Access neighbours of node s using the adjacency matrix adj[s]
		list<int>::iterator i;
		for (i = adj[v].begin(); i!=adj[v].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				Q.push(*i);
			}
		}
	}
}
#include <iostream>
#include <vector>

using namespace std;

// Add an edge in the undirected graph
void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Print adjacency list
void printGraph(vector<int> adj[], int V) {
	for (int v = 0; v<V; v++) {
		cout << v << "\t";
		for (auto x : adj[v]) {
			cout << "->" << x;
		}
		cout << "\n";
	}
}


//------------------------------------------------------------------------------'


int main()
{
	int V = 5;
	vector<int> adj[V];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 3);

	printGraph(adj, V);
}

// //------------------------------------------------------------------------------

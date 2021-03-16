#include "iostream"
#include "list"

using namespace std;

class Graph {
	int V; 			// Number of vertices
	list<int>* adj; // adjacent list

	void DFSVisit(int v, bool visited[]);

	public:

	Graph(int V);
	void addEdge(int v, int u);

	void DFS(int v);

};

// Construct graph
Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

// Add edge bewteen vertex v and vertex u
void Graph::addEdge(int v, int u) {
	adj[v].push_back(u);
}

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

	// Mark all vertcies as not visisted
	bool* visited = new bool[V];
	for (int i=0; i<V; i++) {visited[i] = false;}

	// Recurisvely call DFS-visit
	DFSVisit(v, visited);
}

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// Create a graph with 10 vertices (from 0 to 9)
	Graph G1(10);

	// Add some edges bewteen the vertices
	// This is graph 1 (attached picture), which is an undirected graph
	G1.addEdge(0,2);
	G1.addEdge(0,4);
	G1.addEdge(0,5);

	G1.addEdge(1,3);
	G1.addEdge(1,6);

	G1.addEdge(2,0);
	G1.addEdge(2,3);
	G1.addEdge(2,6);

	G1.addEdge(3,1);
	G1.addEdge(3,2);
	G1.addEdge(3,5);

	G1.addEdge(4,0);
	G1.addEdge(4,9);

	G1.addEdge(5,0);
	G1.addEdge(5,3);
	G1.addEdge(5,9);

	G1.addEdge(6,1);
	G1.addEdge(6,2);
	G1.addEdge(6,7);

	G1.addEdge(7,6);
	G1.addEdge(7,8);

	G1.addEdge(8,7);
	G1.addEdge(8,9);

	G1.DFS(0);



	// Create a graph with 7 vertices (from 0 to 6)
	Graph G2(7);

	// Add edges bewteen the vertices in G2
	// This is graph 2 (attached picture), which is a directed graph
	G2.addEdge(0,2);
	G2.addEdge(0,3);
	G2.addEdge(0,5);

	G2.addEdge(2,1);

	G2.addEdge(3,1);
	G2.addEdge(3,5);
	
	G2.addEdge(4,0);
	G2.addEdge(4,1);
	G2.addEdge(4,6);

	G2.addEdge(6,1);
	G2.addEdge(6,3);
	G2.addEdge(6,5);

	cout << endl;
	G2.DFS(4);

}

//------------------------------------------------------------------------------

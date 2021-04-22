// FIND NUMBER OF REACHABLE GHOSTS FROM PACKMAN
#include <list>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
	int N;				
	int V; 				// number of nodes
	string charStr;		// string from input
	list<int>* adj; 	// adjacency list
	vector<int> ghostIndex;	// vector with indexes where you can find ghosts
	int packManIndex;	// index where packman is found
	
	public:
	Graph(int N, string charStr);

	void addEdge(int i, int j);

	int searchForReachableGhosts();

};

Graph::Graph(int N, string charStr) {
	this->N = N;
	this->V = N*N;
	this->charStr = charStr;
	adj = new list<int>[V];

	// Go through all nodes of the map (go through string)
    // Check if node is packman or ghost
    // Attach edges between the nodes that are not walls
	for (int i=0; i<N*N; i++) {

		// Check if packman or ghost
		if (charStr.at(i) == 'P') {
				packManIndex = i;
		}
		else if (charStr.at(i) == 'G') {
				ghostIndex.push_back(i);
		}

		
		int r = i/N+1; // row number (zero indexed)

		// Check if you can add edge to the right (do not check right col)
		if (i != (N*r -1)) {
			if (charStr.at(i) != '#' && charStr.at(i+1) != '#') {
				addEdge(i, i+1);
			}
		}
		// Check if you can add edge down (do not check last row)
		if (i < N*N - N) {
			if (charStr.at(i) != '#' && charStr.at(i+N) != '#') {
				addEdge(i, i+N);
			}
		}
	}
}

void Graph::addEdge(int i, int j) {
	adj[i].push_back(j);
	adj[j].push_back(i);
}

int Graph::searchForReachableGhosts() {
	int reachableGhosts = 0;

	// USING BFS TO SEARCH FOR GHOSTS


	// Mark all vertices as not visited
	bool* visited = new bool[V];
	for (int i=0; i<V; i++){visited[i]=false;}

	// Create a queue Q
	list<int> Q;

	// Mark current node as visited, and Q.enqueue(packmanIndex)
	visited[V] = true;
	Q.push_back(packManIndex);

	// While the queue is not empty:
	while (!Q.empty()) {
		int u = Q.front();
		if (charStr.at(u) == 'G') {reachableGhosts++;} // if you found a ghost
		Q.pop_front(); // dequeue

		// Enqueue all adjacent nodes of node u that is not visited
		// Access neighbours of node u using the adjacency matrix adj[s]
		list<int>::iterator i;
		for (i = adj[u].begin(); i!=adj[u].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true; // visit
				Q.push_back(*i); // add to queue
			}
		}
	}

	return reachableGhosts;

}

void codejudgeReachableGhost(){
	// Reading through input
	// First line is the size of the grid
	int N;
	cin >> N;

	string resultStr;

	// Read N lines
	for (int i=0; i<N+1; i++) {
		string line;
		getline(cin, line);
		resultStr += line;
	}

	// Create graph
	Graph G = Graph(N, resultStr);

	cout << G.searchForReachableGhosts();

}
//------------------------------------------------------------------------------'


int main()
{
    codejudgeReachableGhost();
	
}

//------------------------------------------------------------------------------

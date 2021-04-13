#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <climits>


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
	Graph(int V, string charStr);

	void addEdge(int i, int j);

	void printGraphInfo();

	int searchForReachableGhosts();

	string pathToClosestGhost();

};

Graph::Graph(int N, string charStr) {
	this->N = N;
	this->V = N*N;
	this->charStr = charStr;

	adj = new list<int>[V];

	// Go through all

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

void Graph::printGraphInfo() {
	cout << "P is located at: " << packManIndex << endl;
	cout << "G is located at: ";
	for (int i=0; i<ghostIndex.size(); i++) {
		cout << ghostIndex.at(i) << " ";
	}
	cout << endl;

	for (int v=0; v<V; v++) {
		cout << v;
		// Go through all neighbors
		for (int neighbour : adj[v]) {
			cout << "->\t" << neighbour;
		}
		cout << "\n";
	}
	cout << "\n";
}


int Graph::searchForReachableGhosts() {
	int reachableGhosts = 0;

	// USE BFS TO SEARCH FOR GHOSTS
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
		// Print first node in queue, and dequeue it
		int u = Q.front();
		if (charStr.at(u) == 'G') {reachableGhosts++;}
		Q.pop_front();

		// Enqueue all adjacent nodes of node s that is not visited
		// Access neighbours of node s using the adjacency matrix adj[s]
		list<int>::iterator i;
		for (i = adj[u].begin(); i!=adj[u].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				Q.push_back(*i);
			}
		}
	}

	return reachableGhosts;

}

string Graph::pathToClosestGhost() {
	string path = "";

	bool ghostFound = false;
	int ghostFoundIndex = -1;

	// Will store predecessor of each vertex in array p
	int p[V];
	// WIl store distance from source in array d
	int d[V];

	// Using BFS algorithm
	bool* visited = new bool[V];

	// All vertices as not visited
	// Parent is -1, distance is infinity
	for (int i=0; i<V; i++) {
		visited[i]=false;
		d[i] = INT_MAX;
		p[i] = -1;
	}

	// Create a queue Q
	list<int> Q;

	// Mark current node as visited, and Q.enqueue(packmanIndex)
	visited[packManIndex] = true;
	d[packManIndex] = 0;
	Q.push_back(packManIndex);

	// While the queue is not empty:
	while (!Q.empty() && !ghostFound) {
		// Print first node in queue, and dequeue it
		int u = Q.front();
		Q.pop_front();

		// Enqueue all adjacent nodes of node s that is not visited
		// Access neighbours of node s using the adjacency matrix adj[s]
		list<int>::iterator i;
		for (i = adj[u].begin(); i!=adj[u].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				d[*i] = d[u] + 1;
				p[*i] = u;
				Q.push_back(*i);

				if (charStr.at(*i) == 'G') {
					ghostFound = true;
					ghostFoundIndex = *i;
				}
			}
		}
	}

	vector<int> pathVec;
	pathVec.push_back(ghostFoundIndex);
	int crawl = ghostFoundIndex;
	while (p[crawl] != -1) {
		pathVec.push_back(p[crawl]);
		crawl = p[crawl];
	}
	

	for (int i=pathVec.size()-2; i>=0; i--) {
		if (pathVec.at(i)-N == pathVec.at(i+1)) { path += "S ";} 	// SOUTH
		else if (pathVec.at(i)+N == pathVec.at(i+1)) {path += "N ";} // NORTH 
		else if (pathVec.at(i)+1 == pathVec.at(i+1)) {path += "W ";} // WEST
		else if (pathVec.at(i)-1 == pathVec.at(i+1)) {path += "E ";} // EAST
	}

	return path;
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

void codejudgeClosestGhost() {
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

	cout << G.pathToClosestGhost();
}


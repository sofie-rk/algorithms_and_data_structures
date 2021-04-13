
#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

class Graph
{
	int V; 			// number of nodes
	string charStr;
	list<int>* adj; // adjacency list
	vector<int> ghostIndex;	// vector with indexes where you can find ghosts
	int packManIndex;	// index where packman is found
	
	public:
	Graph(int V, string charStr);

	void addEdge(int i, int j);

	void printGraphInfo();

	void updatePackMan();

	void addGhost(int i);

	int searchForReachableGhosts();
	


};

Graph::Graph(int N, string charStr) {
	this->V = N*N;
	this->charStr = charStr;

	adj = new list<int>[V];

	// Read first N-1 characters
	int r = 0;
	for (int i=0; i<N*N-N; i++) {
		r = i/8+1;
		if (i == (N*r - 1)) {
			// Only check down
			if (charStr.at(i) != '#' && charStr.at(i+8) != '#') {
				addEdge(i, i+8);
			}
		} else {
			// Check the other
			if (charStr.at(i) != '#') {
				// Check if you can go to the right or down
				if (charStr.at(i+1) != '#') {
					addEdge(i,i+1);
				}
				if (charStr.at(i+8) != '#') {
					addEdge(i,i+8);
				}
			}
		if (charStr.at(i) == 'P') {
			packManIndex = i;
		}
		else if (charStr.at(i) == 'G') {
			ghostIndex.push_back(i);
		}
		
	}

	}

	// Read last N nodes
	for (int i=N*N-N; i<N*N-1; i++) {
		// Check if possible to go to the right
		if (charStr.at(i) != '#' && charStr.at(i+1) != '#') {
			addEdge(i, i+1);
		}
	}

	// 
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













//------------------------------------------------------------------------------'

int main()
{
	//cout << countGhosts();

	// Reading through input
	// First line is the size of the grid
	// int N;
	// cin >> N;

	// string resultStr;

	// // Read N lines
	// for (int i=0; i<N+1; i++) {
	// 	string line;
	// 	getline(cin, line);
	// 	resultStr += line;
	// }

	int N = 8;
	string resultStr = "######### #    ## # ## ## #  #G##   P####### # ##G   #G#########";

	Graph G = Graph(N, resultStr);

	G.printGraphInfo();


}

//------------------------------------------------------------------------------

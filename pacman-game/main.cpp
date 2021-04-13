
#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

class Graph
{
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

};

Graph::Graph(int N, string charStr) {
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
		packManIndex = Q.front();
		if (charStr.at(packManIndex) == 'G') {reachableGhosts++;}
		Q.pop_front();

		// Enqueue all adjacent nodes of node s that is not visited
		// Access neighbours of node s using the adjacency matrix adj[s]
		list<int>::iterator i;
		for (i = adj[packManIndex].begin(); i!=adj[packManIndex].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				Q.push_back(*i);
			}
		}
	}

	return reachableGhosts;

}


void codejudgeTest(){
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
	//cout << countGhosts();

	
	codejudgeTest();

	// int N = 8;
	// string resultStr = "######### #    ## # ## ## #  #G##   P####### # ##G   #G#########";

	// Graph G = Graph(N, resultStr);

	// cout << "Reachable ghosts: " << G.searchForReachableGhosts() << endl;

	// cout << "TESTING NEXT MAP: " << endl;
	// int N2 = 8;
	// string resultStr2 = "#########G#    ## ####G##  G  P##### G ##G #   ## G# G #########";

	// Graph G2 = Graph(N2, resultStr2);

	// cout << "Reachable ghosys: " << G2.searchForReachableGhosts() << endl;

	// G2.printGraphInfo();

	// int N3 = 7;

	// string resultString3 = "########G    ###### ##     ## ######     P#######";

	// Graph G3 = Graph(N3, resultString3);

	// G3.printGraphInfo();

	// cout << G3.searchForReachableGhosts();

}

//------------------------------------------------------------------------------

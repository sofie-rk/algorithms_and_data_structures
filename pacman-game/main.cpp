
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class GraphMultiPlayer
{
	int N;				
	int V; 				// number of nodes
	string charStr;		// string from input
	list<int>* adj; 	// adjacency list
	vector<int> ghostIndex;	// vector with indexes where you can find ghosts
	vector<int> packManIndex;	// vector with indexes where you can find packman
	
	public:
	GraphMultiPlayer(int V, string charStr);

	void addEdge(int i, int j);

	void printGraphMultiPlayerInfo();

	int closestPath();

};

GraphMultiPlayer::GraphMultiPlayer(int N, string charStr) {
	this->N = N;
	this->V = N*N;
	this->charStr = charStr;

	adj = new list<int>[V];

	// Go through all

	for (int i=0; i<N*N; i++) {

		// Check if packman or ghost
		if (charStr.at(i) == 'P') {
				packManIndex.push_back(i);
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



void GraphMultiPlayer::addEdge(int i, int j) {
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void GraphMultiPlayer::printGraphMultiPlayerInfo() {
	cout << "P is located at: ";
	for (int i=0; i<packManIndex.size(); i++) {
		cout << packManIndex.at(i) << " ";
	}
	cout << endl;
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

int GraphMultiPlayer::closestPath() {

	set<int> distances;
	distances.insert(INT_MAX);

	// If less packmans than ghosts, iterate through packmans
	if (packManIndex.size() < ghostIndex.size()) {
		for (auto packMan:packManIndex) {
			if(*distances.begin() > 1){
			bool ghostFound = false;

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
			visited[packMan] = true;
			d[packMan] = 0;
			Q.push_back(packMan);

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
							distances.insert(d[*i]);
						}
					}
				}
			}
		}
		}
	} else { //less ghosts than packmans
		for (auto ghost : ghostIndex) {
			if(*distances.begin() > 1){
			bool packManFound = false;

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
			visited[ghost] = true;
			d[ghost] = 0;
			Q.push_back(ghost);

			while (!Q.empty() && !packManFound) {
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

						if (charStr.at(*i) == 'P') {
							packManFound = true;
							distances.insert(d[*i]);
						}
					}
				}
			}
		}
		}
	}


	return *distances.begin();
}

void testMultiplayerInput() {

	int N = 8;

	string resStr = "#########P#   P## # ## ## #  #G##   P####### # ##G   #G#########";

	GraphMultiPlayer G = GraphMultiPlayer(N, resStr);

	cout << G.closestPath();

}

void codejudgeMultiPlayer() {
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
	GraphMultiPlayer G = GraphMultiPlayer(N, resultStr);

	cout << G.closestPath();
}



//------------------------------------------------------------------------------'

int main()
{

	codejudgeMultiPlayer();

	//testMultiplayerInput();
	//codejudgeClosestGhost();
	//cout << countGhosts();
	// codejudgeReachableGhost();

	// int N = 8;
	// string resultStr = "######### #    ## # ## ## #  #G##   P####### # ##G   #G#########";

	// GraphMultiPlayer G = GraphMultiPlayer(N, resultStr);

	// string path = G.closestPath();

	// cout << path;

	// cout << "Reachable ghosts: " << G.searchForReachableGhosts() << endl;

	// cout << "TESTING NEXT MAP: " << endl;
	// int N2 = 8;
	// string resultStr2 = "#########G#    ## ####G##  G  P##### G ##G #   ## G# G #########";

	// GraphMultiPlayer G2 = GraphMultiPlayer(N2, resultStr2);

	// string path2 = G2.closestPath();
	// cout << path2;

	// cout << "Reachable ghosys: " << G2.searchForReachableGhosts() << endl;

	// G2.printGraphMultiPlayerInfo();

	// int N3 = 7;

	// string resultString3 = "########G    ###### ##     ## ######    P########";

	// GraphMultiPlayer G3 = GraphMultiPlayer(N3, resultString3);

	// cout << G3.closestPath();

	// G3.printGraphMultiPlayerInfo();

	// cout << G3.searchForReachableGhosts();

}

//------------------------------------------------------------------------------

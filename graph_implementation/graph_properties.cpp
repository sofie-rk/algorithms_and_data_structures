#include "graph.h"

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool Graph::isBipartite() {

    // Assign vertices into set "1" and set "2"
    // If vertex is not assigned, it is marked as "-1"

    vector<int> setV(N, -1); 

    // BFS
    queue<pair<int,int>> Q; // storing vertex, set number
    

    for (int i = 0; i<N; i++) {
        if (setV[i] == -1) {
            // Put into set 1
            Q.push({i, 1});
            setV[i] = 1;

            while (!Q.empty()) {
                pair<int, int> p = Q.front();
                Q.pop();

                int currentVertex = p.first;
                int currentSet = p.second;

                for (int j : adj[currentVertex]) {
                    // If neighbour is in same set as currentVertex, 
                    // bipartite graph is not possible
                    if (setV[j] == currentSet) {
                        cout << "Graph is not bipartite.\n";
                        return false;
                    }
                    if (setV[j] == -1) {
                        // Put into opposite set
                        if (currentSet == 1){setV[j] = 2;}
                        else {setV[j] = 1;}
                        Q.push({j, setV[j]});
                    }
                }
            }
        }
    }
    cout << "Graph is bipartite.\n";
    return true;
}
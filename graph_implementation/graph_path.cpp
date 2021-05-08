#include "graph.h"

#include <iostream>
#include <list>
using namespace std;





void Graph::connectedComponents() {

    cout << "\n--- CONNECTED COMPONENTS IN THIS GRAPH ---\n";

    // Mark all nodes as not visited
    bool* visited = new bool[N];
    for (int i=0; i<N; i++) {visited[i] = false;}

    // Use DFS search to visit all possible nodes from v
    for (int v=0; v<N; v++) {
        if (visited[v] == false) {
            DFSVisit(v, visited);
            cout << "\n";
        }

        // if visited[v] == true, go through next node
        // if visited, it is already in the connected component
        // if not visisted, start DFS search to find the connected components
    }

}
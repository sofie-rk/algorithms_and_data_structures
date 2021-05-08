#include <iostream>
#include <list>

using namespace std;
#include "graph.h"

bool Graph::isCyclic() {
    // Using DFS-algorithm to detect cycle
    // Visits all adjacent vertices of the current node
    // If adjacent vertex is already visited and is not the 
    // parent of the current vertex, there is a cycle


    // Mark all vertices as not visited
    bool* visited = new bool[N];
    for (int i=0; i<N; i++) {visited[i]=false;}
    // Mark all vertcies as not parent
    bool* parentStack = new bool[N];
    for (int i=0; i<N; i++) {parentStack[i]=false;}

    
    // Start from first node, and recursively
    // call helper function
    for (int v=0; v<N; v++) {
        // If vertex is not visited, visit
        if (!visited[v]) {
            if (isCyclicVisit(v, visited, parentStack)) {
                return true;
            }
        }
    }
    return false;
}

bool Graph::isCyclicVisit(int v, bool visited[], bool *parentStack) {
   
   if (visited[v] == false) {
        // The current node is marked as visited
        visited[v] = true;
        // Current node is marked as part of parent stack
        parentStack[v] = true;

        // Recursively visit all adjacent vertices of vertex v
	    // Iterate through all neighbours in adjacency matrix adj, adj[v]
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        
            // If vertex is not visited, visit
            if (!visited[*i]) {
                if (isCyclicVisit(*i, visited, parentStack)) {
                    return true;
                }
            }
            // If an adjacent vertex already is visited, and is
            // not parent of the current vertex, a cycle is detected
            else if (parentStack[*i]) {
                return true;
            }
        }  
   }
   // Remove vertex from parent stack
   parentStack[v] = false;
 
    return false;
}


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
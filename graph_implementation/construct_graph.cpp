#include "construct_graph.h"
#include "graph.h"

void testGraph1() {
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

	G1.addEdge(9,4);
	G1.addEdge(9,5);
	G1.addEdge(9,8);

	// Printing the adjacency matrix of graph G1
	G1.printAdjList();
	G1.DFS(0);
	G1.BFS(0);
	if (G1.isCyclic()){cout << "\nG1 is cyclic\n";}
	else {cout << "\nG1 is not cyclic\n";}
	
}

void searchIllustration() {

    cout << "\n\nSEARCH ILLUSTRATIONS\n"; 
    Graph G = Graph(7);

    G.addEdge(0,1);
    G.addEdge(1,0);
    G.addEdge(0,2);
    G.addEdge(2,0);

    G.addEdge(1,3);
    G.addEdge(3,1);
    G.addEdge(1,4);
    G.addEdge(4,1);
    G.addEdge(1,6);
    G.addEdge(6,1);

    G.addEdge(2,6);
    G.addEdge(6,2);

    G.addEdge(3,5);
    G.addEdge(5,3);

    G.printAdjList();

    G.DFS(0);
    G.BFS(0);

}
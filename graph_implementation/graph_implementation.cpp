#include "graph.h"

//------------------------------------------------------------------------------'


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

	G1.addEdge(9,4);
	G1.addEdge(9,5);
	G1.addEdge(9,8);

	// Printing the adjacency matrix of graph G1
	G1.printAdjList();
	G1.DFS(0);
	G1.BFS(0);
	if (G1.isCyclic()){cout << "\nG1 is cyclic\n";}
	else {cout << "\nG1 is not cyclic\n";}
	
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

	cout << "\n\n";
	G2.printAdjList();
	G2.DFS(4);
	G2.BFS(4);
	if (G2.isCyclic()){cout << "\nG2 is cyclic\n";}
	else {cout << "\nG2 is not cyclic\n";}

	Graph G3(6);
	G3.addEdge(0,1);
	G3.addEdge(0,3);
	G3.addEdge(1,2);
	G3.addEdge(2,5);
	G3.addEdge(3,4);
	G3.addEdge(4,5);

	cout << "\n\n";
	G3.printAdjList();
	if (G3.isCyclic()){cout << "\nG3 is cyclic\n";}
	else {cout << "\nG3 is not cyclic\n";}
	

	Graph G4(5);
	G4.addEdge(0,3);
	G4.addEdge(3,0);
	G4.addEdge(1,2);
	G4.addEdge(2,4);
	G4.addEdge(4,1);


	cout << "\n\n";
	G4.printAdjList();
	if (G4.isCyclic()){cout << "\nG4 is cyclic\n";}
	else {cout << "\nG4 is not cyclic\n";}
	G4.connectedComponents();

	
}

// //------------------------------------------------------------------------------

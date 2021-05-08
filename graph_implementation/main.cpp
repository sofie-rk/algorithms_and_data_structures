#include "graph.h"
#include "construct_graph.h"

//------------------------------------------------------------------------------'


int main()
{

	testGraph1();

	searchIllustration();

	bipartiteCheck();

	cyclicCheck();
	
	
	// cout << "\n\n";
	// G2.printAdjList();
	// G2.DFS(4);
	// G2.BFS(4);
	// if (G2.isCyclic()){cout << "\nG2 is cyclic\n";}
	// else {cout << "\nG2 is not cyclic\n";}

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

#include "graph.h"
#include "construct_graph.h"

//------------------------------------------------------------------------------'


int main()
{

	testGraph1();

	searchIllustration();

	bipartiteCheck();

	cyclicCheck();
	
	connectedComponentsCheck();


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
	
	
}

// //------------------------------------------------------------------------------

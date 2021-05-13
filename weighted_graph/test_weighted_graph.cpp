#include "weighted_graph.h"

void testWeightedGraph1() {
    // Creating graph in picture WG1_1
	WeightedGraph WG1 = WeightedGraph(8);

	WG1.addEdge(0,1,6);
	WG1.addEdge(1,0,6);
	WG1.addEdge(0,2,8);
	WG1.addEdge(2,0,8);
	WG1.addEdge(0,3,2);
	WG1.addEdge(3,0,2);

	WG1.addEdge(1,2,3);
	WG1.addEdge(2,1,3);
	WG1.addEdge(1,4,4);
	WG1.addEdge(4,1,4);

	WG1.addEdge(2,3,4);
	WG1.addEdge(3,2,4);
	WG1.addEdge(2,4,2);
	WG1.addEdge(4,2,2);
	WG1.addEdge(2,5,6);
	WG1.addEdge(5,2,6);

	WG1.addEdge(3,6,7);
	WG1.addEdge(6,3,7);

	WG1.addEdge(4,5,1);
	WG1.addEdge(5,4,1);
	WG1.addEdge(4,7,1);
	WG1.addEdge(7,4,1);

	WG1.addEdge(5,6,2);
	WG1.addEdge(6,5,2);
	WG1.addEdge(5,7,7);
	WG1.addEdge(7,5,7);

	WG1.addEdge(6,7,5);
	WG1.addEdge(7,6,5);

	WG1.printGraphInfo();

    WG1.primMST(0);

}
#pragma once

#include <iostream>
#include <list>

using namespace std;

class Graph {
	int V;			// number of vertices in the graph
	list<int>*adj;	// adjacency list

	public:
	Graph(int V);
	
	// Utility functions for the graph
	void addEdge(int v, int u);
	void printAdjList();

	// Depth-first and breadth-first search algorithms
	void DFSVisit(int v, bool visited[]);
	void DFS(int v);
	void BFS(int v);

	// Path and cycle algorithms
	bool isCyclicVisit(int v, bool visited[], bool* parentStack);
	bool isCyclic();

	void connectedComponents();



};

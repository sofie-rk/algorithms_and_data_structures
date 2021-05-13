#pragma once
#include <list>

using namespace std;

class WeightedGraph
{
    int V;  // number of vertices in the graph

    // Using list of pairs for the adjacency list
    list<pair<int,int>>* adj;

    public:
    WeightedGraph(int V);

    void addEdge(int u, int v, int w);

    void printGraphInfo();

    // Minimum spanning tree algorithms
    void primMST(int src);
    void kruskalMST(int src);

};

void testWeightedGraph1();
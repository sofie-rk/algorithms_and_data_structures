#pragma once
#include <vector>

using namespace std;

class WeightedGraph
{
    int V;  // number of vertices in the graph

    // Using vector of pair vectors
    vector<pair<int,int>>* adj;

    public:
    WeightedGraph(int V);

    void addEdge(int u, int v, int w);

    void printGraphInfo();

};
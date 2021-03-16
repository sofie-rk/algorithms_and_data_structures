**Depth first search**

Depth first search is an algorithm for systematically visiting all vertices and edges in a graph. The nodes are visited "depth-wise".

Start at a root node. Visit adjacent vertex v. Mark v, and visit all unmarked neighbours of v recursively. Go back to previous vertex when all adjacent vertices are visited.

STL's list container is used to store lists of adjacent nodes in the C++ code.

The algorithm is used on the undirected graph in picture graph1.png, and on the directed graph in picture graph2.png.

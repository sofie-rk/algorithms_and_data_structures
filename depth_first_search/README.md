**Depth first search**
Depth first search in an algorithm for systematically visiting all vertices and edges in a graph. The nodes are visited "depth-wise".

Start in one node, and then visit the adjacent nodes of the current node.
Once a node with no more adjacent nodes is reach, DFS goes back to a node with adjacent nodes until all nodes are visited.

Start at a root node. Visit adjacent vertex v. Mark v, and visit all unmarked neighbours of v recursively. Go back to previous vertex when all adjacent vertices are visited.

STL's list container is used to store lists of adjacent nodes.

**Breadth-first search**
Breadth-first search is an algorithm used to visit all vertices of a graph.

BFS finds the length of the shortest path from s to all other vertices.

Each vertex in the graph is either visited or not visited.

The algorithm:
1) Unmark all vertices and initialize queue Q.
2) Mark root node s and add it to the queue, Q.Enqueue(s)
3) While Q is not empty:

     v = Q.Dequeue. 
     
     For each unmarked neighbor u of v mark u, and Q.Enqueue(u).


STL's list container is used to store lists of adjacent nodes in the C++ code.

The algorithm is used on the undirected graph in picture graph1.png, and on the directed graph in picture graph2.png
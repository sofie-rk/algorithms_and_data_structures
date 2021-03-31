**Graph**
V = set of verices.
E = set of edges. 
Each edge is connecting a pair of vertices.
Let n = number of vertices, and m = number of edges.

A graph is defined as a set of vertices V and a set of edges E. G = (V,E). A graph have n vertices and m edges.

A graph can be represented using adjacency matrix or adjacency list. 

**Adjacency matrix**
The adjacency matrix is a 2D VxV array adj, where V is the number of vertices in a graph.
adj[i][j] = 1 if i and j are neighbors. adj[i][j] = 0 otherwise.
The adjacency matrix consumes O(V^2) space.

**Adjacency list**
The adjacency list is an array of lists, A[0...n-1].
A[i] is a linked list of all neighbors of i.
The adjacency list consumes O(n+m) space. (n is number of vertices, m is the number of edges).

**Undirected graph**
Set of vertices pairwise joind by edges. Image graph1.png is an undirected graph.
![graph1](Illustrations_graph/graph1.png)


**Directed graph**
Set of vertices pairwise joined by directed edges.
Image graph2.png is a directed graph.
![graph2](Illustrations_graph/graph2.png)

**Path**
Sequence of vertices connected by edges.

**Cycle**
Path starting and ending at the same vertex.

**Depth-first search (DFS)**
Systematically visits all vertices  in a graph.

**Breadth-first search (BFS)**
Systematically visits all vertices in a graph. BFS finds the shortest path from s to all other vertices.

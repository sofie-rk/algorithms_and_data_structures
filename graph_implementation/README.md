# Graph
V = set of verices.
E = set of edges. 
Each edge is connecting a pair of vertices.
Let N = number of vertices, and M = number of edges.
A graph is defined as a set of vertices V and a set of edges E. G = (V,E). 

A graph can be represented using adjacency matrix or adjacency list. 

## Adjacency matrix
The adjacency matrix is a 2D NxN array adj, where N is the number of vertices in a graph.
adj[i][j] = 1 if i and j are neighbors. adj[i][j] = 0 otherwise.
The adjacency matrix consumes O(N^2) space.

## Adjacency list
The adjacency list is an array of lists, A[0...n-1].
A[i] is a linked list of all neighbors of i.
The adjacency list consumes O(N+M) space. (n is number of vertices, m is the number of edges).

## Undirected graph
Set of vertices pairwise joind by edges.
![graph1](Illustrations_graph/graph1.png)


## Directed graph
Set of vertices pairwise joined by directed edges.
![graph2](Illustrations_graph/graph2.png)

## Path
Sequence of vertices connected by edges.

## Cycle
Path starting and ending at the same vertex.

## Depth-first search (DFS)
Systematically visits all vertices  in a graph. The nodes are visited "depth-wise".

Start at a root node. Visit adjacent vertex v. Mark v, and visit all unmarked neighbours of v recursively. Go back to previous vertex when all adjacent vertices are visited.


![DFS_illustration](Illustrations_graph/DFS_illustration.jpg)

With adjacency list representation, the running time is O(N+M). All N nodes are visited. All neighbors of N are visited, in so all edges are traversed (M).

Space Complexity: O(N) (extra array to store visisted vertices is needed).
## Breadth-first search (BFS)
Systematically visits all vertices in a graph. BFS finds the shortest path from s to all other vertices. The vertices are visited "Breadth-wise".

The algorithm:

Each vertex in the graph is either visited or not visited.
1. Unmark all vertices and initialize queue Q.
2. Mark root node s as visited and add it to the queue (Q.ENQUEUE()).
3. While Q is not empty:
    v = Q.DEQUEUE()
    
    For each unmarked neighbour u of v: mark u and Q.ENQUEUE(u)

![BFS_illustration](Illustrations_graph/BFS_illustration.jpg)

With adjacency list representation, the running time is O(N+M). All N nodes are visited. All neighbors of N are visisted, so all M edges must be traversed.
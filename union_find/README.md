# Union Find

## Union find

Maintain a dynamic family of sets supporting the following operations:

INIT(n): constructs sets {0}, {1}, ... , {n-1}

UNION(i, j): forms the union of the two sets that contain i and j. 

FIND(i): return a representative for the set that contains i.

## Quick Find
Maintain an array id[0, ... , n-1] such that id[i] = representative for i.

INIT(n): initialize array. Each element is its own representative. Time O(n).

UNION(i, j): if FIND(i) != FIND(j), update representative for all elements in one of the sets. Time O(n).

FIND(i): return representative. Time O(1).

## Quick Union
Maintain each sets as a rooted tree. Trees are stored as arrays p[0, ... , n-1] such that p[i] is the parent of i, and p[root] = root. The representative is the root of the the tree.

INIT(n): create n trees with one element each. Time O(n).

UNION(i,j): if FIND(i) != FIND(j), make the root of one tree the child of the root of the other tree. Time O(d) (d is depth of the tree).

FIND(i): follow path to the root, and return root. Time O(d) (d is depth of the tree).

Problem with Quick Union is that the depth of tree might bee d=n-1.

## Weighted Quick Union
Weighted quick union is an extension of quick union. The depth of Weighted Quick Union is at most log(n), which is better than regular Quick Union.

In Weighted Quick Union, you maintain an extra array size[0, ... , n-1] which contains the size of the subtree rooted at i.

INIT(n): create n trees with one element each. Initialize size[0, ... , n-1].

UNION(i,j): if FIND(i)!=FIND(j), make the root of the *smaller* tree the childe of the root of the *larger* tree. Time O(log(n)).

FIND(i): follow path to the root, then return root. Time O(log(n)).

## Path Compression
When doing the FIND(i) operation, compress the path. Make all nodes on the path children of the root.

This will give no change in running time for a single FIND(i). However, FIND(i) will become faster since the depth of the tree will become smaller.

This works on both quick union and weighted quick union.
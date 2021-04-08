# Union Find

## Union find

Maintain a dynamic family of sets supporting the following operations:

INIT(n): constructs sets {0}, {1}, ... , {n-1}

UNION(i, j): forms the union of the two sets that contain i and j. 

FIND(i): return a representative for the set that contains i.

## Quick find
Maintain an array id[0, ... , n-1] such that id[i] = representative for i.

INIT(n): initialize array. Each element is its own representative. Time O(n).

UNION(i, j): if FIND(i) != FIND(j), update representative for all elements in one of the sets. Time O(n).

FIND(i): return representative. Time O(1).

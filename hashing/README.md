# Hashing

## Dictionaries
Each element x in set S has a key x.key from a universe U and a satellite data x.data.

SEARCH(k): determine if element with key k exist. If so, return it.

INSERT(x): add x to S (assuming that x is not already in S)

DELETE(x): remove x from S.

## Dictionary using linked list
Maintain (keys of) S in a linked list.

Space: O(n).

SEARCH(k): linear search for key k. O(n).

INSERT(x): insert x in the front of the list. O(1).

DELETE(x): remove x from the list. O(1).

## Dictionary using direct accessing
Maintain S in an array A of size U (size of universe). Stor element x at A[x.key]. 

Space: O(U).

SEARCH(k): return A[x.key]. O(1).

INSERT(x): set A[x.key] = x. O(1).

DELETE(x): set A[x.key] = null. O(1).

## Chained hashing
Use a **hash function** h. The hash function should spread the keys from S approximately evenly. Example: h(k) = k%11, will spread out keys on elements 0, 1, ..., 10.


Maintain array A[0, ... , m-1] of linked list. Store element x in linked list at A[h(x.key)].

Space: O(n).

SEARCH(k): linear seacrh in A[h(k)] for key k. O(1) (expected time using simple uniform hashing).

INSERT(x): insert x in front of list A[h(x.key)]. O(1).

DELETE(x): remove x from list A[h(x.key)]. O(1).

## Linear probing
Maintain S in array A of size m. Element x is stores in A[h(x.key)] *or* in cluster to the right of A[h(x.key)].

A cluster is a sequence of non-empty entries.

Space: O(n).


SEARCH(k): linear search from A[k] in cluster to the right of A[k].

INSERT(x): insert x on A[h(x.key)]. If non-empty, insert on next empty entry to the right of x (cyclically).

DELETE(x): remove x from A[h(x.key)]. Re-insert all elements to the right of x in the cluster.




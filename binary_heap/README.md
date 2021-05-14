# Binary tree

A binary tree is a rooted tree. All levels in the tree are completely filled (each node has two children) except the last level which may not be completely filled. In the last layer, all keys are as left as possible.

Each node in a heap store v.key, v.parent, v.left, v.right

In a **max heap**, the root node must be the maximum among all keys. For all nodes v, all keys in left subtree and right subtree must be less than or equal to v.key. An example is given below. In a **min heap**, the root node must be the minimum among all keys. For all nodes v, all keys in left subtree and right subtree must be bigger than or equal to v.key.

![heap1](heap1.png)



## Operations in a binary heap

PARENT(x): return parent of x

LEFT(x): return left child of x

RIGHT(x): return right child of x

MAX(): return element with the largest key

EXTRACTMAX(): return and remove the element with the largest key

INCREASEKEY(x, k): set x.key = k (assume k>=x.key)

INSERT(x): insert key into heap at correct position

## Representation of a binary heap

Binary heap can be as an array H[0 ... n]. H[0] is unused. H[1 ... n] stores nodes in level order.

PARENT(x): return x/2

LEFT(x): return 2*x

RIGHT(x): return 2*x+1

For the image above, array H is: H = [-, 16, 13, 11, 7, 5, 9, 1, 4]


## Binary heap as a priority queue
insertKey(x), deleteKey(x), extractMax(), increaseKey(i,k) are operations in O(log(n)) time.

## Heapsort

Heaps can be used to sort an array H[1 ... n]. 

1. Build a max heap for H.

2. Apply n EXTRACTMAX() on the heap. Replace the returned element at the end of the array, and reduce size of heap by 1.

3. Return H

Time complexity:

Constructing the heap: O(n).

n EXTRACTMAX in O(n log(n)) time.

Total time: O(n log(n))


## Merge k sorted arrays using a heap

Given k sorted arrays (from high to low) of size n each, merge them using a max heap, and print the sorted output.

1. Create a max Heap, and insert the first element of all k arrays. O(k).

2. Run until the size of max Heap is greater than zeors.

3. Use EXTRACTMAX to remove the top element of the max Heap.  O(log(k))

4. Insert the next element for the same array in which the removed element belonged. If array is empty, replace root with infinite. After replacing the root, heapify the tree.

n elements in each array. Total running time: O(n log(k)).


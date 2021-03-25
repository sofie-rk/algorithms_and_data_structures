#include "binary_heap.h"

// Insert a key
void MaxHeap::insertKey(int k) {
	if (numberOfElements == capacity) {
		cout << "\nOverflow: Maximum capacity is reached, could not insert key\n";
		return;
	}

	// Increase the amount of elements in the heap
	numberOfElements++;

	int i = numberOfElements;
	H[i] = k;

	// If heap order is violated, fix it with bubbleUp-algorithm
	bubbleUp(i);
}

void MaxHeap::deleteKey(int i) {
	// Increases value to infinite, then uses extractMax()
	// to remove it

	increaseKey(i, INT_MAX);
	extractMax();

}


int MaxHeap::extractMax() {
	// Assume that the heap is not empty

	// Store max value
	int r = H[1];

    // Change H[1] to be the last node
    H[1] = H[numberOfElements];

    // Decrease number of elements
    --numberOfElements;

    // Order heap from node 1 and down
    bubbleDown(1);

    return r;

} 


void MaxHeap::increaseKey(int i, int k) {
	// Increase at index i to value k
	// Assuming that k >= H[x]

	// Assign new value to key x
	H[i] = k;

	// If the heap order now is violated, fix it using bubbleup
    bubbleUp(i);
}

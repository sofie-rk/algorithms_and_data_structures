#include "binary_heap.h"
#include "utility.h"


// Constructor
MaxHeap::MaxHeap(int givenCapacity) {
	// Initialize variables
	H = new int[givenCapacity];
	capacity = givenCapacity;
	numberOfElements = 0;

	// Now, the heap is initialized (and empty)
}

// Print array H which represents heap
void MaxHeap::printArrayRep() {
	
	//cout << "\nPRINTING HEAP ARRAY\n";
    cout << endl;
	for (int i=0; i<numberOfElements+1; i++) {
		cout << H[i] << " ";
	}

	cout << endl;
}

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
	// It is assumes that k >= H[x]

	// Assign new value to key x
	H[i] = k;

	// If the heap order now is violated, fix it using bubbleup
    bubbleUp(i);
}

void MaxHeap::bubbleUp(int i) {
    // If heap order is violated at node i because key
    // is larger than parent key

    while (i != 1 && H[i] > H[parent(i)]) {
        // swap node i and parent node
        swap(&H[i], &H[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::bubbleDown(int i) {
    // If heap order is violated at node i because key
    // is smaller that the key at left or right child

    // Assumes that the subtrees are in correct order
    
    // Find index of max child
    int maxChild = maxOfChild(H[left(i)], H[right(i)], i);

    while (H[maxChild] > H[i] && left(i)<=numberOfElements && right(i)<=numberOfElements) {
        swap(&H[i], &H[maxChild]);
        i = maxChild;

        maxChild = maxOfChild(H[left(i)], H[right(i)], i);

    }




}

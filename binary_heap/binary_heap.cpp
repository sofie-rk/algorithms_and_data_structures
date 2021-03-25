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




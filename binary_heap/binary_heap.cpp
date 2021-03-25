#include <iostream>

using namespace std;

//------------------------------------------------------------------------------'


// Utility function
// Swaps two elements
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MaxHeap 
{
	int *H; // array of elements in heap
	int capacity; // maximum possible size of heap
	int numberOfElements; // number of elements in heap

	public:

	MaxHeap(int capacity);

	void printArrayRep();

	void insertKey(int k);

	int parent(int i) {return (i)/2;} // round up
	int left(int i) {return 2*i;}
	int right(int i) {return 2*i + 1;}

};

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
	
	cout << "\nPRINTING HEAP ARRAY\n";
	for (int i=0; i<numberOfElements+1; i++) {
		cout << H[i] << " ";
	}
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

	// If heap order is violated, fix it
	while (i != 1 && H[i] > H[parent(i)]) {
		// As long as H[i] is smaller than its parent, the heap order is violated
		swap(&H[i], &H[parent(i)]);
		i = parent(i);
	}

	
}


int main()
{
	MaxHeap H(20);
	
	// Insert keys to the heap
	H.insertKey(16);
	H.insertKey(4);
	H.insertKey(11);
	H.insertKey(7);
	H.insertKey(5);
	H.insertKey(9);
	H.insertKey(1);
	H.insertKey(13);

	H.printArrayRep();

}

//------------------------------------------------------------------------------

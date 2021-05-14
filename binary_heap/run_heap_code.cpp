#include "binary_heap.h"

#include <iostream>
using namespace std;

void testHeapOperations() {

    MaxHeap H(20);
	
	// Insert keys to the heap
	cout << "\nInserting keys:";
	H.insertKey(16);
	H.insertKey(4);
	H.insertKey(11);
	H.insertKey(7);
	H.insertKey(5);
	H.insertKey(9);
	H.insertKey(1);
	H.insertKey(13);

	H.printArrayRep();

	cout << "\nIncrease key at node 6 to 40";
	H.increaseKey(6, 40);
	H.printArrayRep();

	cout << "\nmax()";
	cout << "\nMax: " << H.max() << endl;

	cout << "\nextractMax()";
	H.extractMax();
	H.printArrayRep();

	cout << "\nDelete node 2";
	H.deleteKey(2);
	H.printArrayRep();

}


void testHeapSort() {

    int A[] = {12, 11, 13, 5, 9, 10, 22, 4};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "\nArray to be sorted:\n";
    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    heapSort(A, n);

    cout << "Sorted array:\n";
    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }

}
#include <iostream>


using namespace std;

#include "binary_heap.h"


//------------------------------------------------------------------------------'





int main()
{
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

//------------------------------------------------------------------------------

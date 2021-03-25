#pragma once

#include <iostream>
using namespace std;


class MaxHeap 
{
	int *H; // array of elements in heap
	int capacity; // maximum possible size of heap
	int numberOfElements; // number of elements in heap

	public:

	MaxHeap(int capacity);

	void printArrayRep();

	void insertKey(int k);

	int parent(int i) {return (i)/2;} // round down
	int left(int i) {return 2*i;}
	int right(int i) {return 2*i + 1;}

	int max() {return H[1];}
	int extractMax();

	void increaseKey(int i, int k);

    void bubbleUp(int i);
    void bubbleDown(int i);
};


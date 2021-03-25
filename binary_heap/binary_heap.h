#pragma once

#include <iostream>
#include <climits>
using namespace std;


class MaxHeap 
{
	int *H; // array of elements in heap
	int capacity; // maximum possible size of heap
	int numberOfElements; // number of elements in heap

	public:

	MaxHeap(int capacity);

	void printArrayRep();

	int parent(int i) {return (i)/2;} // round down
	int left(int i) {return 2*i;}
	int right(int i) {return 2*i + 1;}

	void bubbleUp(int i);
    void bubbleDown(int i);

	void insertKey(int k);
	void deleteKey(int i);
	int max() {return H[1];}
	int extractMax();
	void increaseKey(int i, int k);
    
};

void swap(int *x, int *y);

int maxOfChild(int left, int right, int i);
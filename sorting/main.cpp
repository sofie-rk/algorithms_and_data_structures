#include "sorting_algorithms.h"

#include <iostream>
#include <array>

using namespace std;

// SORTING
// Given array A[0, ... , N-1], return array B[0, ..., N-1] with same values as A but in sorted order


void printArray(int A[], int N) {
	// This code prints out the array nice:)
	for (int i=0; i<N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}






//------------------------------------------------------------------------------

int main()
{
	int B[] = {3, 6, 1, 8, 9, 4, 10, 4, 7, 12};
	int N_B = sizeof(B)/sizeof(B[0]);
	
	cout << "INSERTION SORT" << endl;
	printArray(B, N_B);
	insertionSort(B, N_B);
	printArray(B, N_B);

	int C[] = {1, 7, 3, 6, 4, 8, 2, 7, 3, 5, 6};
	int N_C= sizeof(C)/sizeof(C[0]);

	cout << "MERGE SORT" << endl;
	printArray(C, N_C);
	mergeSort(C, 0, N_C-1);
	printArray(C, N_C);



}

//------------------------------------------------------------------------------

#include "sorting_algorithms.h"


void insertionSort(int A[], int N) {
    
	for (int i=0; i<N; i++) {
		
		int j = i;
		int currentElement = A[i];

		while (j>0 && A[j-1] > currentElement) {
			A[j] = A[j-1];
			j = j-1;
		}
		A[j] = currentElement;
	}
}
// SORTING ALGORITHMS

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


// INSERTION SORT
// Proceed left-to-right in n rounds
// Compare current element A[i] to A[i-1], ..., A[0] until A[i] is placed correctly
// At round i subarray A[0, ..., i-1] is sorted
// Insert A[i] into A[0, ..., i-1] to make A[0, ..., i] sorted
// Complexity O(n^2)

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


// MERGE SORT
// Recursive sorting through merging of sorted subarrays
// Divide and Conquer algorithm:
// Divide input array into two halves recursively
// Then merges sorted subarrays until input array is sorted

void merge(int A[], int i, int m, int j) {
	// Merge two subarrays into one sorted array
	// First subarray is A[i, ..., m]
	// Second subarray is A[m+1, ..., j]

	// Create and fill the subarrays
	int leftN = m-i+1;
	int rightN = j-m;
	int leftSubArray[leftN]; 
	int rightSubArray[rightN];

	for (int k=0; k<leftN; k++) {
		leftSubArray[k] = A[i + k];
	}
	for (int k=0; k<rightN; k++) {
		rightSubArray[k] = A[m+1+k]; 
	}

	// Merging of leftSubArray and rightSubArray
	int l = 0; // inital index left subarray
	int r = 0; // inital index right subarray
	int k = i; // inital index merged array

	while (l < leftN && r < rightN) {
		// As long as there are elements in left subarray and right subarray

		if (leftSubArray[l] <= rightSubArray[r]) {
			// If element in left array is smaller than element in right array, 
			// copy it to the merged array, and change to the next element in left array
			A[k] = leftSubArray[l];
			l++;
		}
		else {
			// Copy element from right array to merged array and
			// change to the next element in the right array
			A[k] = rightSubArray[r];
			r++;
		}
		// Go to next element in the merged array
		k++;
	}

	// If there are any remaining elements in left subarray,
	// copy it to the merged array
	while (l < leftN) {
		A[k] = leftSubArray[l];
		k++;
		l++;
	}

	// If there are any remaining elements in right subarray, 
	// copy it to the merged array
	while (r < rightN) {
		A[k] = rightSubArray[r];
		k++;
		r++;
	}
}

void mergeSort(int A[], int i, int j) {
	if (i>=j) {
		return; // returns recursively
	}
	int m = (i+j)/2;
		
	// Divide array and recurisvely call itself
	mergeSort(A, i, m);
	mergeSort(A, m+1, j);

	// Then, merge the two sorted subarrays together
	merge(A, i, m, j); 
	

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

#include "searching_algorithms.h"


// LINEAR SEARCH
// Given an array A of N elements and a given element x
// Write a function to search for element x in array A using linear search
// Linear search: go through the array and check if every entry matches x
// If entry is found, return the index. Otherwise, return -1.

// Complexity O(n)

int linearSearch(int A[], int N, int x) {

	for (int i=0; i<N; i++) {
		if (A[i] == x) {
			return i;
		}
	}
	return -1;
}


// BINARY SEARCH
// Given a sorted array A of N elements, and a given element x
// Write a function to search for element x in array A using binary search
// Binary search: search the array by repeatedly dividing the search interval
// in half.

// Start by checking the middle entry m of array A. 
// If A[m] = x, return m and stop
// If A[m] < x, recursively continue to serach for x in the RIGHT half of array A
// If A[m] > x, recursively continue to search for x in the LEFT half of array A
// otherwise, return -1

// Complexity O(log2(n))

int binarySearch(int A[], int i, int j, int x) {

	if (j >= i) {

	int m =  (i+j)/2;

	if (A[m] == x) {
		return m;
	}
	
	else if (A[m] < x) {
		// Search through the RIGHT half of the array you just searched
		return binarySearch(A, m+1, j, x);
	}
	else if (A[m] > x) {
		// Search through the LEFT half of the array you just searched
		return binarySearch(A, i, m-1, x);
	}

	}
	// x is not found
	return -1;
}

#include "searching_algorithms.h"
#include "searching_problems.h"

// PROBLEM
// Let A[0 ... n-1] be a sorted array and let k be a number. 
// Determine whether there is a pair of elements A[i] and A[j] 
// (i must be different from j) such that A[i]+A[j] = k.

// O(n^2), algo using brute force (similar to using linear search)
bool twoSumBruteForce(int A[], int N, int k) {

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (A[i] + A[j] == k) {
                return true;
            }
        }
    }
    return false;
}

// O(n log(n)), algo using brute force
bool twoSumBinarySearch(int A[], int N, int k) {
    for (int i=0; i<N; i++) {
        // Use binary search to find k-A[i]
        if (binarySearch(A, 0, N, k - A[i]) != -1 && binarySearch(A, 0, N, k - A[i]) != i) {
            return true;
        }

    }
    return false;

}
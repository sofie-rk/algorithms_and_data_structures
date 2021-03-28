#include "searching_algorithms.h"
#include "three_sum_problem.h"

// PROBLEM
// Let A[0 ... n-1] be a sorted array and let k be a number. 
// Determine whether there is three elements A[i], A[j] and A[z]
// (i, j and z must be different ) such that A[i]+A[j]+A[z] = k.

// O(n^3), brute force (similar to using linear search)
bool threeSumBruteForce(int A[], int N, int k) {

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int z=j+1; z<N; z++) {
                if (A[i] + A[j] + A[z] == k) {
                    return true;
                }
            }
        }
    }

    return false;

}

// O(n^2 log(n)) using binary serach
bool threeSumBinarySearch(int A[], int N, int k) {
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            // Use binary search to find k-A[i]-A[j]
            if (binarySearch(A, 0, N, k-A[i]-A[j]) != -1 && binarySearch(A, 0, N, k-A[i]-A[j]) != i && binarySearch(A, 0, N, k-A[i]-A[j]) != j) {
                return true;
            }
        }
    }
    return false;
}
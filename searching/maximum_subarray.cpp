#include "maximum_subarray.h"

#include <iostream>
#include <limits.h>
using namespace std;


// MAXIMAL SUBARRAY
// Let A[0, ..., n-1] be an array of integers (both positive and negative)
// A maximal subarray of A is a subarray A[i ... j]
// such that the sum A[i]+A[i+1]+...+A[j] is max among all subarrays
// of A.
// Give an algorithm that finds the maximal sum of a subarray of A

// This script gives 4 algortihms with different complexity (O(n^3), O(n^2), O(nlog(n)), O(n))


// O(n^3) time (brute force)
int maximalSubArray1(int A[], int N) {
    int maxSubArray = A[0];

    // Have n^2 pairs of (i, j)
    for (int i=0; i<N; i++){
        
        for (int j=i; j<N; j++) {
            int currentSubArray = 0;

            // Go through at most n elements within A[i]...A[j]
            // Which gives O(n^3)
            for (int k=i; k<j+1; k++) {
                currentSubArray += A[k];
                if (currentSubArray > maxSubArray) {
                    maxSubArray = currentSubArray;
                }
            }
        }
    }

    return maxSubArray;
}


// Algorithm that finds maximum subarray of A in O(n^2) time
int maximalSubArray2(int A[], int N) {

    int maxSubArray = A[0];
    // Have n^2 pairs of (i,j)
    for (int i=0; i<N; i++) {
        int currentSubArray = 0;
        for (int j=i; j<N; j++) {
            currentSubArray += A[j];
            if (currentSubArray > maxSubArray) {
                maxSubArray = currentSubArray;
            }
        }
    }

    return maxSubArray;
}

// Algorithm (maximalSubArray3) that finds a maximal subarray of A in O(n log(n))
// This is a divide and conquer algorithm
int maxCrossingSubArray(int A[], int l, int m, int r) {
	
	int leftSum = INT_MIN;
	int currentSumLeft = 0;

	// From the middle and go to the left
	// Find the maximum subarray
	for (int i=m; i>=0; i--) {
		currentSumLeft += A[i];
		if (currentSumLeft > leftSum) {
			leftSum = currentSumLeft;
		}
	}

	int rightSum = INT_MIN;
	int currentSumRight = 0;

	// From the middle to the right 
	// Find the maximum subarray
	for (int j=m+1; j<=r; j++) {
		currentSumRight += A[j];
		if (currentSumRight > rightSum) {
			rightSum = currentSumRight;
		}
	}

	// Add the left and right, to find the subarray crossing
	// the middle element
	return (leftSum + rightSum);
}

// Find max of two integers
int maxOf2Int(int a, int b) {
	if (a>b) {return a;}
	else {return b;}
}
// Find max of 3 integers
int maxOf3Int(int a, int b, int c) {
	return maxOf2Int(maxOf2Int(a, b), c);
}

int maximalSubArray3(int A[], int l, int r) {
	
	// Divide the array A in two halves	
	// The maximum subarray is in either:
		// The left half
		// The right half
		// Crossing the midpoint

	// If only one element:
	if (l == r) {return A[l];}

	// Midpoint
	int m = (l + r)/2;

	// Finding max in the left and right halves by recursive call
	int maxLeftSubArray = maximalSubArray3(A, l, m);
	int maxRightSubArray = maximalSubArray3(A, m+1, r);
	// Finding max of subarray crossing midpoint
	int maxCrossing = maxCrossingSubArray(A, l, m, r);

	// Return the max value of the three possibilities
	return maxOf3Int(maxLeftSubArray, maxRightSubArray, maxCrossing);

	// Compleixity: dividing log2(n), each comparison is n, which gives O(nlog(n))
}


// Algorithm that finds maximum subarray of A in O(n) time
// Initially: i=0, accSum = 0, maxSum = small number
// accSum: accumulated sum
// maxSum: max sum obtained
// Going through array (n elements)
// 1) accSum += A[i]
// 2) if (accSum > maxSum): maxSum = accSum
// 3) if (accSum <= 0): accSum = 0
// The last step "resets" accSum whenever the accumulated sum gets less than zero
// This algorithm looks for positive contigous segments of the array

int maximalSubArray4(int A[], int N) {
	int maxSum = INT_MIN;
	int accSum = 0;

	for (int i=0; i<N; i++) {
		accSum += A[i];

		if (accSum > maxSum) {
			maxSum = accSum;
		}
		if (accSum <= 0) {
			accSum = 0;
		}
	}

	return maxSum;
}
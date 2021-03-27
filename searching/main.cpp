// SEARCHING ALGORTITHMS
// From Algorithms and Data Structures, Spring 2021
 

#include <iostream>
using namespace std;

#include "searching_algorithms.h"
#include "two_sum_problem.h"
#include "maximum_subarray.h"



//------------------------------------------------------------------------------'


int main()
{

	// TESTING LINEAR SEARCH ALGORITHM
	int A[] = {1, 4, 7, 12, 36, 16, 18, 25, 28, 31, 29, 33, 8, 42};
	int N_A = sizeof(A)/sizeof(A[0]);
	int x1 = 42;
	int x2 = 56;

	cout << linearSearch(A, N_A, x1) << endl;
	cout << linearSearch(A, N_A, x2) << endl;

	// TESTING LINEAR SEARCH ALGORITHM
	int B[] = {1, 2, 5, 8, 10, 33, 56, 78};
	int N_B = sizeof(B)/sizeof(B[0]);
	int x3 = 5;
	int x4 = 35;

	cout << binarySearch(B, 0, N_B-1, x3) << endl;
	cout << binarySearch(B, 0, N_B-1, x4) << endl;

	
	// TESTING TWO-SUM PROBLEM
	// Algo with brute force
	cout << "43: " << twoSumBruteForce(B, N_B, 43) << endl;
	cout << "4: " << twoSumBruteForce(B, N_B, 4) << endl;

	// Algo with binary search
	cout << "43: " << twoSumBinarySearch(B, N_B, 43) << endl;
	cout << "4: " << twoSumBinarySearch(B, N_B, 4) << endl;

	// TESTING MAXIMAL-SUBARRY PROBLEM
	int C[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int N_C = sizeof(C)/sizeof(C[0]);

	cout << "Algo1: " << maximalSubArray1(C, N_C) << endl;
	cout << "Algo2: " << maximalSubArray2(C, N_C) << endl;
	cout << "Algo3: " << maximalSubArray3(C, 0, N_C) << endl;
	cout << "Algo4: " << maximalSubArray4(C, N_C) << endl;




	


	


}

//------------------------------------------------------------------------------

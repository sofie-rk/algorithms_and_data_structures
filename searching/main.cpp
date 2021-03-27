// SEARCHING ALGORTITHMS
// From Algorithms and Data Structures, Spring 2021
 

#include <iostream>
using namespace std;

#include "searching_algorithms.h"
#include "two_sum_problem.h"



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

	
	// TWO-SUM PROBLEM
	// Algo with brute force
	cout << "43: " << twoSumBruteForce(B, N_B, 43) << endl;
	cout << "4: " << twoSumBruteForce(B, N_B, 4) << endl;

	// Algo with binary search
	cout << "43: " << twoSumBinarySearch(B, N_B, 43) << endl;
	cout << "4: " << twoSumBinarySearch(B, N_B, 4) << endl;

	


	


}

//------------------------------------------------------------------------------

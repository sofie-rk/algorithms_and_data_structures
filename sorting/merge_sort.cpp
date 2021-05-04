// MERGE SORT
// Recursive sorting through merging of sorted subarrays
// Divide and Conquer algorithm:
// Divide input array into two halves recursively
// Then merges sorted subarrays until input array is sorted

void merge(int A[], int i, int m, int j) {
    // Help function
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

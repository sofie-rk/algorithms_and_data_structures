#include "binary_heap.h"

void heapSort(int A[], int n) {

    // Build Heap
    MaxHeap h = MaxHeap(n);
    for (int i=0; i<n; i++) {
        h.insertKey(A[i]);
    }

    // Extract an element from heap
    for (int i=n-1; i>=0; i--) {
        A[i] = h.extractMax();
    }
}
#include "binary_heap.h"
#include "utility.h"

void MaxHeap::bubbleUp(int i) {
    // If heap order is violated at node i because key
    // is larger than parent key

    while (i != 1 && H[i] > H[parent(i)]) {
        // swap node i and parent node
        swap(&H[i], &H[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::bubbleDown(int i) {
    // If heap order is violated at node i because key
    // is smaller that the key at left or right child

    // Assumes that the subtrees are in correct order
    
    // Find index of max child
    int maxChild = maxOfChild(H[left(i)], H[right(i)], i);

    while (H[maxChild] > H[i] && left(i)<=numberOfElements && right(i)<=numberOfElements) {
        swap(&H[i], &H[maxChild]);
        i = maxChild;

        maxChild = maxOfChild(H[left(i)], H[right(i)], i);

    }
}

// Swaps two elements
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int maxOfChild(int left, int right, int i) {
    // Finds index of maximum child
    if (left > right) {
        return 2*i;
    } else {
        return 2*i+1;
    }
}
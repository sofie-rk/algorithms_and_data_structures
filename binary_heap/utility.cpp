#include "utility.h"

// Swaps two elements
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int maxOfChild(int left, int right, int i) {
    if (left > right) {
        return 2*i;
    } else {
        return 2*i+1;
    }
}
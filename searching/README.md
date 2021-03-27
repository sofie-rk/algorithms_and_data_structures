# Searching algorithms

Given a sorted array A and number x, determine if x appears in the array.

## Linear search
Check if each entry matches x.

Time O(n).

## Binary search
Compare x to middle entry m in array A.

If A[m] = x return true and stop.

If A[m] < x, continue *recursively* on the right half of the array.

If A[m] > x, continue *recursively* on the left half of the array.

Time O(log(n))


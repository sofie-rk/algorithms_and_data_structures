# Searching algorithms

Given a sorted array A and number x, determine if x appears in the array.

## Linear search
Check if each entry in array A matches x.

Time O(n).

## Binary search
Compare x to middle entry m in array A.

If A[m] = x return true and stop.

If A[m] < x, continue *recursively* on the right half of the array.

If A[m] > x, continue *recursively* on the left half of the array.

Time O(log(n))


# Problems using searching algorithms

## Two-sum problem 
Let A[0, ... , n-1] be a sorted array and let k be a number. Determine whether there is a pair of elements A[i] and A[j] such that A[i]+A[j] = k (i must be different from j).

## Three-sum problem
Let A[0 ... n-1] be a sorted array and let k be a number. Determine whether there are three elements A[i], A[j] and A[z] such that A[i]+A[j]+A[z] = k (i, j and z must be different).

## Maximum subarry
Let A[0, ..., n-1] be an array of integers. A maximal subarray of A is a subarray A[i ... j] such that the sum A[i]+A[i+1]+...+A[j] is max among all subarrays of A. Give an algorithm that finds the maximal sum of a subarray of A.
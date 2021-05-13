#include "binary_search_tree.h"

#include <iostream>
using namespace std;

BinarySearchTree* sortedArrayToBST(int A[], int i, int j) {

    if (i > j){return nullptr;}

    BinarySearchTree B, *root = nullptr;

    int m = (i+j+1)/2;

    // Make element at index m the root
    root = B.insert(root, A[m]);

    root->leftSubTree = sortedArrayToBST(A, i, m-1);
    root->rightSubTree = sortedArrayToBST(A, m+1, j);

    return root;
}

void testSortedArrayToBST() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "\nTesting sorted array to balanced BST: \n";

    cout << "Array A: \t";
    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    BinarySearchTree* B = sortedArrayToBST(A, 0, n-1);

    cout << "Preorder traversal on the BST: \n";
    B->preorder(B);
}
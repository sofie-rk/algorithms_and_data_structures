#include "binary_search_tree.h"

BinarySearchTree* BinarySearchTree::deleteVertex(BinarySearchTree* root, int x) {

    if (!root) {
        return root;
    }
    if (x < root->data) {
        root->leftSubTree = deleteVertex(root->leftSubTree, x);
    } 
    else if (x > root->data) {
        root->rightSubTree = deleteVertex(root->rightSubTree, x);
    }

    // If x is same as root, this the vertex to be deleted
    else {

        // NO CHILD
        if (!root->leftSubTree && !root->rightSubTree){
            return nullptr;
        }
    }

    return nullptr;
}

BinarySearchTree* BinarySearchTree::predecessor(BinarySearchTree* root, int k) {
    if (!root){return nullptr;}

    if (root->data == k) {return root;}

    if (k < root->data) {
        return predecessor(root->leftSubTree, k);
    }
    BinarySearchTree* T = predecessor(root->rightSubTree, k);

    if (!T) {return T;}

    return root;
}



BinarySearchTree* preorderToBST(int A[], int size) {
    int preIndex = 0;

    return constructTreeUtility(A, preIndex, A[0], INT_MIN, INT_MAX, size);
}

BinarySearchTree* constructTreeUtility(int A[], int* preIndex, int key, int min, int max, int size){
    
    if (*preIndex >= size) {
        return nullptr;
    }

    BinarySearchTree* root = nullptr;

    if (key > min && key < max) {
        root = BinarySearchTree(key);

        *preIndex = *preIndex + 1;
    }

    return nullptr;
}
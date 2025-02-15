#pragma once

#include <vector>

using namespace std;



class BinarySearchTree 
{
    public:

    int data; 
    BinarySearchTree* leftSubTree;
    BinarySearchTree* rightSubTree;

    BinarySearchTree();
    BinarySearchTree(int);

    BinarySearchTree* insert(BinarySearchTree*, int);
    BinarySearchTree* deleteVertex(BinarySearchTree*, int);

    bool search(BinarySearchTree*, int);

    void inorder(BinarySearchTree*);
    void preorder(BinarySearchTree*);
    void postorder(BinarySearchTree*);

    BinarySearchTree* predecessor(BinarySearchTree*, int);

    // BinarySearchTree* getLeft(){return leftSubTree;}
    // BinarySearchTree* getRight(){return rightSubTree;}
    // int getData(){return data;}

};

void testBST();

BinarySearchTree* sortedArrayToBST(int A[], int i, int j);
void testSortedArrayToBST();

BinarySearchTree* preorderToBST(int A[]);
BinarySearchTree* constructTreeUtility(int A[], int* preIndex, int key, int min, int max, int size);
#pragma once

#include <vector>

using namespace std;



class BinarySearchTree 
{
    int data; 
    BinarySearchTree* leftSubTree;
    BinarySearchTree* rightSubTree;
    

    public:
    BinarySearchTree();
    BinarySearchTree(int);

    BinarySearchTree* insert(BinarySearchTree*, int);
    BinarySearchTree* deleteVertex(BinarySearchTree*, int);

    bool search(BinarySearchTree*, int);

    void inorder(BinarySearchTree*);
    void preorder(BinarySearchTree*);
    void postorder(BinarySearchTree*);

    BinarySearchTree* predecessor(BinarySearchTree*, int);

};

void testBST();
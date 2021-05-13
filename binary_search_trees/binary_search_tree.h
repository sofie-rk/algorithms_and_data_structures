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

    void inorder(BinarySearchTree*);

};

void testBST();
#include "binary_search_tree.h"

#include <iostream>
using namespace std;



BinarySearchTree::BinarySearchTree() : 
    data(0),
    leftSubTree(nullptr),
    rightSubTree(nullptr)
{}

BinarySearchTree::BinarySearchTree(int value) :
    data(value),
    leftSubTree(nullptr),
    rightSubTree(nullptr)
{}


BinarySearchTree* BinarySearchTree::insert(BinarySearchTree* root, int data) {
    
    // If root is null, insert the node here
    if (!root) {
        return new BinarySearchTree(data);
    }

    if (data > root->data){
        root->rightSubTree = insert(root->rightSubTree, data);
    } else {
        root->leftSubTree = insert(root->leftSubTree, data);
    }

    return root;
}

bool BinarySearchTree::search(BinarySearchTree* root, int x) {
    if (!root) {return false;}

    if (root->data == x) {
        return true;
    }
    if (root->data < x) {
        return search(root->rightSubTree, x);
    }
    return search(root->leftSubTree, x);
}


void testBST() {
    BinarySearchTree B, *root = nullptr;
   
    root = B.insert(root, 15); // first node is the root
    B.insert(root, 8);
    B.insert(root, 20);
    B.insert(root, 1);
    B.insert(root, 14);
    B.insert(root, 3);
    B.insert(root, 11);
    B.insert(root, 13);

    cout << "\nInorder tree traversal:\n";
    B.inorder(root);

    cout << "\nPreorder tree traversal:\n";
    B.preorder(root);

    cout << "\nPostorder tree traversal:\n";
    B.postorder(root);

    cout << "\nSearching for 25: \n";
    if (B.search(root, 25)) {cout << "Found 25\n";}
    else {cout << "Didnt find 25\n";}

    cout << "\nSearching for 13: \n";
    if (B.search(root, 13)) {cout << "Found 13\n";}
    else {cout << "Didnt find 13\n";}
}
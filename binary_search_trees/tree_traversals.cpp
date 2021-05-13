#include "binary_search_tree.h"

#include <iostream>
using namespace std;

void BinarySearchTree::inorder(BinarySearchTree* root) {
    if (!root) {
        return;
    }
    inorder(root->leftSubTree);
    cout << root->data << endl;
    inorder(root->rightSubTree);
}

void BinarySearchTree::preorder(BinarySearchTree* root) {
    if (!root) {
        return;
    }
    cout << root->data << endl;
    preorder(root->leftSubTree);
    preorder(root->rightSubTree);
}

void BinarySearchTree::postorder(BinarySearchTree* root) {
    if (!root) {
        return;
    }
    postorder(root->leftSubTree);
    postorder(root->rightSubTree);
    cout << root->data << endl;
}
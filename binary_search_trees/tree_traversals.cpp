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
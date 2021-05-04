#include "binary_search_tree.h"

#include <iostream>


using namespace std;



BinarySearchTree::BinarySearchTree() : root(nullptr){}

void BinarySearchTree::insert(Node* node) {
    
    // If root is NULL, insert the first node
    if (!root) {
        root = node;
        nodes.push_back(node);
    } else {

        while() {
            
        }

        if (node->key > root->key) {
            insert(root->right);
        } else {
            insert(root->left);
        }
        // return root after insertion
        return root;
        
    }
}

void BinarySearchTree::printBSTInfo() {

    if (root){
        cout << "Root: " << root->key << endl;
    } else {
        cout << "Empty BST" << endl;
    }

    
    
}
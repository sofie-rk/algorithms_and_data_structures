#pragma once
#include "node.h"

#include <vector>

using namespace std;



class BinarySearchTree 
{
    Node *root;
    vector<Node*> nodes;

    public:
    BinarySearchTree();

    void insert(Node* node);

    void printBSTInfo();

};
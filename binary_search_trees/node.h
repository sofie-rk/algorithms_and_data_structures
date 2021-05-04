#pragma once

struct Node 
{
    int key;
    int data;
    Node* parent;
    Node* left;
    Node* right;
    

    Node(int key, int data);
    void printNode();

};
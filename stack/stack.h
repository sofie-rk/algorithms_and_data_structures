#pragma once

#include "queue.h"


class StackArray 
{
    int N; // capacity of the stack
    int* S; // array;
    int top;    // top index

    public:

    StackArray(int N);

    void push(int x);
    int pop();
    bool isEmpty();

    void displayStack();

};

void testStackArray();

struct Node
{
    int data;
    Node* next;

};

class StackSinglyLinkedList
{
    Node* top;
    public:

    StackSinglyLinkedList();

    void push(int x);
    int pop();
    bool isEmpty();

    void displayStack();

};

void testStackSinglyLinkedList();

class StackTwoQueues
{
    Queue* Q1;
    Queue* Q2;
    int currentSize;

    public:

    StackTwoQueues();

    void push(int x);
    int pop();
    bool isEmpty();

    void displayStack();

};

void testStackTwoQueue();
#pragma once

struct QNode 
{
    int data;
    QNode* next;
};

class Queue
{
    QNode* head;
    QNode* tail;

    public:
    Queue();

    void enqueue(int x);
    int dequeue();
    bool isEmpty();

    void displayQueue();

};

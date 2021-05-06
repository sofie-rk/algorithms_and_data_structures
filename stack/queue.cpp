#include "queue.h"

#include <climits>
#include <iostream>
using namespace std;

Queue::Queue() : head(nullptr), tail(nullptr) {}

void Queue::enqueue(int x) {
    QNode* node = new QNode();
    node->data = x;

    if (isEmpty()) {
        head = node;
        tail = node;
        return;
    }

    // The current tail now points to the new node
    tail->next = node;
    // The new node is now the tail
    tail = node;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow\n";
        return INT_MIN;
    }
    QNode* temp = head;
    head = head->next;

    // If queue now becomes empty, make tail null as well
    if (isEmpty()) {tail = nullptr;}

    return temp->data;
}

bool Queue::isEmpty() {
    return (head == nullptr);
}

void Queue::displayQueue() {
    if (isEmpty()) {cout << "Queue is empty\n";}

    else {
        QNode*N = head;
        while (N != nullptr) {
            cout << N->data << " ";
            N = N->next;
        }
        cout << "\n";
    }
} 

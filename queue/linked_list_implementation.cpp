#include "queue.h"

#include <climits>
#include <iostream>
using namespace std;

QueueLinkedList::QueueLinkedList() : head(nullptr), tail(nullptr) {}

void QueueLinkedList::enqueue(int x) {
    Node* node = new Node();
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

int QueueLinkedList::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow\n";
        return INT_MIN;
    }
    Node* temp = head;
    head = head->next;

    // If queue now becomes empty, make tail null as well
    if (isEmpty()) {tail = nullptr;}

    return temp->data;
}

bool QueueLinkedList::isEmpty() {
    return (head == nullptr);
}

void QueueLinkedList::displayQueue() {
    if (isEmpty()) {cout << "Queue is empty\n";}

    else {
        Node*N = head;
        while (N != nullptr) {
            cout << N->data << " ";
            N = N->next;
        }
        cout << "\n";
    }
} 

void testQueueLinkedList() {
    QueueLinkedList Q = QueueLinkedList();

    cout << "\n\n";
    Q.displayQueue();
    Q.enqueue(3);
    Q.displayQueue();
    Q.enqueue(5);
    Q.displayQueue();
    Q.enqueue(1);
    Q.displayQueue();
    Q.dequeue();
    Q.displayQueue();

}
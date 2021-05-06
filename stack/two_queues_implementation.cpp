#include "stack.h"
#include "queue.h"

#include <iostream>
#include <climits>
using namespace std;

StackTwoQueues::StackTwoQueues() {
    currentSize = 0;
    Q1 = new Queue();
    Q2 = new Queue();
}

void StackTwoQueues::push(int x) {

    // Enqueue x to Q2
    Q2->enqueue(x);

    // Dequeue all elements from Q1, and enqueue them to Q2
    while (!Q1->isEmpty()) {
        Q2->enqueue(Q1->dequeue());
    }

    // Swap names of Q1 and Q2
    Queue* Q = Q1;
    Q1 = Q2;
    Q2 = Q;
}

int StackTwoQueues::pop() {
    if (isEmpty()) {cout << "Stack underflow\n"; return INT_MIN;}
    int i = Q1->dequeue();
    currentSize--;

    return i;
}

bool StackTwoQueues::isEmpty() {
    return (Q1->isEmpty());
}

void StackTwoQueues::displayStack() {
    // Go through Q1
    Q1->displayQueue();
}

void testStackTwoQueue() {
    cout << "\n\n";

    StackTwoQueues S = StackTwoQueues();

    S.push(3);
    S.push(5);
    S.displayStack();
    S.push(2);
    S.displayStack();
    S.push(1);
    S.displayStack();
    S.pop();
    S.displayStack();
}
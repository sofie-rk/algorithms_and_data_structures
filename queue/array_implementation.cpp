#include "queue.h"

#include <climits>
#include <iostream>
using namespace std;

QueueArray::QueueArray(int N) {
    this->N = N;

    head = 0;
    tail = 0;
    count = 0;

    Q = new int[N-1];
}

void QueueArray::enqueue(int x) {
    if (count == N) {
        cout << "Queue overflow\n";
        return;
    }
    Q[tail] = x;
    tail = (tail + 1) % N; 
    count++;
}

int QueueArray::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow\n";
        return INT_MIN;
    } 
    int temp = Q[head];
    head = (head + 1) % N;
    count--;

    return temp;
}

bool QueueArray::isEmpty() {
    return (count == 0);
}

void QueueArray::displayQueue() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        if (head < tail && tail != 0) {
            for (int i=head; i<tail; i++) {
                cout << Q[i] << " ";
            }
        } else {
            for (int i=head; i<N; i++) {
                cout << Q[i] << " ";
            }
            for (int i=0; i<tail; i++) {
                cout << Q[i] << " ";
            }
        }
    }
    cout << "\n";
}

void testQueueArray() {
    QueueArray Q = QueueArray(4);
    
    Q.enqueue(3);
    Q.displayQueue();
    Q.enqueue(5);
    Q.enqueue(1);
    Q.displayQueue();
    Q.dequeue();
    Q.dequeue();
    Q.displayQueue();
    Q.enqueue(4);
    Q.displayQueue();
    Q.enqueue(8);
    Q.displayQueue();
    Q.dequeue();
    Q.displayQueue();

}
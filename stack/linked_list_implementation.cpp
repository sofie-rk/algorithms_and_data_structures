#include "stack.h"

#include <climits>
#include <iostream>
using namespace std;

StackSinglyLinkedList::StackSinglyLinkedList() : top(nullptr) {}

void StackSinglyLinkedList::push(int x) {
    Node* node = new Node();

    // Initialize node
    node->data = x;
    node->next = top;

    // Change top node to be node
    top = node;
}

int StackSinglyLinkedList::pop() {
    if (isEmpty()) {
        std::cout << "Stack underflow\n";
        return INT_MIN;
    } 
    Node* temp = top;
    // Assign second node to top
    top = top->next;

    return temp->data;  
}

bool StackSinglyLinkedList::isEmpty() {
    return (top == nullptr);
}

void StackSinglyLinkedList::displayStack() {
    if (isEmpty()) {cout << "Stack is empty\n";} 
    
    else {
        Node* N = top;
        while (N!=nullptr) {
            cout << N->data << " ";
            N = N->next;
        }
        cout << endl;
    }
}

void testStackSinglyLinkedList() {

    cout << "\n\n";

    StackSinglyLinkedList S = StackSinglyLinkedList();
    S.displayStack();
	S.push(3);
	S.push(4);
	S.displayStack();
	S.pop();
	S.displayStack();
	S.push(28);
	S.push(10);
	S.push(2);
	S.displayStack();
	S.pop();
	S.displayStack();
}
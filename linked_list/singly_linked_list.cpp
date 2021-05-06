#include "singly_linked_list.h"

#include <iostream>

using namespace std;

void printSinglyLinkedList(SinglyNode* N) {

    while (N != nullptr) {
        cout << N->data << " ";
        N = N->next;

    } 
}

void testSinglyLinkedList(){
    
    SinglyNode* head = nullptr;
    SinglyNode* second = nullptr;
    SinglyNode* third = nullptr;
    SinglyNode* fourth = nullptr;

    head = new SinglyNode();
    second = new SinglyNode();
    third = new SinglyNode();
    fourth = new SinglyNode();

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = nullptr;

    printSinglyLinkedList(head);
}
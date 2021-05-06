#include "doubly_linked_list.h"

#include <iostream>

void printDoublyLinkedList(DoublyNode* N) {
    while (N != nullptr) {
        std::cout << N->data << " ";
        N = N->next;
    }
}


void testDoublyLinkedList() {
    DoublyNode* head = nullptr;
    DoublyNode* second = nullptr;
    DoublyNode* third = nullptr;
    DoublyNode* fourth = nullptr;

    head = new DoublyNode();
    second = new DoublyNode();
    third = new DoublyNode();
    fourth = new DoublyNode();

    head->data = 7;
    head->next = second;
    head->prev = nullptr;

    second->data = 8;
    second->next = third;
    second->prev = head;

    third->data = 5;
    third->next = fourth;
    third->prev = second;

    fourth->data = 11;
    fourth->next = nullptr;
    fourth->prev = third;

    printDoublyLinkedList(head);
    
}
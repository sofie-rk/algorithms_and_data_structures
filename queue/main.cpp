#include "queue.h"

#include "iostream"
using namespace std;

// Implement a queue that can contain integers using a
// singly linked list

// Algorithm takes in
// Line 1: 		the number of operations N
// Line 2...N+1:Either "E X" or "D"
// "E X" means enqueue integer X in the queue
// "D" means dequeue an element from the queue
// Output: for each dequeue operation in the input,
// output the integer that was dequeued at that time

// QUEUE
// Type of data structure
// First in first out (FIFO)
// Head pointer: first item in the queue
// Tail pointer: last item in the queue
// enQueue(): add new node after tail, and moves tail to the next node
// deQueue(): remove front node and moves head to the next node

// Linked list node
// struct Node {
// 	int key;
// 	struct Node* next;
// };
 
//------------------------------------------------------------------------------'
int main()
{

	testQueueArray();

	// int N;
	// cin >> N;

	// // Create head and tail node
	// struct Node* head;
	// struct Node* tail;

	// for (int i=0; i<N; i++) {
	// 	string operation;
	// 	cin >> operation;

	// 	// ENQUEUE
	// 	if (operation == "E") {
	// 		int value;
	// 		cin >> value;

	// 		Node* node = new Node();

	// 		// Add new node at the end of queue
	// 		node->key = value;
	// 		node->next = NULL;

	// 		if (tail != NULL) {
	// 			tail->next = node;
	// 		}
	// 		if (head == NULL) {
	// 			head = node;
	// 		}
	// 		// Change tail of the queue
	// 		tail = node;
	// 	}

	// 	// DEQUEUE
	// 	else if (operation == "D") {
	// 		// print out element that is dequeued
	// 		cout << head->key << endl;

	// 		// Move head one node ahead
	// 		head = head->next;
	// 	}
	// }


}

//------------------------------------------------------------------------------

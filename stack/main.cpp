#include "stack.h"

#include <iostream>
using namespace std;

// Implement a stack that can contain integers using a
// singly linked list

// Algorithm takes in
// Line 1: 		the number of operations N
// Line 2...N+1:Either "PU X" or "PO"
// "PU X" means push the integer X on the stack
// "PO" means pop an element from the stack
// Output: for each pop operation in the input, outout the 
// integer that was popped at that time

// STACK
// Type of data structure
// Last in first out (LIFO)

// Linked list NodeMain
// struct NodeMain {
// 	int key;
// 	struct NodeMain* next;
// };


//------------------------------------------------------------------------------'
int main()
{
	testStackArray();

	cout << "\n\n";


	testStackSinglyLinkedList();

	


	// // Algorithm takes in N number of operations N>0
	// int N;
	// cin >> N;

	// // Top NodeMain
	// struct NodeMain* top;

	// // Go through all of the opaerations
	// for (int i=0; i<N; i++) {
	// 	string operation;
	// 	cin >> operation;
		
	// 	// PUSH
	// 	if (operation == "PU") {
	// 		int value;
	// 		cin >> value;

	// 		struct NodeMain* NodeMain;
	// 		NodeMain = new NodeMain();

	// 		// Initialize NodeMain
	// 		NodeMain->key = value;
	// 		NodeMain->next = top;
	// 		// Make NodeMain the top of stack
	// 		top = NodeMain;
	// 	}
	// 	// POP
	// 	else if (operation == "PO") {

	// 		cout << top->key << endl;
			
	// 		// Assign second NodeMain to top
	// 		top = top->next;
	// 	}
	// }
}

//------------------------------------------------------------------------------

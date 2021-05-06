#include "stack.h"

#include <iostream>

using namespace std;

// CONSTRUCTOR
StackArray::StackArray(int N) {
    this->N = N;
    S = new int[N];
    this->top = -1;
}

void StackArray::push(int x) {
    if (top>=(N-1)) {cout << "Stack overflow\n"; return;}
    
    else{
        S[top+1] = x;
        top++;
    }
    
}

int StackArray::pop() {
    if (isEmpty()) {cout << "Stack underflow\n"; return 0;}
    int elementPop = S[top];
    top--;

    return elementPop;
}


bool StackArray::isEmpty() {
    if (top == -1) {return true;}
    else {return false;}
}

void StackArray::displayStack() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        for (int i = 0; i<=top; i++) {
            cout << S[i] << " ";
        }
        cout << endl;
    }
}
#include "hashing.h"

#include <iostream>
using namespace std;

ChainedHashing::ChainedHashing(int B) {
    this->numberOfBuckets = B;
    table = new list<int>[numberOfBuckets];
}

int ChainedHashing::hash(int x) {
    return (x % numberOfBuckets);
}

int ChainedHashing::searchItem(int k) {
    // return k if it is found, else return -1

    int index = hash(k);

    // Linear search in A[h(key)] for k
    for (list<int>::iterator i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == index) {
            return k;
        }
    }

    return -1;

}

void ChainedHashing::insertItem(int x) {
    int index = hash(x);
    table[index].push_front(x);
}

void ChainedHashing::deleteItem(int x) {
    int index = hash(x);

    // Check if key is in the list
    list<int>::iterator i;
    for (i = table[index].begin(); i!= table[index].end(); i++) {
        if (*i == x) {
            break;
        }
    }
    // Remove key if it is found
    if (i != table[index].end()) {
        table[index].erase(i);
    } 
}

void ChainedHashing::displayChainedHashing() {
    for (int i=0; i<numberOfBuckets; i++) {
        cout << i;
        for (auto x : table[i]) {
            cout << "-> " << x;
        }
        cout << "\n";
    }
}
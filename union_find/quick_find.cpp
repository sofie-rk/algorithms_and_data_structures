#include "quick_find.h"

#include <iostream>
using namespace std;

QuickFind::QuickFind(int n) {
    this->n = n;

    // Initialize array. Each element is its own representative.
    for (int k=0; k<n; k++) {
        id[k] = k;
    }
}


int QuickFind::find(int i) {
    return id[i];
}

void QuickFind::unionFunc(int i, int j) {
    int iRep = find(i);
    int jRep = find(j);

    // If i and j not in the same set
    if (iRep != jRep) {
        // Change representative (id) of all elements in set where i belong,
        // to the set where j belong
        for (int k=0; k<n; k++) {
            if (id[k] == iRep) {
                id[k] = jRep;
            }
        }
    }
}

void QuickFind::printIdArray() {
    for (int i=0; i<n; i++) {
        cout << id[i] << " ";
    }
    cout << "\n";
}
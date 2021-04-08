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

void testQuickFindCode() {
    QuickFind quickFind = QuickFind(7);
    quickFind.printIdArray();

	quickFind.unionFunc(3,4);
	quickFind.printIdArray();

	quickFind.unionFunc(5,0);
	quickFind.printIdArray();

	quickFind.unionFunc(4,5);
	quickFind.printIdArray();

	quickFind.unionFunc(4,3);
	quickFind.printIdArray();

	quickFind.unionFunc(0,1);
	quickFind.printIdArray();

	quickFind.unionFunc(2,6);
	quickFind.printIdArray();

	quickFind.unionFunc(0,4);
	quickFind.printIdArray();

	quickFind.unionFunc(6,0);
	quickFind.printIdArray();

}
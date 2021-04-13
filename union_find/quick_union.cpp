#include "quick_union.h"

#include <iostream>
using namespace std;

QuickUnion::QuickUnion(int n) {
    this->n = n;

    p = new int[n];

    for (int k=0; k<n; k++) {
        // Initially, each element is its own representative
        // p[root] = root, where root is the representative of the set
        p[k] = k;
    }
}

int QuickUnion::find(int i) {
    while (i != p[i]) {
        // as long as i is not the representative
        i = p[i];
        // Walk upwards in the tree
    }
    return i;
}

void QuickUnion::unionFunc(int i, int j) {
    // If i and j not in the same set
    if (find(i) != find(j)) {
        // Representative of i is changed to representative of j
        p[find(i)] = find(j);
    }
}


void QuickUnion::printParentArray() {
    for (int i=0; i<n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

void testQuickUnionCode() {

    cout << "\nTesting Quick Union Code \n";

    QuickUnion quickUnion = QuickUnion(7);
    quickUnion.printParentArray();

	quickUnion.unionFunc(3,4);
	quickUnion.printParentArray();

    cout << "FIND(3): " << quickUnion.find(3) << endl;

	quickUnion.unionFunc(5,0);
	quickUnion.printParentArray();

	quickUnion.unionFunc(4,5);
	quickUnion.printParentArray();

	quickUnion.unionFunc(4,3);
	quickUnion.printParentArray();

	quickUnion.unionFunc(0,1);
	quickUnion.printParentArray();

    cout << "FIND(0): " << quickUnion.find(0) << endl;

	quickUnion.unionFunc(2,6);
	quickUnion.printParentArray();

	quickUnion.unionFunc(0,4);
	quickUnion.printParentArray();

	quickUnion.unionFunc(6,0);
	quickUnion.printParentArray();

    cout << "Done testing Quick Union Code \n";
}
#include "weighted_quick_union.h"

#include <iostream>
using namespace std;

WeightedQuickUnion::WeightedQuickUnion(int n) {
    this->n = n;
    p = new int[n];
    size = new int[n];

    // Each element is the only element in the tree
    // Size of all the trees are 1
    for (int k=0; k<n; k++) {
        p[k] = k;
        size[k] = 1;
    }
}

int WeightedQuickUnion::find(int i) {
    // As long as not representative of set
    while(i != p[i]) {
        // Go upwards in the tree
        // Will eventually reach root node which is the representative,
        // and its parent is itself
        i = p[i];
    }

    return i;
}

void WeightedQuickUnion::unionFunc(int i, int j) {
    int iRep = find(i);
    int jRep = find(j);
    
    // If i and j not in the same set
    if (iRep != jRep) {
        // Find the largest tree
        if (size[iRep] <= size[jRep]) {
            p[iRep] = jRep;
            size[jRep] += size[iRep];
        } else {
            p[jRep] = iRep;
            size[iRep] += size[jRep];
        }
    }
}

void WeightedQuickUnion::printParentArray() {
    for (int i=0; i<n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

void testWeightedQuickUnionCode() {

    cout << "\nTesting Weighted Quick Union Code \n";

    WeightedQuickUnion wQuickUnion = WeightedQuickUnion(7);
    wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(3,4);
	wQuickUnion.printParentArray();

    cout << "FIND(3): " << wQuickUnion.find(3) << endl;

	wQuickUnion.unionFunc(5,0);
	wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(4,5);
	wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(4,3);
	wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(0,1);
	wQuickUnion.printParentArray();

    cout << "FIND(1): " << wQuickUnion.find(1) << endl;

	wQuickUnion.unionFunc(2,6);
	wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(0,4);
	wQuickUnion.printParentArray();

	wQuickUnion.unionFunc(6,0);
	wQuickUnion.printParentArray();

    cout << "Done testing Weighted Quick Union Code \n";

}
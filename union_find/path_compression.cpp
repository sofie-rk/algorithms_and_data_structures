#include "path_compression.h"

// Weighted quick union with path compression

#include <iostream>
#include <vector>
using namespace std;

PathCompression::PathCompression(int n) {
    this-> n = n;
    p = new int[n];
    size = new int[n];

    for (int k=0; k<n; k++) {
        p[k] = k;
        size[k] = 1;
    }
}

int PathCompression::find(int i) {

    vector<int> nodes; // will store the nodes visited using FIND(i) here

    int j = p[i];
    while(i != p[i]) {
        i = p[i];
        nodes.push_back(i);
    }

    // PATH COMPRESSION
    for (auto node : nodes) {
        // All of the visisted nodes changes parent to be to the representative node
        p[node] = i;
    }

    return i;
}

void PathCompression::unionFunc(int i, int j) {
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

void PathCompression::printParentArray() {
    for (int i=0; i<n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

void testPathCompressionCode() {

    cout << "\nTesting Path Compression Code (with weighted quick union) \n";

    PathCompression pathCompression = PathCompression(7);
    //pathCompression.printParentArray();

	pathCompression.unionFunc(3,4);
	//pathCompression.printParentArray();

	pathCompression.unionFunc(5,0);
	//pathCompression.printParentArray();

	pathCompression.unionFunc(4,5);
	//pathCompression.printParentArray();

	pathCompression.unionFunc(4,3);
	//pathCompression.printParentArray();

	pathCompression.unionFunc(0,1);
	pathCompression.printParentArray();

	// FIND(3), should make 3 child of root elements
    cout << "FIND(3) " << pathCompression.find(3) << endl;
    
    pathCompression.printParentArray();

    pathCompression.unionFunc(2,6);
    pathCompression.printParentArray();

    cout << "Testing Path Compression Code \n";

}
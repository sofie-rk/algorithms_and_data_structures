#include "hashing.h"

#include <iostream>
using namespace std;




//------------------------------------------------------------------------------'
int main()
{
    ChainedHashing H =  ChainedHashing(10);

    H.insertItem(1);
    H.insertItem(13);
    H.insertItem(16);
    H.insertItem(41);
    H.insertItem(54);
    H.insertItem(66);
    H.insertItem(96);

    H.displayChainedHashing();

    cout << "Searching for 16: " << H.searchItem(16) << "\n\n";

    cout << "Deleting 16" << endl;
    H.deleteItem(16);

    H.displayChainedHashing();
    cout << "Searching for 16: " << H.searchItem(16) << endl;

}

//------------------------------------------------------------------------------

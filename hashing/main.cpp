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

    cout << "Deleting 66" << endl;
    H.deleteItem(66);

    H.displayHash();
    
    cout << H.searchItem(1) << endl;

    cout << H.searchItem(3) << endl;
}

//------------------------------------------------------------------------------

#include <list>

using namespace std;

class ChainedHashing
{
    int numberOfBuckets;
    list<int>* table;

    public:
    ChainedHashing(int B);

    int searchItem(int k);
    void insertItem(int x);
    void deleteItem(int x);
    

    int hash(int x);

    void displayChainedHashing();

};
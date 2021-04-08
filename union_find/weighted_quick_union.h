
class WeightedQuickUnion {

    int n;
    int* p;
    int* size;

    public:

    // Constructur of WeightedQuickUnion is the same as INIT(n)
    WeightedQuickUnion(int n);
    void unionFunc(int i, int j);
    int find(int i);

    void printParentArray();
};

void testWeightedQuickUnionCode();
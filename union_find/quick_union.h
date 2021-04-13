class QuickUnion {

    int n;
    int* p;

    public:

    // Constructur is the same as INIT(n)
    QuickUnion(int n);

    void unionFunc(int i, int j);
    int find(int i);

    void printParentArray();

    ~QuickUnion() {}

};

void testQuickUnionCode();
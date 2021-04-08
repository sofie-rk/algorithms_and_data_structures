
class QuickFind {
    int n;
    int id[];

    public:

    // NB! Constructur of QuickFind corresponds to INIT(n)
    QuickFind(int n);
    void unionFunc(int i, int j);
    int find(int i);

    void printIdArray();
};
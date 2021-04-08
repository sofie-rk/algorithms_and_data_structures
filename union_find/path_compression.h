// Weighted quick union with path compression

class PathCompression {
    int n;
    int* p;
    int* size;

    public:
    PathCompression(int n);
    void unionFunc(int i, int j);
    int find(int i);

    void printParentArray();
};

void testPathCompressionCode();
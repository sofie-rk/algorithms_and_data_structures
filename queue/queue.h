class QueueArray 
{
    int head;
    int tail;
    int count;
    int N;
    int *Q;

    public:

    QueueArray(int N);

    void enqueue(int x);
    int dequeue();
    bool isEmpty();

    void displayQueue();
};

void testQueueArray();
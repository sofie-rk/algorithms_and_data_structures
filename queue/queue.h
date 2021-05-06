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

struct Node 
{
    int data;
    Node* next;

};

class QueueLinkedList 
{
    Node* head;
    Node* tail;

    public:
    QueueLinkedList();

    void enqueue(int x);
    int dequeue();
    bool isEmpty();

    void displayQueue();

};

void testQueueLinkedList();
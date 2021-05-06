
class StackArray 
{
    int N; // capacity of the stack
    int* S; // array;
    int top;    // top index

    public:

    StackArray(int N);

    void push(int x);
    int pop();
    bool isEmpty();

    void displayStack();

};
const int max_itens = 100;

struct Node {
    int value;
    Node *next;
};
class Queue{
    private:
    Node *first, *last;

    public:
    Queue(); //Constructor
    ~Queue(); //Destructor
    bool isEmpty();
    bool isFull();
    void push(int item);
    int pop();
    void printQueue();
    int len();
};
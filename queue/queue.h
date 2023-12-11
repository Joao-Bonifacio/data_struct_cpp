const int max_itens = 100;

class Queue{
    private:
    int first, last, *data;

    public:
    Queue(); //Constructor
    ~Queue(); //Destructor
    bool isFull();
    bool isEmpty();
    void push(int item);
    int pop();
    void printQueue();
    int len();
};
const int max_itens = 100;

class Stack{
    private:
    int lenght;
    int *estrutura;

    public:
    Stack(); //Constructor
    ~Stack(); //Destructor
    bool isFull();
    bool isEmpty();
    void push(int item);
    int pop();
    void printstack();
    int len();
};
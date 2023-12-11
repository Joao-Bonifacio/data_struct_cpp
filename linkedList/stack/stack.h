const int max_itens = 100;
struct Node{ //poderia ser class
    int value;
    Node *next;
};

class Stack{
    private:
    Node *NodeTop; //Topo da pilha 

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
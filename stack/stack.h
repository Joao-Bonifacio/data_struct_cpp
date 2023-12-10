const int max_itens = 100;
typedef int typeitem;

class Stack{
    private:
    int lenght;
    typeitem *estrutura;

    public:
    Stack(); //Constructor
    ~Stack(); //Destructor
    bool isFull();
    bool isEmpty();
    void push(typeitem item);
    typeitem pop();
    void printstack();
    int len();
};
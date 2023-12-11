#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(){
    lenght = 0;
    estrutura = new int[max_itens];
}
Stack::~Stack(){
    delete[] estrutura;
}
bool Stack::isFull(){
    return (lenght == max_itens);
}
bool Stack::isEmpty(){
    return (lenght == 0);
}
//
void Stack::push(int item){
    if (isFull()) {
        cout << "The stack is full"<<endl;
    }
    //-----------------------> Stack <-----------------------------
    estrutura[lenght] = item;
    lenght++;
    //add:0 -> 1 -> 2...
}
int Stack::pop(){
    if (isEmpty()) {
        cout << "The stack is empty"<<endl;
        return 0;
    }
    lenght--;
    return estrutura[lenght];
}
//
void Stack::printstack(){
    cout << "stack: [ ";
    for (int i = 0; i < lenght; i++) {
        if (i != lenght - 1) {
            cout << estrutura[i] << ", ";
        }else {
            cout << estrutura[i];
        }
    }
    cout << " ]" <<endl;
    
}
int Stack::len(){
    return lenght;
}
#include <iostream>
#include "stack.h"
#include <cstddef> //NULL
using namespace std;

Stack::Stack(){
    NodeTop = NULL;
}
Stack::~Stack(){
    Node *tmpNode = NodeTop;
    while (tmpNode != NULL) {
        tmpNode = NodeTop;
        NodeTop = NodeTop->next;
        delete tmpNode;
    }
}
bool Stack::isEmpty(){
    return (NodeTop == NULL);
}
bool Stack::isFull(){
    Node *newNode;
    try {
        newNode = new Node;
        delete newNode;
        return false;
    } catch(bad_alloc e) {
        return true;
    }
}
//
void Stack::push(int item){
    if (isFull()) {
        cout << "The stack is full"<<endl;
    }
    Node *newNode = new Node;
    newNode->value = item;
    newNode->next = NodeTop; //Guarda o próximo endereço de memória
    NodeTop = newNode;
}
int Stack::pop(){
    if (isEmpty()) {
        cout << "The stack is empty"<<endl;
        return 0;
    }
    Node *tmpNode = NodeTop;
    int item = NodeTop->value;
    NodeTop = NodeTop->next;
    delete tmpNode;
    return item;
}
//
void Stack::printstack(){
    Node *tmpNode = NodeTop;
    cout << "[ ";
    while (tmpNode != NULL) {
        cout << tmpNode->value << " ";
        tmpNode = tmpNode->next;
    }
    cout << "]" <<endl;
}
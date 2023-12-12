#include <iostream>
#include "queue.h"
#include <cstddef>
#include <new>
using namespace std;

Queue::Queue(){
    first = NULL;
    last = NULL;
}
Queue::~Queue(){
    Node *tmpNode;
    while (first != NULL) {
        tmpNode = first;
        first = first->next;
        delete tmpNode;
    }
    last = NULL;
}
bool Queue::isEmpty(){
    return (first == NULL);
}
bool Queue::isFull(){
    Node * tmpNode;
    try {
        tmpNode = new Node;
        delete tmpNode;
        return false;
    } catch(bad_alloc e) {
        return true;
    }
}
void Queue::push(int item){
    if (isFull()) {
        cout << "The queue is full"<<endl;
    }
    Node *newNode = new Node;
    newNode->value = item;
    newNode->next = NULL;
    if (first == NULL) {
        first = newNode;
    } else {
        last->next = newNode;
    }
    last = newNode;
}
int Queue::pop(){
    if (isEmpty()) {
        cout << "The queue is empty"<<endl;
        return 0;
    }
    Node *tmpNode = first;
    int item = first->value;
    first = first->next;
    if (first == NULL) {
        last = NULL;
    }
    delete tmpNode;
    return item;
}
void Queue::printQueue(){
    Node *tmpNode;
    cout << "Queue: [ ";
    while (tmpNode != NULL) {
        cout << tmpNode->value << " ";
        tmpNode = tmpNode->next;
    }
    cout << "]" <<endl;
}
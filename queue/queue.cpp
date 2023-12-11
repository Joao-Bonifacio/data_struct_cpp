#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue(){
    first = 0;
    last = 0;
    data = new int[max_itens];
}
Queue::~Queue(){
    delete[] data;
}
bool Queue::isFull(){ //!!
    return (last - first == max_itens);
}
bool Queue::isEmpty(){ //!!
    return (first == last);
}
void Queue::push(int item){ //!! | alias -> enqueue()
    if (isFull()) {
        cout << "The queue is full"<<endl;
    }
    data[last % max_itens] = item;
    last++;
}
int Queue::pop(){ //!! | alias -> dequeue()
    if (isEmpty()) {
        cout << "The queue is empty"<<endl;
        return 0;
    }
    first++;
    return data[(first - 1) % max_itens];
}
//
void Queue::printQueue(){
    cout << "Queue: [ ";
    for (int i = first; i < last; i++) {
        cout << data[i % max_itens] <<" ";
    }
    cout << "]" <<endl;
    
}
int Queue::len(){
    return last - first;
}

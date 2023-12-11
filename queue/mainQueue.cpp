#include <iostream>
#include "queue.h"
using namespace std;

int main(int argc, char const *argv[]){
    Queue array_queue;
    int item, option;

    do {
        cout << "0 => Exit"<<endl;
        cout << "1 => Add"<<endl;
        cout << "2 => Remove"<<endl;
        cout << "3 => Print Queue"<<endl;
        cout << "> ";
        cin >> option;
        switch (option) {
            case 0: break;
            case 1:
                cout << "Inster number: ";
                cin >> item;
                array_queue.push(item);
                break;
            case 2:
                item = array_queue.pop();
                cout << item << " removed."<<endl;
                break;
            default:
                array_queue.printQueue();
                break;
        }
    } while (option != 0);
    array_queue.~Queue();
    
    return 0;
}

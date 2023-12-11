#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char const *argv[]){
    Stack array_stack;
    int item, option;

    do {
        cout << "0 => Exit"<<endl;
        cout << "1 => Add"<<endl;
        cout << "2 => Remove"<<endl;
        cout << "3 => Print stack"<<endl;
        cout << "> ";
        cin >> option;
        switch (option) {
            case 0: break;
            case 1:
                cout << "Inster number: ";
                cin >> item;
                array_stack.push(item);
                break;
            case 2:
                item = array_stack.pop();
                cout << item << " removed."<<endl;
                break;
            default:
                array_stack.printstack();
                break;
        }
    } while (option != 0);
    
    return 0;
}

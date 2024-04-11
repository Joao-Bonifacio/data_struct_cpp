#include <iostream>
#include "avlTree.h"
using namespace std;

int main(int argc, char const *argv[]){
    AVLTree tree_alunos;
    int option, ra, imp;
    string name;
    bool search = false;

    do {
        cout << "0 => Exit"<<endl;
        cout << "1 => Add"<<endl;
        cout << "2 => Remove"<<endl;
        cout << "3 => Search"<<endl;
        cout << "4 => Print"<<endl;
        cout << "> ";
        cin >> option;

        if (option == 1) {
            cout << "Inserir Ra: ";
            cin >> ra;
            cout << "Inserir Nome: ";
            cin >> name;
            Aluno aluno(ra, name);
            if (tree_alunos.isFull()) {
                cout<<"Is Full!"<<endl;
            }else {
                tree_alunos.insert(aluno);
            }
        }else if (option == 2) {
            cout << "RA to remove: ";
            cin >> ra;
            Aluno aluno(ra, " ");
            tree_alunos.remove(aluno);
        }else if (option == 3) {
            cout << "Ra to search: ";
            cin >> ra;
            Aluno aluno(ra, " ");
            tree_alunos.search(aluno, search);
            if (search) {
                cout << aluno.getRa()<<": "<< aluno.getName()<<endl;    
            }else {
                cout << "Not found"<<endl; 
            }
        }else if (option == 4) {
            cout << "Digite 1 para fazer a impressao em pre ordem!\n";
            cout << "Digite 2 para fazer a impressao em ordem!\n";
            cout << "Digite 3 para fazer a impressao em pos ordem!\n";
            cin >> imp;
            if (imp == 1){
                tree_alunos.showTreePreOrder(tree_alunos.getRoot());
            } else if (imp == 2){
                tree_alunos.showTreeInOrder(tree_alunos.getRoot());
            } else{
                tree_alunos.showTreePostOrder(tree_alunos.getRoot());
            }      
        }
    } while (option != 0);
    
    return 0;
}

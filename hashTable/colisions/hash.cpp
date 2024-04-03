#include <iostream>
#include "hash.h"
using namespace std;

int Hash::HashFunction(Aluno aluno) {
    return (aluno.getRa() % max_positions);
}
Hash::Hash(int lenght, int max) {
    itens_lenght = 0;
    max_itens = max;
    max_positions = lenght;
    estrutura = new Aluno[lenght];
}
Hash::~Hash() {
    delete[] estrutura;
}
bool Hash::isFull() {
    return (itens_lenght == max_itens);
}
int Hash::getLenght() {
    return (itens_lenght);
}

void Hash::insert(Aluno aluno) {
    if (isFull()) {
        cout<<"A tabela está cheia"<<endl;
    } else {
        int local = HashFunction(aluno);
        while (estrutura[local].getRa() > 0) {
            local = (local+1) % max_positions;
        }
        estrutura[local] = aluno;
        itens_lenght++;
    }
}
void Hash::remove(Aluno aluno) {
    int local = HashFunction(aluno);
    if (estrutura[local].getRa() != -1) {
        estrutura[local] = Aluno(-1, " ");
        itens_lenght--;
    }
    
}
void Hash::search(Aluno& aluno, bool& search) {
    int local = HashFunction(aluno);
    Aluno aux = estrutura[local];
    if (aluno.getRa() != aux.getRa()) {
        search = false;
    } else {
        search = true;
        aluno = aux;
    }
}
void Hash::getTable() {
    cout << "Tabela: \n";
    for (int i = 0; i < max_positions; i++) {
        if (estrutura[i].getRa() != -1) {
            cout<< i << " : " << estrutura[i].getRa() <<" | "<< estrutura[i].getName() << endl;
        };
    };
}
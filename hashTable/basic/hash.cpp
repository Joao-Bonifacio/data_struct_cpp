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
    int local = HashFunction(aluno);
    //Tratamento de colisão (linear -> insere no próximo indice)
    while (estrutura[local].getRa() > 0) {
        local = (local+1) % max_positions;
    }
    //----------------------------------------------------------
    estrutura[local] = aluno;
    itens_lenght++;
}
void Hash::remove(Aluno aluno) {
    int local = HashFunction(aluno);
    bool test = false;
    //Tratamento de colisões
    while (estrutura[local].getRa() != -1) {
        if (estrutura[local].getRa() == aluno.getRa()) {
            cout<<"Elemento removido"<<endl;
            estrutura[local] = Aluno(-2, " ");
            itens_lenght--;
            test = true;
            break;
        }
        local = (local+1) % max_positions;
    }
    if (!test) {
        cout<<"Elemente não encontrado | Nenhum removido!"<<endl;
    }
    //----------------------
}
void Hash::search(Aluno& aluno, bool& search) {
    int local = HashFunction(aluno);
    search = false;
    while (estrutura[local].getRa() != -1) {
        if (estrutura[local].getRa() == aluno.getRa()) {
            search = true;
            aluno = estrutura[local];
            break;
        }
        local = (local+1) % max_positions;
    }
}
void Hash::getTable() {
    cout << "Tabela: \n";
    for (int i = 0; i < max_positions; i++) {
        if (estrutura[i].getRa() > 0) {
            cout<< i << " : " << estrutura[i].getRa() <<" | "<< estrutura[i].getName() << endl;
        };
    };
}
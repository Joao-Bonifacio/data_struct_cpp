#include <iostream>
#include "hash.h"
using namespace std;

int main() {
    int lenght, max;
    cout<<"Digite o tamanho da estrutura"<<endl;
    cin>>lenght;
    cout<<"Digite o número máximo de elementos"<<endl;
    cin>>max;
    cout<<"O fator de carga é "<< (float)max / (float)lenght <<endl;

    Hash alunoHash(lenght, max);
    int options, ra;
    string name;
    bool search;

    do {
        cout<<"Digite 0 para sair"<<endl;
        cout<<"Digite 1 para inserir"<<endl;
        cout<<"Digite 2 para remover"<<endl;
        cout<<"Digite 3 para buscar"<<endl;
        cout<<"Digite 4 para imprimir"<<endl;
        cin>>options;

        if (options == 1) {
            cout<<"Qual o Ra do aluno"<<endl;
            cin>>ra;
            cout<<"Qual o nome do aluno"<<endl;
            cin>>name;
            Aluno aluno(ra, name);
            alunoHash.insert(aluno);
        } else if (options == 2) {
            cout<<"Qual  é o Ra do aluno"<<endl;
            cin>>ra;
            Aluno aluno(ra," ");
            alunoHash.remove(aluno);
        } else if (options == 3) {
            cout<<"Qual  é o Ra do aluno"<<endl;
            cin>>ra;
            Aluno aluno(ra," ");
            alunoHash.search(aluno, search);
            if (search) {
                cout<<"Encontrado"<<endl;
                cout<<"RA: "<< aluno.getRa()<<" | "<<"Name: "<< aluno.getName() <<endl;
            }else {
                cout<<"Aluno não encontrado"<<endl;
            }
        } else if (options == 4) {
            alunoHash.getTable();
        }
    } while (options != 0);
    
    return 0;
}

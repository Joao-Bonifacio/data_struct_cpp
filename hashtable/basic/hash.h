#include "aluno.h"

class Hash {
    private:
        int HashFunction(Aluno aluno);
        int max_itens;
        int max_positions;
        int itens_lenght;
        Aluno* estrutura;
    public:
        Hash(int lenght, int max);
        ~Hash();
        bool isFull();
        int getLenght();
        void insert(Aluno aluno);
        void remove(Aluno aluno);
        void search(Aluno& aluno, bool& search);
        void getTable();
};

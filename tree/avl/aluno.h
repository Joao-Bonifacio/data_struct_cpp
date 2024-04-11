#include <iostream>
using namespace std;

class Aluno {
private:
    int ra;
    string name;
public:
    Aluno();
    Aluno(int r, string n);
    string getName();
    int getRa();
};

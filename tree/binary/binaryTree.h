#include <iostream>
#include "aluno.h"

struct Node {
    Aluno aluno;
    Node* leftChild;
    Node* rightChild;
};

class BinarySearchTree { //Conhecida como BST
private:
    Node* root;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void deleteTree(Node* current_node);
    Node* getRoot();
    bool isFull();
    bool isEmpty();
    void insert(Aluno aluno);
    void remove(Aluno aluno);
    void searchToRemove(Aluno aluno, Node*& current_node);
    void removeNode(Node*& current_node);
    void getSucessor(Aluno& aluno_sucessor, Node* temp);
    void search(Aluno& aluno, bool& search);
    void showTreePreOrder(Node* current_node);
    void showTreeInOrder(Node* current_node);
    void showTreePostOrder(Node* current_node);
};

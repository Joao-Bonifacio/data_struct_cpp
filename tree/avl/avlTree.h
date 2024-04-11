#include <iostream>
#include "aluno.h"

struct Node {
    Aluno aluno;
    Node* leftChild;
    Node* rightChild;
    int ballanceFactor;
};

class AVLTree { //Conhecida como BST
private:
    Node* root;
    
public:
    AVLTree();
    ~AVLTree();
    void deleteTree(Node* current_node);
    Node* getRoot();
    bool isFull();
    bool isEmpty();
    void insert(Aluno aluno);
    void remove(Aluno aluno);
    void searchToRemove(Aluno aluno, Node*& current_node, bool& reduced);
    void removeNode(Node*& current_node, bool& reduced);
    void getSucessor(Aluno& aluno_sucessor, Node* temp);
    void search(Aluno& aluno, bool& search);
    void showTreePreOrder(Node* current_node);
    void showTreeInOrder(Node* current_node);
    void showTreePostOrder(Node* current_node);
    //
    void rightRotate(Node*& tree);
    void leftRotate(Node*& tree);
    void leftRightRotate(Node*& tree);
    void rightLeftRotate(Node*& tree);
    void rotate(Node*& tree);
    void recursiveInsert(Node*& current_node, Aluno aluno, bool& growed);
};

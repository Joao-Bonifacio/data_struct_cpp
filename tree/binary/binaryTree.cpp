#include <iostream>
#include <cstddef> //trabalhar com NULL
#include "binaryTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}
BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}
void BinarySearchTree::deleteTree(Node* current_node) {
    if (current_node != NULL) {
        deleteTree(current_node->leftChild);
        deleteTree(current_node->rightChild);
        delete current_node;
    }
}
Node* BinarySearchTree::getRoot() {
    return root;
}
bool BinarySearchTree::isFull() {
    try {
        Node* temp = new Node;
        delete temp;
        return false;
    } catch(bad_alloc exception) {
        return true;
    }
}
bool BinarySearchTree::isEmpty() {
    return (root == NULL);
}
void BinarySearchTree::insert(Aluno aluno) {
    if (isFull()) {
        cout<<"A árvore está cheia!"<<endl;
    }else {
        Node* newNode = new Node;
        newNode -> aluno = aluno;
        newNode -> leftChild = NULL;
        newNode -> rightChild = NULL;
        if (root == NULL) {
            root = newNode;
        }else {
            Node* temp = root;
            while (temp != NULL) {
                if (aluno.getRa() < temp->aluno.getRa()) {
                    if (temp->leftChild == NULL) {
                        temp->leftChild = newNode;
                        break;
                    }else {
                        temp = temp->leftChild;
                    }
                }else {
                    if (temp->rightChild == NULL) {
                        temp->rightChild = newNode;
                        break;
                    }else {
                        temp = temp->rightChild;
                    }
                }
            }
        }
    }
}
void BinarySearchTree::remove(Aluno aluno) {
    searchToRemove(aluno, root);
}
void BinarySearchTree::searchToRemove(Aluno aluno, Node*& current_node) {
    if (aluno.getRa() < current_node->aluno.getRa()) {
        searchToRemove(aluno, current_node->leftChild);
    }else if(aluno.getRa() > current_node->aluno.getRa()) {
        searchToRemove(aluno, current_node->rightChild);
    }else {
        removeNode(current_node);
    }
}
void BinarySearchTree::removeNode(Node*& current_node) {
    Node* temp = current_node;
    if (current_node->leftChild == NULL) {
        current_node = current_node->rightChild;
        delete temp;
    }else if (current_node->rightChild == NULL) {
        current_node = current_node->leftChild;
        delete temp;
    }else {
        Aluno sucessor;
        getSucessor(sucessor, current_node);
        current_node->aluno = sucessor;
        searchToRemove(sucessor, current_node->rightChild);
    }
}
void BinarySearchTree::getSucessor(Aluno& aluno_sucessor, Node* temp) {
    temp = temp->rightChild;
    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }
    aluno_sucessor = temp->aluno;
}
void BinarySearchTree::search(Aluno& aluno, bool& search) {
    search = false;
    Node* temp = root;
    while (temp != NULL) {
        if (aluno.getRa() < temp->aluno.getRa()){
            temp = temp->leftChild;
        }else if (aluno.getRa() > temp->aluno.getRa()) {
            temp = temp->rightChild;
        }else { //encontrado
            search = true;
            aluno = temp->aluno;
            break;
        }
    }
}
void BinarySearchTree::showTreePreOrder(Node* current_node) {
    if (current_node != NULL) {
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
        showTreePreOrder(current_node->leftChild);
        showTreePreOrder(current_node->rightChild);
    }
}
void BinarySearchTree::showTreeInOrder(Node* current_node) {
    if (current_node != NULL) {
        showTreeInOrder(current_node->leftChild);
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
        showTreeInOrder(current_node->rightChild);
    }
}
void BinarySearchTree::showTreePostOrder(Node* current_node) {
    if (current_node != NULL) {
        showTreePostOrder(current_node->leftChild);
        showTreePostOrder(current_node->rightChild);
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
    }
}
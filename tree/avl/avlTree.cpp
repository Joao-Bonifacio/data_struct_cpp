#include <iostream>
#include <cstddef> //trabalhar com NULL
#include "avlTree.h"
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}
AVLTree::~AVLTree() {
    deleteTree(root);
}
void AVLTree::deleteTree(Node* current_node) {
    if (current_node != NULL) {
        deleteTree(current_node->leftChild);
        deleteTree(current_node->rightChild);
        delete current_node;
    }
}
Node* AVLTree::getRoot() {
    return root;
}
bool AVLTree::isFull() {
    try {
        Node* temp = new Node;
        delete temp;
        return false;
    } catch(bad_alloc exception) {
        return true;
    }
}
bool AVLTree::isEmpty() {
    return (root == NULL);
}
void AVLTree::insert(Aluno aluno) {
    bool growed;
    recursiveInsert(root, aluno, growed);
}
void AVLTree::recursiveInsert(Node*& current_node, Aluno aluno, bool& growed) {
    if (current_node == NULL) {
            current_node = new Node;
            current_node->rightChild = NULL;
            current_node->leftChild = NULL;
            current_node->aluno = aluno;
            current_node->ballanceFactor = 0;
            growed = true;
            return;
        }  
        if (aluno.getRa() < current_node->aluno.getRa()) {
            recursiveInsert(current_node->leftChild, aluno, growed);
            if (growed){
                current_node->ballanceFactor-=1;   
            } 
        } else {
            recursiveInsert(current_node->rightChild, aluno, growed);
            if (growed){
                current_node->ballanceFactor+=1;
            }    
        } 
        rotate(current_node);

        if (growed && current_node->ballanceFactor == 0){
            growed = false;
        }
}
void AVLTree::remove(Aluno aluno) {
    bool reduced;
    searchToRemove(aluno, root, reduced);
}
void AVLTree::searchToRemove(Aluno aluno, Node*& current_node, bool& reduced) {
    if (aluno.getRa() < current_node->aluno.getRa()) {
        searchToRemove(aluno, current_node->leftChild, reduced);
        if (reduced){
            current_node->ballanceFactor+=1;
        }
    }else if(aluno.getRa() > current_node->aluno.getRa()) {
        searchToRemove(aluno, current_node->rightChild, reduced);
        if (reduced){
            current_node->ballanceFactor-=1;
        }
    }else {
        removeNode(current_node, reduced);
    }
    if (current_node != NULL){
        rotate(current_node);
        if (reduced && current_node->ballanceFactor != 0){
            reduced = false;
        }
    }
}
void AVLTree::removeNode(Node*& current_node, bool& reduced) {
    Node* temp = current_node;
    if (current_node->leftChild == NULL) {
        current_node = current_node->rightChild;
        reduced = true;
        delete temp;
    }else if (current_node->rightChild == NULL) {
        current_node = current_node->leftChild;
        reduced = true;
        delete temp;
    }else {
        Aluno sucessor;
        getSucessor(sucessor, current_node);
        current_node->aluno = sucessor;
        searchToRemove(sucessor, current_node->rightChild, reduced);
        if (reduced) {
            current_node->ballanceFactor-=1;
        }
    }
}
void AVLTree::getSucessor(Aluno& aluno_sucessor, Node* temp) {
    temp = temp->rightChild;
    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }
    aluno_sucessor = temp->aluno;
}
void AVLTree::search(Aluno& aluno, bool& search) {
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
void AVLTree::showTreePreOrder(Node* current_node) {
    if (current_node != NULL) {
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
        showTreePreOrder(current_node->leftChild);
        showTreePreOrder(current_node->rightChild);
    }
}
void AVLTree::showTreeInOrder(Node* current_node) {
    if (current_node != NULL) {
        showTreeInOrder(current_node->leftChild);
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
        showTreeInOrder(current_node->rightChild);
    }
}
void AVLTree::showTreePostOrder(Node* current_node) {
    if (current_node != NULL) {
        showTreePostOrder(current_node->leftChild);
        showTreePostOrder(current_node->rightChild);
        cout<< current_node->aluno.getRa() <<": "<< current_node->aluno.getName() <<endl;
    }
}
void AVLTree::rightRotate(Node*& father) {
    Node* newFather = father->leftChild;
    father->leftChild = newFather->rightChild;
    newFather->rightChild = father;
    father = newFather;
}
void AVLTree::leftRotate(Node*& father) {
    Node* newFather = father->rightChild;
    father->rightChild = newFather->leftChild;
    newFather->leftChild = father;
    father = newFather;
}
void AVLTree::leftRightRotate(Node*& father) {
    Node* child = father->leftChild;
    leftRotate(child);
    father->leftChild = child;
    rightRotate(father);
}
void AVLTree::rightLeftRotate(Node*& father) {
    Node* child = father->rightChild;
    rightLeftRotate(child);
    father->rightChild = child;
    leftRotate(father);
}
void AVLTree::rotate(Node*& father) {
    Node* child;
    Node* grandChild;
    if(father->ballanceFactor == -2){ //rotaciona para a direita

    child = father->leftChild;

    if(child->ballanceFactor == -1){ // Simples para a direita
        father->ballanceFactor = 0;
        child->ballanceFactor = 0;
        rightRotate(father);
    }else if (child->ballanceFactor == 0){ // Simples para a direita
        father->ballanceFactor = -1;
        child->ballanceFactor = 1;
        rightRotate(father);
    }else if (child->ballanceFactor == 1){ // Rotação dupla
        grandChild = child->rightChild;
        if (grandChild->ballanceFactor == -1){
            father->ballanceFactor = 1;
            child->ballanceFactor = 0;
        } else if (grandChild->ballanceFactor == 0){
            father->ballanceFactor = 0;
            child->ballanceFactor = 0;                
        } else if (grandChild->ballanceFactor == 1){
            father->ballanceFactor = 0;
            child->ballanceFactor = -1;                
        }
        grandChild->ballanceFactor = 0; 
        rightLeftRotate(father);            
    }else if(father->ballanceFactor == 2){ //rotaciona para a esquerda
        child = father->rightChild;
        if (child->ballanceFactor == 1) { // Simples para a esquerda
            father->ballanceFactor = 0;
            child->ballanceFactor = 0;
            leftRotate(father);
        } else if (child->ballanceFactor == 0){ // Simples para a esquerda         
            father->ballanceFactor = 1;
            child->ballanceFactor = -1;
            leftRotate(father);
        } else if (child->ballanceFactor == -1){ // Rotacao dupla
            grandChild = child->leftChild;
            if (grandChild->ballanceFactor == -1){
                father->ballanceFactor =  0;
                child->ballanceFactor = 1; 
            } else if (grandChild->ballanceFactor == 0){
                father->ballanceFactor =  0;
                child->ballanceFactor = 0; 
            } else if (grandChild->ballanceFactor == 1){
                father->ballanceFactor =  -1;
                child->ballanceFactor = 0; 
            }
            grandChild->ballanceFactor = 0;
            rightLeftRotate(father);
        }
    }
}

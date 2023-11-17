#ifndef BST_NODE_H
#define BST_NODE_H
#include<iostream>
using namespace std;

template <typename T>
class Node{
    private:
    T val;
    Node<T>* parent;
    Node<T>* left; 
    Node<T>* right;
    
    template <typename U>
    friend class BST;

    public: 
    Node(T val) : val(val){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    #pragma region "Setter"
    void setKey(T key){
        this->val = key;
    }

    void setParent(Node<T>* ptr){
        this->parent = ptr;
    }

    void setLeft(Node<T>* ptr){
        this->left = ptr;
    }

    void setRight(Node<T>* ptr){
        this->right = ptr;
    }
    #pragma endregion
    #pragma region "Getter"
    T getKey(){
        return this->val;
    }

    Node<T>* getParent(){
        return this->parent;
    }

    Node<T>* getLeft(){
        return this->left;
    }

    Node<T>* getRight(){
        return this->right;
    }
    
    #pragma endregion

    //overload di stampa
    friend ostream& operator<< (ostream& out, Node<T> &node){
        out << "node val: " << node.val << " " << &node << " - left: " << node.left << " - right: " << node.right << " - parent: " << node.parent << endl;
        return out;
     }
};
#endif
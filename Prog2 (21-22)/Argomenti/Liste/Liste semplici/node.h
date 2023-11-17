#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <typename T>
class Node{
    private:
    T val;
    Node<T>* next;
    template <typename U>
    friend class List;

    public: 
    Node(T key) : val(key){
        next = nullptr;
    }

    //getter key e next
    T getKey(){
        return this->key;
    }

    Node<T>* getNext(){
        return this->next;
    }

    //overload di stampa
    friend ostream& operator<< (ostream& out, Node<T> &node){
        out << "node val: " << node.val << " " << &node << " - next: " << node.next;
        return out;
    }


};
#endif
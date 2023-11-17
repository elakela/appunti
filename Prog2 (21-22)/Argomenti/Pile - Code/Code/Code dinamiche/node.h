#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node{
    private:
    T val; 
    Node<T>* next; 
    Node<T>* prev;
    template <typename U>
    friend class List;

    public: 
    Node(T val): val(val){
        next = nullptr;
        prev = nullptr;
    }

    //getter 
    Node<T>* getNext(){
        return this->next;
    }

    Node<T>* getPrev(){
        return this->prev;
    }

    T getKey(){
        return this->key;
    }

    //overload di stampa
    friend ostream& operator<<(ostream& out, Node<T> &node){
        out << "node val: " << node.val << " " << &node << " - next: " << node.next << " - prev: " << node.prev;
        return out;
    }
};
#endif
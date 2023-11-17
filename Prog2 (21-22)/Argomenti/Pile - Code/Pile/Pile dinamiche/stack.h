#ifndef STACK_H
#define STACK_H
#include "list.h"

template <typename T>
class Stack : protected List<T>{
    private: 
    int size = 0;
    Node<T>* top;

    public: 
    //costruttore
    Stack() : List<T>(){};

    //controllo se è vuota
    bool isEmpty(){
        return size == 0;
    }

    //getter del top
    Node<T>* getTop(){
        if(isEmpty()){
            cout << "empty stack" << endl;
            return nullptr;
        }

        top = List<T> :: getHead();
        return top;
    }

    //push (inserimento)
    void push(T val){
        List<T> :: insertHead(val);
        size++;
    }

    //pop (rimozione)
    Node<T>* pop(){
        if(isEmpty()){
            cout << "stack underflow" << endl;
            return nullptr;
        }

        Node<T>* ptr = top;
        List<T> :: removeHead();
        size--;
        return ptr;
    }

    //overload di stampa
    friend ostream& operator<<(ostream& out, Stack<T>& pila){
            
            Node<T>* ptr=pila.getTop();

            while (ptr){
                out << *ptr << endl;
                ptr=ptr->getNext();
            }
            delete ptr;
            return out;
        }

};
#endif
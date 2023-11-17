#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

template <typename T>
class Queue : protected List<T>{
    private: 
    int size =0;
    
    public:
    Queue():List<T>(){};

    //controllo se è vuota
    bool isEmpty(){
        return size == 0;
    }

    //ritorno la testa e la coda
    Node<T>* getHead(){
        Node<T>* head = List<T> :: getHead();
        return head;
    }

    Node<T>* getTail(){
        Node<T>* tail = List<T> :: getTail();
        return tail;
    }

    // enqueue(inserimento)
    void enqueue(T val){
        List<T> :: insertTail(val);
        size++;
    }

    //dequeue (rimozione)
    Node<T>* dequeue(){
        if(isEmpty()){
            cout << "queue underflow " << endl;
            return nullptr;
        }

        Node<T>* head = List<T> :: getHead();
        List<T> :: removeHead();
        size--;
        return head;
    }

    //overload di stampa 
    friend ostream& operator<< (ostream& out, Queue<T> &coda){
        Node<T>* ptr = coda.head;
        while(ptr){
        out << *ptr << endl;
        ptr = ptr->getNext();
        }
        return out;
    }
};
#endif
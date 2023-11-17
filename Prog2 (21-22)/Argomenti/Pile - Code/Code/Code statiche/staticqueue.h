#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <iostream> 
using namespace std;

template <typename T>
class Queue{
    private: 
    T* array;
    int maxSize = -1;
    int head = -1;
    int tail = -1;
    int size = 0; 

    public:
    Queue(int dim) : maxSize(dim){
        array = new T[maxSize];
    } 

    //controllo se è vuoto
    bool isEmpty(){
        return size == 0;
    }

    // ritorna la testa
    T getHead(){
        if(isEmpty()){
            cout << "empty queue" << endl;
            return -1;
        }
        return array[head];
    }

    // enqueue(inserimento)
    void enqueue(T val){
        if(size == maxSize){
            cout << "queue overflow" << endl;
            return;
        }
        if(head=-1){
            head = 0;
        }
        array[++tail%maxSize] = val;
        size++;
    }

    // dequeue (rimozione)
    T dequeue(){
        if (isEmpty()){
            cout << "queue underflow" << endl;
            return -1;
        }
        T x = array[head];
        head = (++head%maxSize);
        size--;
        return x;;
    }

    //overload di stampa 
    friend ostream& operator<< (ostream& out, Queue<T> &coda){
        out << "Head: " << &coda.array[coda.head] << "\tTail: " << &coda.array[coda.tail] << endl;
        for(int i = coda.head, count = 0; count<coda.size; count++){        // non va incrementata la i.
            out << " node val: " << coda.array[i] << " " << &coda.array[i] << " - next: " << &coda.array[i+1] << " - prev: " << &coda.array[i-1] << endl;
            i = (i+1) % coda.maxSize;
        }
        return out;
    }

};
#endif
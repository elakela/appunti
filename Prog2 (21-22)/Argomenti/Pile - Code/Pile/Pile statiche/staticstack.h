#ifndef STATIC_STACK_H
#define STATIC_STACK_H
#include<iostream>
using namespace std;

template <typename T>
class Stack{
    private:
    T* array;
    int size = 0;
    int maxSize = -1;
    int top = -1;

    public:
    Stack(T val) : maxSize(val){
        array = new T[maxSize];
    }

    //controllo se è vuota
    bool isEmpty(){
        return size == 0;
    }

    //getter per il top
    T getTop(){
        if(isEmpty()){
            cout << "empty stack" << endl;
            return -1;
        }

        return array[top];
    }

    //push (inserimento)
    void push(T val){
        if(size == maxSize){
            cout << "stack overlow" << endl;
            return;
        }
        array[++top] = val;
        size++;
    }

    //pop (rimozione)
    T pop(){
        if(isEmpty()){
            cout << "stack underflow" << endl;
            return -1;
        }
        size--;
        return array[top--];
    }

    //overload di stampa
    friend ostream& operator<< (ostream& out, Stack<T> &pila){
        out << "Head: " << pila.getTop() << endl;
        for(int i = pila.size-1; i>0; i--){
            out << "node val: " << pila.array[i] << " " << &pila.array[i] << " - next: " << &pila.array[i-1] << " - prev: " << &pila.array[i+1] << endl; 
        }
        return out;
    }
};
#endif
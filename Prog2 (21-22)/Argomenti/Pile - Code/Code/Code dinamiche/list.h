#ifndef LIST_H
#define LIST_H
#include "node.h"

template <typename T>
class List{
    protected:
    Node<T>* head;
    Node<T>* tail;

    public: 
    List(){
        head = nullptr;
        tail = nullptr;
    }

    //controllo se è vuota
    bool isEmpty(){
        return (head == tail) && (tail == nullptr);
    }

    //ritorno la testa e la coda
    Node<T>* getHead(){
        return this->head;
    }

    Node<T>* getTail(){
        return this->tail;
    }

    #pragma region "Inserimenti"
   //inserimento in testa
    void insertHead(T val){
        if(isEmpty()){
            head = new Node<T>(val);
            tail = head;
            return;
        }
        
        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    //inserimento in coda
    void insertTail(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = new Node<T>(val);
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }

    //inserimento in ordine crescente
    void insertCrescente(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        if(val<=head->val){
            insertHead(val);
            return;
        }

        if(val>tail->val){
            insertTail(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->next){
            if (ptr->next->val>= val){
                break;
            }
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = ptr->next;
        temp->prev = ptr;

        ptr->next->prev = temp;
        ptr->next = temp;
    }

    void insertDec(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        if(val>head->val){
            insertHead(val);
            return;
        }

        if(val<=tail->val){
            insertTail(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->next){
            if (ptr->next->val< val){
                break;
            }
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = ptr->next;
        temp->prev = ptr;

        ptr->next->prev = temp;
        ptr->next = temp;
    }
    #pragma endregion
    #pragma region "Rimozioni"
    //rimozione della testa
    void removeHead(){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        ptr->next->prev = nullptr;
        head = ptr->next;
        delete ptr;
    }

    //rimozione della coda
    void removeTail(){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = tail;
        ptr->prev->next = nullptr;
        tail = ptr->prev;
        delete ptr;
    }

    //rimozione di un elemento
    void removeVal(T val){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        if(val == head->val){
            removeHead();
            return;
        }

        if(val == tail->val){
            removeTail();
            return;
        }

        Node<T>* ptr = head;
        while (ptr->next){
            if(ptr->val == val){
                break;
            }
            ptr = ptr->next;
        }

        if(ptr->val!=val){
            cout << "value " << val << " not found";
            return;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }

    #pragma endregion
    //overload di stampa
    friend ostream& operator<<(ostream& out, List<T> &lista){
        out << "Head: " << lista.head << " Tail: " << lista.tail << endl;
        Node<T>* ptr = lista.head;
        while(ptr){
            out << *ptr << endl;
            ptr = ptr->getNext();
        }
        return out;
    }
};
#endif
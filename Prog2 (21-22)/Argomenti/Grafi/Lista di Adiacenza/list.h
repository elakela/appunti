#ifndef LIST_H
#define LIST_H
#include "node.h"

template <typename T>
class List{
    private:
    Node<T>* head;
    
    public:
    List(){
        head = nullptr;
    }

    //controllo se è vuoto
    bool isEmpty(){
        return head == nullptr;
    }

    //getter per la testa
    Node<T>* getHead(){
        return this->head;
    }

    #pragma region "Inserimenti"
    //inserimento in testa
    void insertHead(T val){
        if (isEmpty()){
            head = new Node<T>(val);
            return;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }

    // inserimento in coda
    void insertTail(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext()){      // il puntatore a seguire deve essere diverso da null.
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
    }

    //inserimento in ordine crescente
    void insertCrescente(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        if(val<= head->val){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext()){
            if(ptr->next->val>=val){
                break;
            }
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
    }

    //inserimento in ordine decrescente 
    void insertDec(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }
        
        if(val > head->val){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext()){
            if(ptr->next->val<val){
                break;
            }
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
        
    }
    #pragma endregion

    #pragma region "Rimozioni"
    //rimozione dalla testa
    void removeHead(){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        head = head->next;
        delete ptr;
    }

    //rimozione dalla coda
    void removeTail(){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        Node<T>* prec = nullptr;
        while(ptr->next){
            prec = ptr;
            ptr = ptr->next;
        }
        
        prec->next = nullptr;
        delete ptr;
    }

    //rimozione di un valore
    void removeKey(T val){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        Node<T>* prec = nullptr;
        while(ptr->next){
            if(ptr->val == val){
                break;
            }
            prec = ptr;
            ptr = ptr->next;
        }
        
        if (ptr->val!=val)
        {
            cout << "value " << val << " not found" << endl;
            return;
        }
        
        prec->next = ptr->next;
        delete ptr;
    }
    #pragma endregion

    //overload di stampa
    friend ostream& operator<<(ostream& out, List<T> &lista){
        
        Node<T>* ptr = lista.head;
        while (ptr){
            out << *ptr << endl;
            ptr = ptr->getNext();
        }
        return out;
    }
};
#endif
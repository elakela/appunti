#include "stack.h"

int main(){
    Stack<int> pila;
    cout << pila.isEmpty();
    if (pila.isEmpty() == 1){
        cout << ": e' vuota" << endl;
    }
    else{
        cout << ": non e' vuota" << endl;
    }
    system("pause");
    system("cls");
    pila.push(32);
    pila.push(2);
    pila.push(18);
    cout << pila;
    system("pause");
    system("cls");
    cout << pila.getTop() << endl;
    cout << pila.pop() << endl;
    cout << pila;
    system("pause");
    system("cls");
    
}
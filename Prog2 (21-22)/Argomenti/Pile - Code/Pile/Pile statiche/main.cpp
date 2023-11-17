#include "staticstack.h"

int main(){
    Stack<int> pila(30);
    cout << pila.isEmpty();
    if(pila.isEmpty() == 1){
        cout << " : is empty" << endl;
    } 
    else{
        cout << ": isn't empty" << endl;
    }
    
    system("pause");
    system("cls");

    pila.push(13);
    pila.push(15);
    pila.push(18);
    cout << pila;
    system("pause");
    system("cls");

    cout << pila.getTop() << " = ";
    cout << pila.pop() << endl << endl << endl;
    
    cout << pila;
    system("pause");
    system("cls");
}
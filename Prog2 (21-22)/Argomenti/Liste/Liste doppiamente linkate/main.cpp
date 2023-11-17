#include "list.h"

int main(){
    List<int> lista;
    cout << lista.isEmpty() << endl;
    lista.insertHead(13);
    lista.insertHead(16);
    lista.insertHead(25);
    cout << lista;
    system ("pause");
    system("cls");

    lista.insertTail(23);
    lista.insertTail(12);
    cout << lista;
    system ("pause");
    system("cls");

    lista.insertCrescente(1); 
    lista.insertDec(50);
    lista.insertDec(1);
    lista.insertCrescente(51);
     cout << lista;
    system ("pause");
    system("cls");

    lista.removeHead();
    lista.removeTail();
    lista.removeVal(25);
    cout << lista;
    system ("pause");
    system("cls");

}
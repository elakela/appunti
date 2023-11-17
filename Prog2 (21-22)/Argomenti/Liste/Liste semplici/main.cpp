#include "list.h"

int main(){
    List<int> lista;
    cout << lista.isEmpty() << endl;
    
    #pragma region "Inserimenti"
    lista.insertHead(13);
    lista.insertHead(15);
    lista.insertHead(23);
    cout << lista;
    system("pause");
    system("cls");
    lista.insertTail(8);
    lista.insertTail(9);
    cout << lista;
    system("pause");
    system("cls");
    lista.insertCrescente(7);
    lista.insertCrescente(28);
    cout << lista;
    system("pause");
    system("cls");
    lista.insertDec(28);
    lista.insertDec(7);
    cout << lista;
    system("pause");
    system("cls");
    #pragma endregion
    #pragma region "Rimozioni"
    lista.removeHead();
    lista.removeTail();
    lista.removeKey(28);
    cout << lista;
    system("pause");
    system("cls");
    #pragma endregion

}
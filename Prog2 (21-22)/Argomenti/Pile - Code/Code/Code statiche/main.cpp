#include "staticqueue.h"

int main(){
    Queue<int> coda(30);
    cout << coda.isEmpty() << endl;
    coda.enqueue(13);
    coda.enqueue(18);
    coda.enqueue(24);
    cout << coda;
    system("pause");
    system("cls");

    cout << coda.getHead() << " = ";
    cout << coda.dequeue() << endl << endl << endl;
    cout << coda;
    system("pause");
    system("cls");


}
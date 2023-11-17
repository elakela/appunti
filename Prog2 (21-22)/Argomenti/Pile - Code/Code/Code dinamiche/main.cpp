#include "queue.h"

int main(){
    Queue<int> coda;
    cout << coda.isEmpty() << endl;

    coda.enqueue(13);
    coda.enqueue(18);
    coda.enqueue(20);
    cout << coda;
    system ("pause");
    system ("cls");

    cout << coda.getHead() << " = ";
    cout << coda.dequeue() << endl << endl << endl << endl;
    
    cout << coda;
    
}
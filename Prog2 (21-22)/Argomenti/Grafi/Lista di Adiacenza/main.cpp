#include "graphList.h"

int main(){
    Graph<int> grafo(1);
    cout << grafo.isEmpty() << endl;
    grafo.addVertex(1);
    grafo.addVertex(2); 
    cout << grafo;
    system("pause");
    system("cls");
    grafo.addEdges(1, 2);
    cout << grafo;
}
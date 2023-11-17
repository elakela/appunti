#include"graph.h"

int main(){
    Graph<int> grafo(30, 1);
    cout << grafo.isEmpty() << endl << endl << endl << endl;

    grafo.addVertex(2);
    grafo.addVertex(3);
    grafo.addVertex(5);
    cout << grafo;
    system ("pause"); 
    system ("cls");
    // grafo.addEdge(2, 3);
    // grafo.addEdge(3, 5);
    // cout << grafo;
    // system ("pause"); 
    // system ("cls");
    int n, m;
    cout << "Indica due nodi per fare un arco: " << endl;
    cin >> n >> m;
    grafo.addEdge(n, m);
    cout << endl << endl << endl;
    cout << grafo;
}
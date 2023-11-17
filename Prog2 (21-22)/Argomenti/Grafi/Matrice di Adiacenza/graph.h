#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H
#include<iostream>
using namespace std;

template <typename T>
class Vertex{
    private: 
    T val;
    template <typename U>
    friend class Graph;

    public:
    Vertex(T val) : val(val){};
    Vertex():Vertex(NULL){};

    //controllo se è uguale
    bool operator=(Vertex<T> &val){
        return this->val == val->val;
    }

    void setVal(T v){
        this->val = v;
    }
    T getVal(){
        return this->val;
    }
    //overload di stampa
    friend ostream& operator<< (ostream& out, Vertex<T> &ver){
        out << ver.val;
        return out;
    }
};


template <typename T>
class Graph{
    private:
    bool **adj; 
    Vertex<T>** v;
    int size = 0;
    int maxSize;
    bool isOriented;

    public:
    Graph(T val, bool orie): maxSize(val), isOriented(orie){
        v = new Vertex<T>*[maxSize];
        adj = new bool*[maxSize];
        for (int i = 0; i<maxSize; i++){
            adj[i] = new bool[maxSize]{0};
        }
    }

    //controllo se è vuoto
    bool isEmpty(){
        return size == 0;
    }

    // aggiungo un vertice
    void addVertex(T val){
        if(size == maxSize){
            return;
        }

        v[size++] = new Vertex<T>(val);
    }

    //aggiungo un arco
    void addEdge(T key1, T key2){
        int i = search(key1);
        int j = search(key2);

        if (i!=-1 && j!=-1){
            adj[i][j] = 1;
            if(isOriented==0){
                adj[j][i] = 1;
            }
        }

        else if(i == -1){
            cout << "val " << key1 << " not found";
        }
        else if (j == -1){
            cout << "val " << key2 << " not found";
        }
    }

    //ricerca
    int search(T val){
        if(isEmpty()){
            return -1;
        }

        for(int i = 0; i<size; i++){
            if(val == v[i]->val){
                return i;
            }
        }
        return -1;
    }


    //overload di stampa
    friend ostream& operator<< (ostream& out, Graph<T> &grafo){ 
        for(int i = 0; i<grafo.size; i++){
            out << grafo.v[i]->getVal() << "\t";
        }
        out << endl << endl << endl << "     ";

        for(int i = 0; i<grafo.size; i++){
            out << grafo.v[i]->getVal() << "  ";
        }
        
            out << endl << "    ---------";
        
        cout << endl;
        for(int i = 0; i<grafo.size; i++){
            out << grafo.v[i]->getVal() << " | ";
            for(int j = 0; j<grafo.size; j++){
                out << " " << grafo.adj[i][j] << " ";
            }
            out << " | " << endl;
        }

        out << "    ---------" << endl;
        return out;
    }

};
#endif
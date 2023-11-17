#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H
#include "list.h"

template <typename T>
class GraphVertex : public List<T>{
    public:
    GraphVertex(T val) : List<T>(){
        List<T>::insertTail(val);
    }

   friend ostream& operator<< (ostream& out, GraphVertex<T> &vertices){
        out << "Vertex " << vertices.getHead()->getKey();
        out << "\t"<< "Adjiacency: ";
        Node<T>* ptr = vertices.getHead();
        while(ptr){
            out << ptr->getKey() << "->";
            ptr = ptr->getNext();
        }

        return out;
    }  
};


template <typename T>
class Graph{
    private: 
    List<GraphVertex<T>> vertices;
    int n_vertices = 0;
    bool isOriented;

    public: 
    Graph(bool oriented) : isOriented(oriented){};
    
    //controllo se è vuoto
    bool isEmpty(){
        return n_vertices == 0;
    }    
    
    // inserimento vertice
    void addVertex(T val){
        GraphVertex<T> toadd(val);
        vertices.insertTail(val);
        n_vertices++;
    }

    // inserimetno arco
    void addEdges(T key1, T key2){
        Node<GraphVertex<T>>* node1 = search(key1);
        Node<GraphVertex<T>>* node2 = search(key2);
        
        if(node1 && node2){
            node1->getKey().insertTail(key2);
            if(!isOriented){
                node2->getKey().insertTail(key1);
            }
        }

        if (node1 == nullptr){
            cout << "val " << key1 << " not found" << endl;
        }
        else if (node2 == nullptr) {
            cout << "val " << key2 << " not found" << endl;
        }
    }
    
    //ricerca
    Node<GraphVertex<T>>* search(T val){
        if(isEmpty()){
            return nullptr;
        }
        
        Node<GraphVertex<T>>* ptr = vertices.getHead();
        while(ptr){
            if (ptr->getKey().getHead()->getKey() == val){
                return ptr;
            }
            ptr = ptr->getNext();
        }
        return nullptr;
    }

    //stampa
    friend ostream& operator<< (ostream& out, Graph<T> &grafo){
        out << grafo.vertices;
        return out;
    }
};
#endif
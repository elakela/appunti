#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void swap (int &a, int &b){ //bisogna prendere i valori dereferenziati
    int x = a;
    a = b;
    b = x;
}

void selection(int* array, int dim){
    int min = 0;
    for(int i = 0; i<dim; i++){
        min = i;
        for(int j = i+1; j<dim; j++){
            if(array[j] < array[i])
                min = j;
        }
        swap(array[i], array[min]);
    }

    for(int i = 0; i<dim; i++)
        cout << array[i] << "  "; 
}

int main(){
    // srand(time(NULL));
    int dim;
    cout << "inserire la dimensione dell'array: " << endl;
    cin >> dim;

    int* array = new int[dim];
    int min, max; 
    cout << "inserire l'intervallo di numeri inseribili nell'array" << endl;
    cin >> min >> max;

    for(int i = 0; i<dim; i++){
        array[i] = rand()%(max-min+1)+min;  // il range si individua scrivendo (b-a+1)+a
    }

    for(int i = 0; i<dim; i++)
        cout << array[i] << "  "; 
    
    cout << endl;
    selection(array, dim);
}
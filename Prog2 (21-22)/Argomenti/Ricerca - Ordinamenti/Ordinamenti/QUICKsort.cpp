#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void swap(int *a, int *b){                             // come parametri vanno passati i valori derefeernziati
    int n1 = *a; 
    *a = *b;
    *b = n1;
}

int partition(int* array, int start, int end){
    int pivot = array[end];
    int j = start-1; 
    for (int i = start; i<end; i++){
        if(array[i]<=pivot){
            j++;                                        // prima si incrementa la j, poi si fa lo swap
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[j+1], &array[end]);
    return (j+1);
}

void quicksort(int* array, int start, int end){
    if(start>=end)
        return;
    
    int mid = partition(array, start, end);
    quicksort(array, start, mid-1);
    quicksort(array, mid+1, end);
}

int main(){
    srand(time(NULL));
    int dim;
    cout << "dim: ";
    cin >> dim;
    int* array = new int[dim];

    int min, max;
    cout << "range: ";
    cin >> min >> max;

    for(int i = 0; i<dim; i++)
        array[i] = rand()%(max-min+1)+min;
    
    for(int i = 0; i<dim; i++)
        cout << array[i] << " "; 

    cout << endl;

    quicksort(array, 0, dim-1);
    for(int i = 0; i<dim; i++)
        cout << array[i] << " ";   
}
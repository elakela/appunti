#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

void merge(int* array, int start, int end, int mid){
    int dim1 = mid-start+1;
    int dim2 = end-mid;

    int* L = new int[dim1+1];
    int* R = new int[dim2+1];

    for(int i = 0; i<dim1; i++){
        L[i] = array[start+i];
    }

    for(int j = 1; j<=dim2; j++){
        R[j-1] = array[mid+j];
    }

    L[dim1] = INT_MAX;
    R[dim2] = INT_MAX;

    int i = 0;
    int j = 0;
    int k = start; 
    for(k = start; k<=end; k++){
        if(L[i] < R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
    }

        //alla fine BISOGNA fare il DELETE
        delete[] L;
        delete[] R;
}  


void mergesort(int* array, int start, int end){
    if(start<end){
        int midpoint = floor((start+end)/2.0);
        mergesort(array, start, midpoint);
        mergesort(array, midpoint+1, end);
        merge(array, start, end, midpoint);
    }
}

int main(){
    srand(time(NULL));
    int dim;
    int start = 0;

    cout << "dim = ?" << endl;
    cin >> dim;
    int end = dim-1;
    int* array = new int[dim];
    int max, min; 
    cout << "indicare il range: " << endl;
    cin>>min >> max;
    for (int i = 0; i<dim; i++){
        array[i] = rand()%(max-min+1)+min;
    }

    for(int i = 0; i<dim; i++)
        cout << array[i] << "  ";
    mergesort(array, start, end);
    cout << endl;
    for(int i = 0; i<dim; i++)
        cout << array[i] << "  ";
}
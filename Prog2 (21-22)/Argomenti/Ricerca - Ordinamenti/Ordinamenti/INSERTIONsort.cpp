#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void Insertion(int* array, int dim){
  
    int temp;
    int j; 
    for (int i = 1; i<dim; i++){
        temp = array[i];
            for(j = i; j>0; j--){           //j va decrementato
                if(temp<array[j-1]){        // va confrontato col precedente di j
                    array[j] = array[j-1];
                }
            else break;
            }
        array[j] = temp;
    }

}

int main(){
    srand(time(NULL));
    int dim; 
    cout << "inserire la dimensione dell'arary: "<< endl;
    cin >> dim;

    int* array = new int[dim];
    int min, max;
    cout << "inserire il range di valori:" << endl;
    cin >> min >> max;

    for(int i = 0; i<dim; i++)
        array[i] = rand()%(max-min+1)+min;

    for (int i = 0; i<dim; i++)
        cout << array[i] << "  ";
    
    cout << endl;
    Insertion(array, dim);

    
    for (int i = 0; i<dim; i++)
        cout << array[i] << "  ";
    
}
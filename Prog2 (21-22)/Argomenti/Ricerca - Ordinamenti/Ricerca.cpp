#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//algoritmo ricorsivo
// int ToSearch(int val, int* array, int start, int end){
//     if(start!=end){
//         int midpoint = start + ((end-start)/2);
//         if(val < array[midpoint]){
//             end = midpoint;
//             ToSearch(val, array, start, end);
//         }
//         else if(val>array[midpoint]){
//             start = midpoint+1;
//             ToSearch(val, array, start, end);
//         }
//         else{
//             return midpoint;
//         }
//     }

//     else if(start == end){
//         return -1;
//     }
// }

//algoritmo iterativo
int search(int* array, int dim, int val){
    int start = 0; 
    int end = dim-1;
    bool found = false;
    while (!found && (start!=end)){
        int midpoint = start + ((end-start)/2);
        if(val == array[midpoint]){
            return midpoint;
        }
        else if (val<array[midpoint]){
            end = midpoint;
        }
        else{
            start = midpoint+1;
        }
    }
    
    return -1;    
}


int main(){
    srand(time(NULL));
    int dim;
    cout << "inserire la dimensione: " << endl;
    cin >> dim;
    
    int* array = new int[dim];

    int max;
    cout << "inserire il massimo valore inseribile nell'array" << endl;
    cin >> max;

    for(int i = 0; i<dim; i++){
        array[i] = rand()%(max+1);
    }
    
    cout << "\t";
    for(int i = 0; i<dim; i++){
        cout << array[i] << "   ";
    }
    cout << endl;

    // // #pragma region "Ricorsione"
    // int end = dim-1;
    // int start = 0; 
    // int val;
    // cout << "inserire un valore da cercare: " << endl;
    // cin >> val;
    // int pos = ToSearch(val, array, start, end);
    // if (pos == -1){
    //     cout << "sorry, value not found" << endl;
    // }
    // else{
    //     cout << "value " << val << " found here: " << pos;
    // }
    // #pragma endregion

    #pragma region "Iterazione"
    int val;
    cout << "inserire un valore da cercare: " << endl;
    cin >> val;
    int pos = search(array, dim, val);
    if(pos!=-1){
        cout << "value " << val << " found here:" << pos << endl;
    }

    else{
        cout << " value " << val << "not found" << endl;
    }

}

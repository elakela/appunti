#include "bst.h"

int main(){
    BST<int> albero;
    cout << albero.isEmpty() << endl;
    system("pause"); 
    system("cls");

    albero.insert(23);
    albero.insert(16);
    albero.insert(48);
    albero.insert(34);
    albero.insert(32); 
    albero.insert(36);
    albero.inorder();
    system("pause"); 
    system("cls");
    albero.postorder();
    system("pause"); 
    system("cls");
    albero.preorder();
    system("pause"); 
    system("cls");

    cout << "il minimo dell'albero: " << *(albero.min()) << endl;
    cout << "il massimo dell'albero: " << *(albero.max()) << endl;
    system("pause"); 
    system("cls");

    cout << "il successore della radice e':" << *(albero.suc(albero.search(23)));
    int n; 
    cout << "di quale altro nodo vuoi conoscere il successore?" << endl;
    cin >> n;
    if((albero.suc(albero.search(n)))){
        cout << "il successore di " << n << " e': " << *(albero.suc(albero.search(n)));
    }
    else{
        cout << "errore" << endl;
    }
    system("pause"); 
    system("cls");

    cout << "il predecessore della radice e':" << *(albero.prec(albero.search(23)));
    cout << "di quale altro nodo vuoi conoscere il predecessore?" << endl;
    cin >> n;
    if((albero.prec(albero.search(n)))){
        cout << "il successore di " << n << " e': " << *(albero.prec(albero.search(n)));
    }
    else{
        cout << "errore" << endl;
    }
    system("pause"); 
    system("cls");

    albero.remove(16);
    albero.remove(48);
    albero.remove(34);
    albero.inorder();
    system("pause"); 
    system("cls");  
    
 }
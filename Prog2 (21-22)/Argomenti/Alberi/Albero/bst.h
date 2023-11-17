#ifndef BST_H
#define BST_H
#include "node.h"

template <typename T>
class BST{
    private: 
    Node<T>* root;

    public: 
    BST(){
        root = nullptr;
    }

    //controllo se è vuota
    bool isEmpty(){
        return root == nullptr;
    }

    #pragma region
    void insert(T val){
        if(this->isEmpty()){
            root = new Node<T>(val);
            return;
        }

        insert(root, val);
    }

    void insert (Node<T>* ptr, T val){
        if (ptr == nullptr){
            ptr = new Node<T>(val);
        }

        if (ptr->left == nullptr && val <= ptr->val){
            ptr->left = new Node<T>(val);
            ptr->left->setParent(ptr);  //bisogna settare il parent
            return;
        }

        else if (ptr->right == nullptr && val > ptr->val){
            ptr->right = new Node<T>(val);
            ptr->right->setParent(ptr); //bisogna settare il parent
            return;
        }

        else if(val <= ptr->val){
            insert(ptr->left, val);
        }

        else{
            insert(ptr->right, val);
        }
    }

    #pragma endregion

    #pragma region "Visit"
    void visit(Node<T>* ptr){
        cout << *ptr;
    }

    void inorder(Node<T>* ptr){
        if(ptr == nullptr){
            return;
        }
        
        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }

    void inorder(){
        inorder(root);
    }

    void preorder(Node<T>* ptr){
        if(ptr == nullptr){
            return;
        }
        
        visit(ptr);
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(Node<T>* ptr){
        if(ptr == nullptr){
            
            return;
        }
        
        postorder(ptr->left);
        postorder(ptr->right);
        visit(ptr);
    }
    
    void postorder(){
        postorder(root);
    }
    
    #pragma endregion

    #pragma region "Ricerche"
    Node<T>* min(){
        return min(root);
    }

    Node<T>* min(Node<T>* ptr){
        if(isEmpty()){
            return nullptr;
        }
        while(ptr->left){
            ptr = ptr->left;
        }

        return ptr;
    }

    Node<T>* max(){
        return max(root);
    }

    Node<T>* max(Node<T>* ptr){
        if(isEmpty()){
            cout << "empty bst" << endl;
            return nullptr;
        }
        while(ptr->right){
            ptr = ptr->right;
        }

        return ptr;
    }

    Node<T>* suc(Node<T>* x){
        if(x == nullptr){
            return nullptr;
        }

        if(x->right){
            return min(x->right);
        }

        Node<T>* y = x->parent;
        while(y!=nullptr && x == y->right){
            x = y;
            y = x->parent;
        }

        return y;
    }

    Node<T>* prec(Node<T>* x){
        if(x == nullptr){
           return nullptr;
        }

        if(x->left){
            x = max(x->left);
            return x;
        }

        Node<T>* y = x->parent;
        while(y!=nullptr && x == y->left){
            x = y;
            y = x->parent;
        }

        return y;
    }

    Node<T>* search(T val){
        return search(val, root);
    }
    Node<T>* search (T val, Node<T>* ptr){
      if(ptr == nullptr){
        return nullptr;
      }
      if(val == ptr->val){
            return ptr;
        }

        if (val< ptr->val){
            return search(val, ptr->left);
        }

        if(val > ptr->val){
            return search(val, ptr->right);
        }

        return nullptr;
    }
    
    #pragma endregion

    #pragma region "Rimozioni"

    Node<T>* remove(Node<T>* ptr){
        if (ptr->left == nullptr && ptr->right == nullptr){
            if(ptr == ptr->parent->left){
                ptr->parent->left = nullptr;
            }
            else{
                ptr->parent->right = nullptr;
            }
            return ptr;
        }

        if(ptr->left == nullptr && ptr->right!=nullptr){
            ptr->right->parent = ptr->parent;
            if(ptr == ptr->parent->left){
                ptr->parent->left = ptr->right;
            }
            else{
                ptr->parent->right = ptr->right;
            }
            return ptr;
        }

        if(ptr->left != nullptr && ptr->right==nullptr){
            ptr->left->parent = ptr->parent;
            if(ptr == ptr->parent->left){
                ptr->parent->left = ptr->left;
            }
            else{
                ptr->parent->right = ptr->left;
            }
            return ptr;
        }

        return nullptr;
    }

    Node<T>* remove(T val){
        if(isEmpty()){
            cout << "empty bst" << endl;
            return nullptr;
        }

        Node<T>* node = this->search(val);
        if (node == nullptr){
            cout << "value not found" << endl;
            return nullptr;
        }

        Node<T>* temp = remove(node);
        if (temp!=nullptr){
            return temp;
        }

        Node<T>* sux = suc(node);
        T swap = node->val;
        node->val = sux->val;
        sux->val = val;

        temp = remove(sux);
        return temp;
    }
    #pragma endregion

};
#endif
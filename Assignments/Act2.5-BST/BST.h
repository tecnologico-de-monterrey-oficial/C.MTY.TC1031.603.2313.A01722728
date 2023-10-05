#ifndef BST_h
#define BST_h

#include "TNode.h"

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
public:
    BST();
    void insert(T data);
    void print();
    bool find(T data);
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    if(isEmpty()){
        root = new TNode<T>(data);
    }else{
        TNode<T>* aux = root;
        while(aux != nullptr){
            if(data < aux->data){
                if(aux->left == nullptr){
                    aux->left = new TNode<T>(data);
                    return;
                }else{
                    aux = aux->left;
                }
            }else{
                if(aux->right == nullptr){
                    aux->right = new TNode<T>(data);
                    return;
                }else{
                    aux = aux->right;
                }
            }
        }

    }

}

template <class T>
bool BST<T>::find(T data) {
    if(isEmpty()){
        return false;
    }else{
        TNode<T>* aux = root;
        while(aux != nullptr){
            if(data == aux->data){
                return true;
            }else if(data < aux->data){
                aux = aux->left;
            }else{
                aux = aux->right;
            }
        }
        return false;
    }
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif /* BST_h */
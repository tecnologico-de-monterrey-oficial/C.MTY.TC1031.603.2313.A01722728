#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <cmath>

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
public:
    BST();
    void insert(T data);
    TNode<T>* findNode(T data);
    void remove(T data);
    void print();
    bool find(T data);
    void visit(int mode);
    int height();
    void ancestors(T data);
    int whatLevelamI(T data);
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol esta vacío
    if (isEmpty()) {
        // El está vacío
        // le asignamos a root un nuevo nodo con el valor de data
        root = new TNode<T>(data);
    } else {
        // El no esta vacío
        // Creamos un apuntador auxiliar igual a root
        TNode<T>* aux = root;
        // Recorremos el árbol hasta insertar el valor nuevo (aux != nullptr)
        while (aux != nullptr) {
            // Validamos si data es menor a aux->data
            if (data < aux->data) {
                // Si es menor
                // Validamos si el apundator del lado izquierdo de aux es nulo
                if (aux->left == nullptr) {
                    // Si es nulo
                    // Apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // No es nulo
                    // Apuntamos aux al lado izquiero de aux
                    aux = aux->left;
                }
            } else {
                // Es mayor o igual 
                // Validamos si el apundator del lado derecho de aux es nulo
                if (aux->right == nullptr) {
                    // Si es nulo
                    // Apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // No es nulo
                    // Apuntamos aux al lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
TNode<T>* BST<T>::findNode(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    while (aux != nullptr) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // Regresamos 
            return aux;
        } else {
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // No lo encontramos
    return nullptr;
}

template <class T>
void BST<T>::remove(T data) {
    
    TNode<T>* aux = findNode(data);
    //if left=nullptr right is new root
    if(aux->left == nullptr) {
        aux = aux->right;
        return;
    }

    //find largest node in left subtree
    TNode<T>* largest=aux->left;
    while(largest->right != nullptr) {
        largest = largest->right;
    }
    //copy value to node to be deleted
    aux->data = largest->data;
    //delete duplicate node
    delete largest;

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
bool BST<T>::find(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    while (aux != nullptr) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // Regresamos 
            return true;
        } else {
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // No lo encontramos
    return false;
}

template <class T>
int BST<T>::height(){
    if (isEmpty()) {
        return 0;
    } else {
        int left = 0;
        int right = 0;
        TNode<T>* aux = root;
        while (aux->left != nullptr) {
            left++;
            aux = aux->left;
        }
        aux = root;
        while (aux->right != nullptr) {
            right++;
            aux = aux->right;
        }
        return max(left, right);
    }
}

template <class T>
void BST<T>::ancestors(T data){

}

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif /* BST_h */
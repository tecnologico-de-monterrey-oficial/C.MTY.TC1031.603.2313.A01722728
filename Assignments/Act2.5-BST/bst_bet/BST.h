#ifndef BST_H
#define BST_H
#include "nodeT.h"

template <typename T>
class BST {
  private:
    nodeT<T> *root; // no espeficicamos el tipo de dato a guardar en el nodo
  public:
    BST();
    ~BST();
    void Delete(nodeT<T>*);
    bool search(T);
    void add(T);
    void pop(T);
};

template <typename T>
BST<T>::BST() {
    root = NULL;
}


template <typename T>
BST<T>::~BST() {
    Delete(root);
}

template <typename T>
void BST<T>::Delete(nodeT<T>* nodo) {
    if (nodo == NULL)
        return;
    Delete(nodo->Left());
    Delete(nodo->Right());
    delete nodo;
}

template <typename T>
bool BST<T>::search(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    while (p != NULL) {
        if (p->Data() == data)
            return true;
        p = p->Data() > data ? p->Left() : p->Right(); // avanzamos a la izquierda o derecha segun el orden entre data y el data del nodo
    }
    return false; // no se encontro el dato
}

template <typename T>
void BST<T>::add(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL;
    nodeT<T> *nodo;
    if (search(data))
        return; // ya esta el dato en nuestro arbol
    nodo = new nodeT<T>(data);
    while (p!= NULL) {
        padre = p;
        p = p->Data() > data ? p->Left() : p->Right();
    }
    if (padre == NULL) {
        root = nodo; // se trata del primer elemento a agregar
    }
    else { // ya existe al menos un elemento en el arbol
        if (padre->Data() > data) {
            padre->setLeft(nodo); // agregarlo a izq
        }
        else {
            padre->setRight(nodo);// agregarlo a la derecha
        }
    }
}

template <typename T>
void BST<T>::pop(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL;
    if (!search(data))
        return; // el dato no esta en nuestro arbol
    while (p->Data() != data) {
        padre = p;
        p = p->Data() > data ? p->Left() : p->Right();
    }
    if (p->Left() == NULL && p->Right() == NULL) { // se trata de un nodo hoja
        delete p;
        if (padre == NULL) { // solo quedaba un elemento
            root = NULL; // se vacia el arbol
        }
        else {
            if (padre->Data() > data)
                padre->setLeft(NULL);
            else
                padre->setRight(NULL);
        }
    }
    else if (p->Left() == NULL || p->Right() == NULL) { // nodo con solo un hijo
        nodeT<T> *subarbol;
        subarbol = p->Left() != NULL ? p->Left() : p->Right();
        delete p;
        if (padre == NULL) { // es equivalente a preguntar p == root o root->Data() == data
            root = subarbol;
        }
        else {
            if (padre->Data() > data)
                padre->setLeft(subarbol);
            else
                padre->setRight(subarbol);
        }
    }
    else { // nodo con dos hijos
        nodeT<T> *sucesor;
        sucesor = p->Right(); // no es nulo porque el nodo p tiene dos hijos
        padre = p; // valor inicial de padre
        while (sucesor->Left() != NULL) {
            padre = sucesor;
            sucesor = sucesor->Left();
        }
        nodeT<T> *subarbol = sucesor->Right();
        p->setData(sucesor->Data()); // se reemplaza la informacion en p
        delete sucesor; // libera nodo
        if (padre == p) { // no se avanza el padre
            padre->setRight(subarbol);
        }
        else {
            padre->setLeft(subarbol); // subarbol puede ser NULL si el nodo era nodo hoja
        }
    }
}

#endif
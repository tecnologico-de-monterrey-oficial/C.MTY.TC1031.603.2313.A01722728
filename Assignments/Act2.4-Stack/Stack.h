#ifndef Stack_h
#define Stack_h

#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
public:
    Stack();
    void push(T data); // Agrego un elemento a la pila
    void pop(); // Elimina el elemento de arriba de la pila
    T top(); // regresa el elemento de arriba de la pila
    bool isEmpty();
};

#endif
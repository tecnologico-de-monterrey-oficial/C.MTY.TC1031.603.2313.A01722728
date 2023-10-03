#ifndef Queue_h
#define Queue_h
#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    void push(T data); // Inserta un elemento en la fila
    void pop(); // Elimina el elemento al principio de la fila
    void front(); // Regresa el elemento al principio de la fila
    void print(); // Imprime los elementos de la fila
    bool isEmpty();
};

template <class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    print();
}

template <class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        cout << "removed ";
        front();
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }
    print();
}

template <class T>
void Queue<T>::front() {
    if (!isEmpty()) {
        cout << "front: ";
        cout <<head->data << endl;
    }else{
        cout << "Queue is empty" << endl;
    }
}

template <class T>
void Queue<T>::print() {
    cout << "Queue: ";
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr && tail == nullptr;
}



#endif
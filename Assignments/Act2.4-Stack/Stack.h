#ifndef Stack_h
#define Stack_h

#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    Node<T>* head;
public:
    Stack();
    void push(T data); // Agrego un elemento a la pila
    void pop(); // Elimina el elemento de arriba de la pila
    void top(); // regresa el elemento de arriba de la pila
    void print(); // Imprime los elementos de la pila
    bool isEmpty();
};

template <class T>
Stack<T>::Stack() {
    head = nullptr;
}

template <class T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    print();
}

template <class T>
void Stack<T>::pop() {
    if(head == nullptr){
        cout << "Stack is empty" << endl;
    }else{
        top();
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        print();
    }
}

template <class T>
void Stack<T>::top() {
    if(head == nullptr){
        cout << "Stack is empty" << endl;
    }else{
        cout << "Top: " << head->data << endl;
    }
}

template <class T>
void Stack<T>::print() {
    if (head == nullptr) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack: ";
        Node<T>* aux = head;
        while (aux != nullptr) {
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}


#endif
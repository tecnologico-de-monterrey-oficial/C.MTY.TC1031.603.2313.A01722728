#ifndef Queue_h
#define Queue_h

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    void push(T data); // Inserta un elemento en la fila
    void pop(); // Elimina el elemento al principio de la fila
    T front(); // Regresa el elemento al principio de la fila
    bool isEmpty();
};

#endif
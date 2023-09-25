#ifndef LinkedList_h
#define LinkedList_h
#include "node.h"

template <class T>
class LinkedList    
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    void print();
    bool isEmpty();
    void insert(int index, T data);
    int findData(T data);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    // Estos mas los que faltan de tarea
    void deleteData(T data);
    void deleteAt(int index);
    T getData(int index);
    T operator[](int index);
    void operator=(LinkedList<T> list);
    void deleteAll();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
    // Asignamos el head a un nuevo nodo con data y head
    head = new Node<T>(data, head);
    // Aumentamos el tamaño de la lista
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
    if (isEmpty())
    {
        // La lista esta vacia
        head = new Node<T>(data);
    }
    else
    {
        // Definamos un apuntador auxiliar igual a head
        Node<T> *aux = head;
        // Recoremos la lista
        while (aux->next != nullptr)
        {
            // recorrer aux
            aux = aux->next;
        }
        // Agregamos un nuevo nodo a aux
        aux->next = new Node<T>(data);
        // aumentamos el tamaño
    }

    size++;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void LinkedList<T>::insert(int index, T data)
{
    // validamos que el indice exita en la lista
    if (index >= 0 && index < size)
    {
        // apuntador auxiliar igual a head
        Node<T> *aux = head;
        // creamos indice auxiliar igual a 0
        int auxIndex = 0;
        // recorremos la lista hasta encontrar el indicce que queremos
        while (index != auxIndex)
        {
            // recorremos auxiliar
            aux = aux->next;
            // incrementamos auxIndex
            auxIndex++;
        }
        // insertamos el nuevo elemento
        aux->next = new Node<T>(data, aux->next);
        // incrementamos size
        size++;
    }
    else
    {
        throw out_of_range("El indice esta fuera del rango");
    }
}

template <class T>
int LinkedList<T>::findData(T data)
{
    // apuntador auxiliar igual a head
    Node<T> *aux = head;
    // creamos un contador
    int contador = 0;
    while (aux->next != nullptr)
    {
        if (aux->data == data)
        {
            return contador;
        }
        // recorrer aux
        aux = aux->next;
        contador++;
    }
    return -1;
}

template <class T>
void LinkedList<T>::print()
{
    // Apuntador auxiliar
    Node<T> *aux = head;
    while (aux != nullptr)
    {
        // Imprimimos el valor de data
        cout << aux->data;
        if (aux->next != nullptr)
        {
            cout << "->";
        }
        // recorremos aux el apuntador de next
        aux = aux->next;
    }
    // Imprimimos un salto de linea
    cout << endl;
}
template <class T>
void LinkedList<T>::updateData(T data, T newData)
{
    // apuntador auxiliar igual a head
    Node<T> *aux = head;
    while (aux->next != nullptr)
    {
        if (aux->data == data)
        {
            aux->data = newData;
            return;
        }
        // recorrer aux
        aux = aux->next;
    }
    cout << "Dato no encontrado" << endl;
}

template <class T>
void LinkedList<T>::updateAt(int index, T data)
{
    Node<T> *aux = head;
    int auxIndex = 0;
    while (aux != nullptr)
    {
        if (auxIndex == index)
        {
            aux->data = data;
            return;
        }
        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range("El indice esta fuera del rango");
}

template <class T>
void LinkedList<T>::deleteData(T data)
{
    Node<T> *aux = head;
    Node<T> *aux2 = head;
    while (aux->next != nullptr)
    {
        if (aux->data == data)
        {
            aux2->next = aux->next;
            delete aux;
            return;
        }
        aux2 = aux;
        aux = aux->next;
    }
    cout << "Dato no encontrado" << endl;
}

template <class T>
void LinkedList<T>::deleteAt(int index)
{
    Node<T> *aux = head;
    Node<T> *aux2 = head;
    int auxIndex = 0;
    while (aux != nullptr)
    {
        if (auxIndex == index)
        {
            aux2->next = aux->next;
            delete aux;
            return;
        }
        aux2 = aux;
        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range("El indice esta fuera del rango");
}

template <class T>
T LinkedList<T>::getData(int index)
{
    Node<T> *aux = head;
    int auxIndex = 0;
    while (aux != nullptr)
    {
        if (auxIndex == index)
        {
            return aux->data;
        }
        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range("El indice esta fuera del rango");
}

template <class T>
T LinkedList<T>::operator[](int index)
{
    Node<T> *aux = head;
    int auxIndex = 0;
    while (aux != nullptr)
    {
        if (auxIndex == index)
        {
            return aux->data;
        }
        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range("El indice esta fuera del rango");
}

template <class T>
void LinkedList<T>::deleteAll()
{
    Node<T> *aux = head;
    while (aux != nullptr)
    {
        head = aux->next;
        delete aux;
        aux = head;
    }
    size = 0;
}

template <class T>
void LinkedList<T>::operator=(LinkedList<T> list)
{   
    deleteAll();
    Node<T> *aux = list.head;
    while (aux != nullptr)
    {
        addLast(aux->data);
        aux = aux->next;
    }
}


#endif
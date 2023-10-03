#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "DNode.h"

template <class T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size = 0;
public:
    DoublyLinkedList();
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    int findData(T data); // Busca el valor dado y regresa la posición donde se encuentra
    T getData(int index); // Regresa el valor en la posición index
    void updateAt(int index, T data); // Actualiza el valor en la posición index
    void updateData(T data, T newData); // Actualiza el valor dado
    bool deleteAt(int index);
    bool deleteData(T data); // Elimina el valor dado
    T& operator[](int index); // Regresa/Actualiza el valor en la posición index
    void operator=(DoublyLinkedList<T> list); //Iguala la LinkedList con la otra 
    void clear(); // Borra toda la lista
    void sort(); // Ordena la lista (QuickSort)
    void duplicate(); // Duplica la lista
    void removeDuplicates(); // Elimina los valores duplicados
    void print(string mode);
    bool isEmpty();
    int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::addFirst(T data) {
    // Asignamos a head un nuevo nodo con data, head y nullptr
    head = new DNode<T>(data, head, nullptr);
    // Validamos si la lista estaba vacía
    if (head->next == nullptr) {
        // Actualizamos tail
        tail = head;
    } else {
        // Actualizamos el nodo que estaba al principio
        head->next->prev = head;
    }
    // Incrementamos el tamaño de la lista
    size++;
}

template <class T>
void DoublyLinkedList<T>::addLast(T data) {
    // Asignamos a tail un nuevo nodo con data, null ptr y tail
    tail = new DNode<T>(data, nullptr, tail);
    // Validamos si la lista estaba vacía
    if (tail->prev == nullptr) {
        // Actualizamos tail
        head = tail;
    } else {
        // Actualizamos el nodo que estaba al principio
        tail->prev->next = tail;
    }
    // Incrementamos el tamaño de la lista
    size++;
}

template<class T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // Validamos que el índice exista en la lista
    if (index >= 0 && index < size) {
        // Definimos una apuntador auxiliar
        DNode<T>* aux;
        if (index <= (size - 1) / 2) {
            // Creamos un apuntador auxiliar igual a head;
            aux = head;
            // Creamos un índice auxiliar igual a 0
            int auxIndex = 0;
            // Recorremos la lista hasta enocntrar el indice que queremos
            while (index != auxIndex) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else {
            // Creamos un apuntador auxiliar igual a head;
            aux = tail;
            // Creamos un índice auxiliar igual a 0
            int auxIndex = size-1;
            // Recorremos la lista hasta enocntrar el indice que queremos
            while (index != auxIndex) {
                // Recorremos aux
                aux = aux->prev;
                // Incrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Insertamos el nuevo elemento
        DNode<T>* aux2 = new DNode<T>(data, aux->next, aux);
        aux->next = aux2;
        // Validamos si ya no hay elementos a la derecha de aux
        if (aux2->next == nullptr) {
            // Actualizarmos tail
            tail = aux2;
        } else {
            // Actualizamos el apuntar prev del nodo después de aux
            aux2->next->prev = aux2;
        }
        // Incrementamos el valor de size
        size++;
    } else {
        throw out_of_range("El índice esta fuera de rango");
    }
}

template <class T>
int DoublyLinkedList<T>::findData(T data) {
    // Definimos un apuntador auxiliar igual a head
    DNode<T>* aux = head;
    // Definimos un índice auxiliar igual a 0
    int auxIndex = 0;
    // Recorremos la lista
    while (aux != nullptr) {
        // Validamos si el valor del nodo es igual al valor buscado
        if (aux->data == data) {
            // Regresamos el valor del índice
            return auxIndex;
        }
        // Recorremos aux
        aux = aux->next;
        // Incrementamos el valor de auxIndex
        auxIndex++;
    }
    // Regresamos -1 si no se encuentra el valor
    return -1;
}

template <class T>
T DoublyLinkedList<T>::getData(int index) {
    // Validamos que el índece exista en la lista
    if (index >= 0 && index < size) {
        // Definimos un apuntador auxiliar
        DNode<T>* aux;
        // Validamos si recorremos la lista de derecha a izquierda o al reves
        if (index <= (size - 1) / 2) {
            // Definimos un índex auxiliar igual a 0
            int auxIndex = 0;
            // Definimos un apuntador auxiliar igual a head
            aux = head;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el valor de índice auxliar
                auxIndex++;
            } 
        } else {
            // Definimos un índex auxiliar igual a size - 1
            int auxIndex = size - 1;
            // Definimos un apuntador auxiliar igual a tail
            aux = tail;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->prev;
                // Decrementamos el valor de índice auxliar
                auxIndex--;
            } 
        }
        // Regresamos el valor del nodo
        return aux->data;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
T& DoublyLinkedList<T>::operator[](int index) {
    // Validamos que el índece exista en la lista
    if (index >= 0 && index < size) {
        // Definimos un apuntador auxiliar
        DNode<T>* aux;
        // Validamos si recorremos la lista de derecha a izquierda o al reves
        if (index <= (size - 1) / 2) {
            // Definimos un índex auxiliar igual a 0
            int auxIndex = 0;
            // Definimos un apuntador auxiliar igual a head
            aux = head;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el valor de índice auxliar
                auxIndex++;
            } 
        } else {
            // Definimos un índex auxiliar igual a size - 1
            int auxIndex = size - 1;
            // Definimos un apuntador auxiliar igual a tail
            aux = tail;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->prev;
                // Decrementamos el valor de índice auxliar
                auxIndex--;
            } 
        }
        // Regresamos el valor del nodo
        return aux->data;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // Definimos un apuntador auxiliar igual a head
    DNode<T>* aux = head;
    // Recorremos la lista
    while (aux != nullptr) {
        // Validamos si el valor del nodo es igual al valor buscado
        if (aux->data == data) {
            // Actualizamos el valor del nodo
            aux->data = newData;
            // Terminamos la función
            return;
        }
        // Recorremos aux
        aux = aux->next;
    }
    // Lanzamos una excepción si no se encuentra el valor
    throw out_of_range("El valor no se encuentra en la lista");
}

template <class T>
void DoublyLinkedList<T>::updateAt(int index, T data) {
    // Validamos que el índece exista en la lista
    if (index >= 0 && index < size) {
        // Definimos un apuntador auxiliar
        DNode<T>* aux;
        // Validamos si recorremos la lista de derecha a izquierda o al reves
        if (index <= (size - 1) / 2) {
            // Definimos un índex auxiliar igual a 0
            int auxIndex = 0;
            // Definimos un apuntador auxiliar igual a head
            aux = head;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el valor de índice auxliar
                auxIndex++;
            } 
        } else {
            // Definimos un índex auxiliar igual a size - 1
            int auxIndex = size - 1;
            // Definimos un apuntador auxiliar igual a tail
            aux = tail;
            // Recorremos la lista
            while (auxIndex != index) {
                // Recorremos aux
                aux = aux->prev;
                // Decrementamos el valor de índice auxliar
                auxIndex--;
            } 
        }
        // Actualizamos el valor del nodo
        aux->data = data;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // Definimos una apuntador auxiliar
        DNode<T>* aux;
        if (index <= (size - 1) / 2) {
            // Creamos un apuntador auxiliar igual a head;
            aux = head;
            // Creamos un índice auxiliar igual a 0
            int auxIndex = 0;
            // Recorremos la lista hasta enocntrar el indice que queremos
            while (index != auxIndex) {
                // Recorremos aux
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else {
            // Creamos un apuntador auxiliar igual a head;
            aux = tail;
            // Creamos un índice auxiliar igual a 0
            int auxIndex = size-1;
            // Recorremos la lista hasta enocntrar el indice que queremos
            while (index != auxIndex) {
                // Recorremos aux
                aux = aux->prev;
                // Incrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Validamos si aux es el primer nodo
        if (aux->prev == nullptr) {
            head = aux->next;
        } else {
            aux->prev->next = aux->next;
        }
        // Validamos si aux es el último nodo
        if (aux->next == nullptr) {
            tail = aux->prev;
        } else {
            aux->next->prev = aux->prev;
        }
        // Decrementamos el valor de size
        size--;
        // Liberamos de memoria el nodo que esta en aux
        delete aux;
        // regresamos verdadero
        return true;
    } else {
        return false;
    }
}

template <class T>  
bool DoublyLinkedList<T>::deleteData(T data) {
    // Definimos un apuntador auxiliar igual a head
    DNode<T>* aux = head;
    // Recorremos la lista
    while (aux != nullptr) {
        // Validamos si el valor del nodo siguiente es igual al valor buscado
        if (aux->data == data) {
            // Validamos si es el primer elemento
            if (aux->prev == nullptr) {
                head = aux->next;
            } else {
                aux->prev->next = aux->next;
            }
            // Validamos si es último elemento
            if (aux->next == nullptr) {
                tail = aux->prev;
            } else {
                aux->next->prev = aux->prev;
            }
            // Borramos aux2
            delete aux;
            // Decrementamos el valor de size
            size--;
            // Terminamos la función
            return true;
        }
        // Recorremos aux
        aux = aux->next;
    }
    // Lanzamos una excepción si no se encuentra el valor
    return false;
}




template<class T>
void DoublyLinkedList<T>::print(string mode) {
    // Validamos si el modeo es asc o desc
    if (mode == "asc") {
        // Definimos un apuntador auxiliar que sea igual a head
        DNode<T>* aux = head;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->data;
            if (aux->next != nullptr) {
                cout << "->";
            } 
            // recorremos aux al apuntador de next
            aux = aux->next;
        }
        // Imprimos un salto de linea
        cout << endl;
    } else {
        // Definimos un apuntador auxiliar que sea igual a head
        DNode<T>* aux = tail;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->data;
            if (aux->prev != nullptr) {
                cout << "->";
            } 
            // recorremos aux al apuntador de next
            aux = aux->prev;
        }
        // Imprimos un salto de linea
        cout << endl;    
    }
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}




#endif /* DoublyLinkedList_h */
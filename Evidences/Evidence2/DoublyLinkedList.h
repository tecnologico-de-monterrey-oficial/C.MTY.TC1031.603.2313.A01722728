#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h


#include "DNode.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size = 0;
public:
    DoublyLinkedList();
    DNode* getHead();
    DNode* getTail();
    void sort(); 
    void quicksort(DNode* left, DNode* right);
    void push_back(Log data);
    void removeLast();
    Log& operator[](int index); // returns the value at index
    void operator=(DoublyLinkedList list); //Iguala la LinkedList con la otra 
    bool isEmpty();
    int getSize();
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DNode* DoublyLinkedList::getHead() {
    return head;
}

DNode* DoublyLinkedList::getTail() {
    return tail;
}


void DoublyLinkedList::quicksort(DNode* left, DNode* right) {
    if (left == nullptr || right == nullptr) {
        return;
    }
    if (left != right && left->prev != right) {
        DNode* pivot = left;
        DNode* i = left;
        DNode* j = right;
        while (i != j) {
            while (i != j && i->data < pivot->data) {
                i = i->next;
            }
            while (j != i && pivot->data < j->data) {
                j = j->prev;
            }
            if (i != j) {
                Log aux = i->data;
                i->data = j->data;
                j->data = aux;
            }
        }
        if (i != pivot) {
            Log aux = i->data;
            i->data = pivot->data;
            pivot->data = aux;
        }
        quicksort(left, i->prev);
        quicksort(i->next, right);
    }
}

void DoublyLinkedList::sort(){
    if (size > 1) {
        // Definimos un apuntador auxiliar igual a head
        DNode* aux = head;
        // Definimos un apuntador auxiliar2 igual a head
        DNode* aux2 = head;
        // Recorremos la lista
        while (aux != nullptr) {
            // Recorremos la lista
            while (aux2 != nullptr) {
                // Validamos si el valor de aux es mayor al valor de aux2
                if (aux2->data < aux->data) {
                    // Intercambiamos los valores
                    Log auxData = aux->data;
                    aux->data = aux2->data;
                    aux2->data = auxData;
                }
                // Recorremos aux2
                aux2 = aux2->next;
            }
            // Recorremos aux
            aux = aux->next;
            // Actualizamos aux2
            aux2 = aux;
        }
    }

}

void DoublyLinkedList::push_back(Log data) {
    if (isEmpty()) {
        head = new DNode(data);
        tail = head;
    }
    else {
        DNode* aux = tail;
        tail = new DNode(data);
        aux->next = tail;
        tail->prev = aux;
    }
    size++;
}

void DoublyLinkedList::removeLast() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DNode* aux = tail->prev;
            delete tail;
            tail = aux;
            tail->next = nullptr;
        }
        size--;
    }
}

Log& DoublyLinkedList::operator[](int index) {
    DNode* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

void DoublyLinkedList::operator=(DoublyLinkedList list) {
    head = list.head;
    tail = list.tail;
    size = list.size;
}

bool DoublyLinkedList::isEmpty() {
    return head == nullptr && tail == nullptr;
}

int DoublyLinkedList::getSize() {
    return size;
}

#endif /* DoublyLinkedList_h */
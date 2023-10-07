#pragma once
#include <iostream>
#include "Log.h"

template <typename T>
class DoubleLinkedListVector {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& val, Node* prevNode = nullptr, Node* nextNode = nullptr)
            : data(val), prev(prevNode), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    DoubleLinkedListVector() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedListVector() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value, tail, nullptr);
        if (tail) {
            tail->next = newNode;
        }
        tail = newNode;
        if (!head) {
            head = newNode;
        }
        size++;
    }

    void pop_back() {
        if (size == 0) {
            return;
        }
        if (size == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* prev = tail->prev;
            prev->next = nullptr;
            delete tail;
            tail = prev;
        }
        size--;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    size_t getSize() const {
        return size;
    }
    //function to sort the list using only < comparisons
    void sort() {
        Node* current = head;
        Node* index = nullptr;
        T temp;

        if (head == nullptr) {
            return;
        } else {
            while (current != nullptr) {
                index = current->next;

                while (index != nullptr) {
                    if (current->data < index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
    

};
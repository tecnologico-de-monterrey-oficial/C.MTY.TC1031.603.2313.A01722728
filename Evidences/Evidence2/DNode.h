 #pragma once 
 #include "Log.h"

struct DNode {
    Log data;
    DNode* next;
    DNode* prev;
    DNode();
    DNode(Log data);
    DNode(Log data, DNode* next, DNode* prev);
};

DNode::DNode() {
    next = nullptr;
    prev = nullptr;
}

DNode::DNode(Log data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}


DNode::DNode(Log data, DNode* next, DNode* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
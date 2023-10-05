#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<int> dll;
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);
    dll.insert(0, 0);
    dll.print("asc");


    return 0;
}
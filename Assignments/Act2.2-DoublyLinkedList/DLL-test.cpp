#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<string> dll;

    dll.addFirst("Cuchara");
    if (dll.deleteData("Cuchara")) {
        cout << "Se borró Cuchara" << endl;
    } else {
        cout << "No se borró Cuchara" << endl;
    }
    dll.print("asc");
    dll.print("desc");
    dll.addFirst("Tenedor");
    dll.addLast("Cucharita");
    dll.addLast("Cuchillo");
    dll.print("asc");
    dll.print("desc");
    dll.insert(0, "Plato");
    dll.print("asc");
    dll.print("desc");
    cout << dll[3] << endl;
    dll.updateAt(3,"Sartén");
    dll.updateData("Plato","Olla");
    dll.print("asc");
    dll.print("desc");
    dll.deleteData("Tenedor");
    dll.print("asc");
    dll.print("desc");
    dll.deleteData("Cuchillo");
    dll.print("asc");
    dll.print("desc");
    cout << "Find: " << dll.findData("Cucharita") << endl;
    cout << dll.getData(0) << endl;
    cout << dll[0] << endl;


    return 0;
}
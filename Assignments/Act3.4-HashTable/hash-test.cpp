#include <iostream>
#include <vector>
using namespace std;

#include "HashMatricula.h"

int main() {

    HashStudentId hashTable;
    hashTable.insert("7");
    hashTable.insert("17");
    hashTable.insert("6");
    hashTable.insert("33");
    hashTable.insert("28");
    hashTable.insert("52");
    hashTable.insert("76");
    hashTable.print();
    hashTable.remove("6");
    hashTable.remove("52");
    hashTable.print();
    cout << hashTable.findStudentId("76") << endl;
    hashTable.insert("39");
    hashTable.print();

    return 0;
}
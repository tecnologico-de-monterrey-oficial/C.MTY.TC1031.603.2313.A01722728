#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
    bst.insert(21);
    //bst.remove(20); // fix remove function
    bst.print();
    cout << bst.height() << endl;
    cout << endl;
    


    return 0;
}
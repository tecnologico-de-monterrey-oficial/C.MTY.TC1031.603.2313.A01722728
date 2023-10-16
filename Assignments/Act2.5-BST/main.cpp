#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
    bst.print();
    cout << endl;
    


    return 0;
}
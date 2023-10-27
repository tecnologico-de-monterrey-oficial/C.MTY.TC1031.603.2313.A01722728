#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(15);
    bst.insert(5);
    bst.insert(30);
    bst.insert(35);
    bst.insert(25);
    bst.insert(18);
    bst.print();
    
    bst.visit(1);
    bst.visit(2);
    bst.visit(3);
    cout << bst.height() << endl;
    cout << bst.whatLevelamI(10) << endl;
    bst.ancestors(5);


    return 0;
}
#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST<int> arbol;
    int a;
    for (int i = 0; i < 50; i++) {
        a = rand() % 100;
        cout << a;
        arbol.add(a);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
    cout << "Se agregan los elementos" << endl;
    for (int i = 0; i < 100; i++) {
        cout << arbol.search(i);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
    a = 0;
    while (!arbol.search(a)) {
        a++;
    }
    cout << "Primer elemento en el arbol es: " << a << endl;
    a++;
    while (!arbol.search(a)) {
        a++;
    }
    cout << "Segundo elemento en el arbol es: " << a << endl;
    arbol.pop(a);
    cout << "Se remueve elemento " << a << endl;
    for (int i = 0; i < 100; i++) {
        cout << arbol.search(i);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
}
#include <iostream>
using namespace std;

int main() {

    int a = 5;
    int* p;
    p = new int;
    *p = a;
    a = *p + 2;
    int *q;
    q = &a;
    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    a = 10;
    cout << "*q: " << *q << endl;

    return 0;
}
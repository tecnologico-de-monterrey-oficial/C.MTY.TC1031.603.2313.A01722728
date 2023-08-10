#include <iostream>
#include <vector>
#include "List.h"
using namespace std;


int main(){
    List<int> list;
    list.removeLast();
    list.insert(3);
    list.insert(4);
    list.insert(10);
    list.removeLast();
    list.insert(15);


    list.print();
    cout << "Size: " << list.getSize() << endl;
    cout << "Max value: " << list.getMax() << endl; 
    cout << "Value at index [1]: " << list.getData(1) << endl;

    return 0;
}
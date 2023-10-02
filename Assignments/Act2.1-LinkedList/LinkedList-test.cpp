#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{

    LinkedList<string> list;

    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    cout << list.getSize() << endl;
    list.print();
    list.addLast("Sarten");
    list.print();
    cout << list.findData("Olla") << endl;
    list.updateData("Olla", "Cuchillo");
    list.print();
    try
    {
        list.updateAt(1, "Salero");
    }
    catch (out_of_range e)
    {
        cout << e.what() << endl;
    }
    list.print();
    cout << list.getData(0) << " " << list.getData(2) << endl;
    cout << list[0] << " " << list[2] << endl;

    LinkedList<string> list2;
    list2 = list;
    list.print();
    list2.print();
}
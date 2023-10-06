#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#include "LinkedList.h"
#include "timer.cpp"

void createListInt(LinkedList<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.addLast(num);
  }
}

int main()
{
    int option;
    char keepGoing = 'y';
    char randomList = 'n';
    string operation;
    LinkedList <int> list;

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Menu de funciones
    vector<string> menu = {
        "addFirst", 
        "addlast", 
        "insert",
        "deleteData",
        "deleteAt",
        "getData",
        "updateData",
        "updateAt",
        "findData",
        "[]getData",
        "[]updateat",
        "=operator"
    };

    // Preguntar para generar lista aleatoria
    cout<<"create a random list? (y/n): ";
    cin>>randomList;
    if(randomList=='y'){
        int quantity;
        cout<<"quantity: ";
        cin>>quantity;
        createListInt(list, quantity);
        list.print();
    }

    cout<<"keep going? (y/n): ";
    cin>>keepGoing;

    while(keepGoing == 'y'){
        for(int i=0; i<menu.size(); i++){
            cout<<i<<". "<<menu[i]<<endl;
        }
        cout << "select an option: ";
        cin >> option;

        operation = menu[option % menu.size()];
        if(operation== "addFirst"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.addFirst(data);
            list.print();
        }else if(operation== "addlast"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.addLast(data);
            list.print();
        }else if(operation== "insert"){
            int index, data;
            cout<<"index: ";
            cin>>index;
            cout<<"data: ";
            cin>>data;
            list.insert(index, data);
            list.print();
        }
        else if(operation== "deleteData"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.deleteData(data);
            list.print();
        }
        else if(operation== "deleteAt"){
            int index;
            cout<<"index: ";
            cin>>index;
            list.deleteAt(index);
            list.print();
        }
        else if(operation== "getData"){
            int index;
            cout<<"index: ";
            cin>>index;
            try{
                cout<<list.getData(index)<<endl;
            }
            catch(out_of_range e){
                cout<<e.what()<<endl;
            }
        }
        else if(operation== "updateData"){
            int data, newData;
            cout<<"data: ";
            cin>>data;
            cout<<"newData: ";
            cin>>newData;
            list.updateData(data, newData);
            list.print();
        }
        else if(operation== "updateAt"){
            int index, newData;
            cout<<"index: ";
            cin>>index;
            cout<<"newData: ";
            cin>>newData;
            list.updateAt(index, newData);
            list.print();
        }
        else if(operation== "findData"){
            int data;
            cout<<"data: ";
            cin>>data;
            cout<<list.findData(data)<<endl;
        }
        else if(operation== "[]getData"){
            int index;
            cout<<"index: ";
            cin>>index;
            try{
                cout<<list[index]<<endl;
            }
            catch(out_of_range e){
                cout<<e.what()<<endl;
            }
        }
        else if(operation== "[]updateat"){
            int index, newData;
            cout<<"index: ";
            cin>>index;
            cout<<"newData: ";
            cin>>newData;
            list.updateAt(index, newData);
            list.print();
        }
        else if(operation== "=operator"){
            LinkedList<int> list2;
            list2 = list;
            list.print();
            list2.print();
        }
        else{
            cout<<"invalid option"<<endl;
        }

        // keepgoing command
        cout<<"keep going? (y/n): ";
        cin>>keepGoing;
    }

    
    

}
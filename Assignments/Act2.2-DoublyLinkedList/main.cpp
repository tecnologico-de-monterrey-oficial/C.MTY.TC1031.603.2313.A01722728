#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#include "DoublyLinkedList.h"
#include "timer.cpp"

void createListInt(DoublyLinkedList<int> &list, int quantity)
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
    DoublyLinkedList <int> list;

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Menu de funciones
    vector<string> menu = {
        "addfirst", 
        "addlast", 
        "insert",
        "deleteData",
        "deleteAt",
        "getData",
        "updateData",
        "updateAt",
        "findData",
        "[]getData",
        "=operator",
        "clear",
        "sort",
        "duplicate",
        "removeDuplicates"
    };

    // Preguntar para generar lista aleatoria
    cout<<"create a random list? (y/n): ";
    cin>>randomList;
    if(randomList=='y'){
        int quantity;
        cout<<"quantity: ";
        cin>>quantity;
        createListInt(list, quantity);
        list.print("asc");
    }
    
    cout<<"keep going? (y/n): ";
    cin>>keepGoing;

    while(keepGoing == 'y'){
        for(int i=0; i<menu.size(); i++){
            cout<<i<<". "<<menu[i]<<endl;
        }
        cout << "select an option: ";
        cin >> option;

        operation = menu[option];
        if(operation=="addfirst"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.addFirst(data);
            list.print("asc");
        }
        else if(operation=="addlast"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.addLast(data);
            list.print("asc");
        }
        else if(operation=="insert"){
            // insert with out of range exception handling
            int data, index;
            cout<<"data: ";
            cin>>data;
            cout<<"index: ";
            cin>>index;
            try{
                list.insert(data, index);
                list.print("asc");
            }
            catch(out_of_range e){
                cout<<e.what()<<endl;
            }
        }
        else if(operation=="deleteData"){
            int data;
            cout<<"data: ";
            cin>>data;
            list.deleteData(data);
            list.print("asc");
        }
        else if(operation=="deleteAt"){
            int index;
            cout<<"index: ";
            cin>>index;
            list.deleteAt(index);
            list.print("asc");
        }
        else if(operation=="getData"){
            // with out of range exception handling
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
        else if(operation=="updateData"){
            int data, newData;
            cout<<"data: ";
            cin>>data;
            cout<<"new data: ";
            cin>>newData;
            // with out of range exception handling
            try{
                list.updateData(data, newData);
                list.print("asc");
            }
            catch(out_of_range e){
                cout<<e.what()<<endl;
            }

        }
        else if(operation=="updateAt"){
            int index, newData;
            cout<<"index: ";
            cin>>index;
            cout<<"new data: ";
            cin>>newData;
            // with out of range exception handling
            try{
                list.updateAt(index, newData);
                list.print("asc");
            }
            catch(out_of_range e){
                cout<<e.what()<<endl;
            }
        }
        else if(operation=="findData"){
            int data;
            cout<<"data: ";
            cin>>data;
            cout<<list.findData(data)<<endl;
        }
        else if(operation=="[]getData"){
            // with out of range exception handling
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
        else if(operation=="=operator"){
            DoublyLinkedList<int> list2;
            list2 = list;
            list.print("asc");
            list2.print("asc");
        }
        else if(operation=="clear"){
            list.clear();
            list.print("asc");
        }
        else if(operation=="sort"){
            list.sort();
            list.print("asc");
        }
        else if(operation=="duplicate"){
            list.duplicate();
            list.print("asc");
        }
        else if(operation=="removeDuplicates"){
            list.removeDuplicates();
            list.print("asc");
        }
        else{
            cout<<"invalid option"<<endl;
        }

        // keepgoing command
        cout<<"keep going? (y/n): ";
        cin>>keepGoing;
    }

    
    

}
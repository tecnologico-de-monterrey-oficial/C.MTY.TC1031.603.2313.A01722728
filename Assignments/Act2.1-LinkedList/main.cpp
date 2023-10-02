#include <iostream>
#include <vector>
using namespace std;
#include "LinkedList.h"

int main()
{
    int option;
    int end = 0;
    string operation;
    LinkedList <int> list;
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
    while(1){
        for(int i=0; i<menu.size(); i++){
            cout<<i<<". "<<menu[i]<<endl;
        }
        cout << "select an option: ";
        cin >> option;

        operation = menu[option];
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
            cout<<list.getData(index)<<endl;
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
            cout<<list[index]<<endl;
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
    }

    
    

}
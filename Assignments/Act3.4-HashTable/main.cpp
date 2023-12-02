#include <iostream>
#include <vector>
using namespace std;

#include "HashMatricula.h"

int main() {

    vector<string> menu{
        "insert",
        "remove",
        "find",
        "print",
        "exit"
    };
    int option = 0;
    string operation = "";

    HashStudentId hashTable;

    while(operation!="exit"){
        cout << "Select an option:" << endl;
        for(int i = 0; i < menu.size(); i++){
            cout << i << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[option%menu.size()];
        //if else logic with exception handling when applying the functions
        if(operation == "insert"){
            string studentId;
            cout << "Enter studentId: ";
            cin >> studentId;
            //exception handling
            try{
                hashTable.insert(studentId);
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "remove"){
            string studentId;
            cout << "Enter studentId: ";
            cin >> studentId;
            //exception handling
            try{
                hashTable.remove(studentId);
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "find"){
            string studentId;
            cout << "Enter studentId: ";
            cin >> studentId;
            //exception handling
            try{
                cout << hashTable.findStudentId(studentId) << endl;
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "print"){
            hashTable.print();
        }
    }

    return 0;
}
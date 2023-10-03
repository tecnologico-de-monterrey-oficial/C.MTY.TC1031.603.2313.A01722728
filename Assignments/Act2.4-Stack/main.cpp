#include <iostream>
#include <vector>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> s;
    vector<string> menu = {"push", "pop", "top", "print", "exit"};
    int option = 0;
    string operation = "";
    int data = 0;

    while(operation!="exit"){
        cout << "Select an option:" << endl;
        for(int i = 0; i < menu.size(); i++){
            cout << i << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[option];
        if(operation == "push"){
            cout << "Enter the data: ";
            cin >> data;
            s.push(data);
        }else if(operation == "pop"){
            s.pop();
        }else if(operation == "top"){
            s.top();
        }else if(operation == "print"){
            s.print();
        }
    }

    return 0;
}
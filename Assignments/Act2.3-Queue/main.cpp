#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

int main(){
    Queue<int> queue;
    vector<string> menu = {"push", "pop", "front", "print", "exit"};
    int option = 0;
    string operation = "";
    int data = 0;
    while (operation != "exit") {
        cout << "Select an option:" << endl;
        for (int i = 0; i < menu.size(); i++) {
            cout << i << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[option];
        if (operation == "push") {
            cout << "Enter the data: ";
            cin >> data;
            queue.push(data);
        } else if (operation == "pop") {
            queue.pop();
        } else if (operation == "front") {
            queue.front();
        } else if (operation == "print") {
            queue.print();
        }
        
    }
    

    return 0;
}
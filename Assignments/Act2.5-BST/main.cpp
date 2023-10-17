#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;
    vector<string> menu{
        "insert",
        "remove",
        "find",
        "print",
        "visit",
        "height",
        "ancestors",
        "whatLevelamI",
        "exit"
    };

    int option = 0;
    string operation = "";
    int data = 0;

    while(operation != "exit"){
        cout << "Select an option:" << endl;
        for(int i = 0; i < menu.size(); i++){
            cout << i << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[option%menu.size()];
        if(operation=="insert"){
            cout << "Data to insert: ";
            cin >> data;
            bst.insert(data);
        }else if(operation=="remove"){
            cout << "Data to remove: ";
            cin >> data;
            bst.remove(data);
        }else if(operation=="find"){
            cout << "Data to find: ";
            cin >> data;
            if(bst.find(data)){
                cout << "Data found" << endl;
            }else{
                cout << "Data not found" << endl;
            }
        }else if(operation=="print"){
            bst.print();
        }else if(operation=="visit"){
            cout << "Select an option:" << endl;
            cout << "1. Preorder" << endl;
            cout << "2. Inorder" << endl;
            cout << "3. Postorder" << endl;
            cin >> option;
            if(option==1){
                bst.visit(1);
            }else if(option==2){
                bst.visit(2);
            }else if(option==3){
                bst.visit(3);
            }
        }else if(operation=="height"){
            cout << "Height: " << bst.height() << endl;
        }else if(operation=="ancestors"){
            cout << "Data to find ancestors: ";
            cin >> data;
            bst.ancestors(data);
        }else if(operation=="whatLevelamI"){
            cout << "Data to find level: ";
            cin >> data;
            cout << "Level: " << bst.whatLevelamI(data) << endl;
        }
    }



    return 0;
}
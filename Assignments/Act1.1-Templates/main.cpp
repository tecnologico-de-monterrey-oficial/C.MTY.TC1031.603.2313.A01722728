#include <iostream>
#include <vector>
#include "List.h"
using namespace std;


int main(){
    List<int> list;

    try{
        cout << "Max value: " << list.getMax() << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }

    try{
       list.removeLast(); 
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }
    list.insert(3);
    list.insert(4);
    list.insert(10);
    list.removeLast();
    list.insert(15);


    list.print();
    cout << "Size: " << list.getSize() << endl;

    try{
        cout << "Max value: " << list.getMax() << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }

    try{
        cout << "Value at index [1]: " << list.getData(1) << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }

    try{
        cout << "Value at index [-1]: " << list.getData(-1) << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }
    
     
    

    return 0;
}
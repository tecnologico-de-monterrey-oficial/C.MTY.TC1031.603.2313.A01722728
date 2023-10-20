#include <iostream>
using namespace std;

#include <vector>
#include "Heap.h"
#include "MinHeap.h"

template <class T>
void createList(vector<T> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    T num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

template <class T>
void heapSort(vector<T> &v, string type){
    if(type=="max"){
        Heap<T> heap(v);
        for(int i=0; i<v.size(); i++){
            v[i] = heap.pop();
        }
    }else if(type=="min"){
        MinHeap<T> heap(v);
        for(int i=0; i<v.size(); i++){
            v[i] = heap.pop();
        }
    }
}

int main() {
    // Semilla para generar números aleatorios
    srand(time(0));

    vector<int> v;
    Heap<int> heap;
    vector<string> menu{
        "create_random_list",
        "heap_sort",
        "push",
        "pop",
        "top",
        "getSize",
        "print",
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
        if(operation=="create_random_list"){
            cout << "Size of the list: ";
            cin >> data;
            createList(v, data);
            heap = v;
        }else if(operation=="heap_sort"){
            string type;
            cout << "Type of heap (max/min): ";
            cin >> type;
            v = heap.getHeap();
            heapSort(v, type);
            for(auto el : v){
                cout << el << " ";
            }
            cout << endl;
        }else if(operation=="push"){
            cout << "Data: ";
            cin >> data;
            heap.push(data);
        }else if(operation=="pop"){
            try{
                cout << heap.pop() << endl;
            }
            catch(exception &e){
                cout << e.what() << endl;
            }
        }else if(operation=="top"){
            try{
                cout << heap.top() << endl;
            }
            catch(exception &e){
                cout << e.what() << endl;
            }
        }else if(operation=="getSize"){
            cout << "Size: " << heap.getSize() << endl;
        }else if(operation=="print"){
            heap.print();
        }
    }



    return 0;
}
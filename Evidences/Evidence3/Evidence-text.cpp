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
    createList(v, 5);
    heapSort(v, "max");
    for(auto el : v){
        cout << el << " ";
    }
    cout << endl;
    heapSort(v, "min");
    for(auto el : v){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
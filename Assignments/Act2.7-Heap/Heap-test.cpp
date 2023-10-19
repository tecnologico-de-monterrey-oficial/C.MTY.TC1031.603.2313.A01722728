#include <iostream>
using namespace std;

#include <vector>
#include "Heap.h"
#include "MinHeap.h"

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
    vector<int> v = {1, 5, 3, 2, 4};
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
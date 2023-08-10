#ifndef Lista_h
#define Lista_h

//Borrar 
#include <iostream>
#include <vector>
using namespace std;
//Borrar

template <class T>
class List{
    private:
        vector <T> data;
        int size;
    public:
        List();
        void insert(T elem);
        void removeLast();
        int getSize();
        T getData(int pos);
        T getMax();
        void print();
};

template <class T>
List<T>::List(){
    size = 0;
}

template <class T>
void List<T>::insert(T elem){
    cout << "value inserted successfully" << endl;
    data.push_back(elem);
    size ++;
}

template <class T>
void List<T>::removeLast(){
    if(size == 0){
        cout << "No hay elementos" << endl;
    }else{
        cout << "Last element removed: " << data[size-1] << endl;
        data.pop_back();
        size --;
    }
}

template <class T>
int List<T>::getSize(){
    return size;
}

template <class T>
T List<T>::getData(int pos){
    if(pos >=0 && pos<size){
        return data[pos];
    }else{
        return 0;
    }
}

template <class T>
T List<T>::getMax(){
    T max = 0;
    for(T x:data){
        if(x>max){
            max = x;
        }
    }
    return max;
}


template <class T>
void List<T>::print(){
    cout << "List:" << endl;
    for(int i=0; i<size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}









#endif

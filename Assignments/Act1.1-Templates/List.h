#ifndef Lista_h
#define Lista_h

#include <iostream>
#include <vector>
using namespace std;

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
    if(size > 0){
        cout << "Last element removed: " << data[size-1] << endl;
        data.pop_back();
        size --;
    }else{
        throw out_of_range("Empty list");
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
        throw out_of_range("Index out of range");
    }
}

template <class T>
T List<T>::getMax(){
    if(size>0){
        T max = data[0];
        for(int i=1; i< size; i++){
            if(data[i]>max){
                max = data[i];
            }
        }
        return max;
    }else{
        throw out_of_range("Empty list");
    }
    
}


template <class T>
void List<T>::print(){
    cout << "List:" << endl;
    for(int i=0; i<size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}


#endif
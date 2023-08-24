#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "timer.cpp"

using namespace std;

int linearSearch(vector<int> arr, int data){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]==data){
            return i;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int> arr, int data, int left, int right){
    int mid = left + (right-left)/2;
    if(left > right){
        return -1;
    }
    if(arr[mid]==data){
        return mid;
    }
    else if(data < arr[mid]){
        right = mid-1;
        return binarySearchRecursive(arr, data, left, right);
    }
    else{
        left = mid+1;
        return binarySearchRecursive(arr, data, left, right);
    }
}

int binarySearchWhile(vector<int> arr, int data){
    int left = 0;
    int right = arr.size() - 1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid]==data){
        return mid;
        }
        else if(data < arr[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
    
}

int main(){
    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 10000 de enteros    
    vector<int> list;
    
    createListInt(list, 10000);
    sort(list.begin(),list.end());

    int command = 1;
    while (command!=0){
        cout << "Input int (between 1-1,000,000) to find position in list or 0 to terminate: " << endl;
        cin >> command;
        startTime(begin);
        cout << "Index using binary search (Recursive): " << binarySearchRecursive(list, command, 0, list.size()-1) << endl;
        getTime(begin, end);
        startTime(begin);
        cout << "Index using binary search (While): " << binarySearchWhile(list, command) << endl;
        getTime(begin, end);
        startTime(begin);
        cout << "Index using linear search: " << linearSearch(list, command) << endl;
        getTime(begin, end);
    }
    

    return 0;
}

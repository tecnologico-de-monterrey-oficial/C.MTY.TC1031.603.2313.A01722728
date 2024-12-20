#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <class T>
int binarySearchRecursive(vector<T> arr, T data, int left, int right){
    int mid = left + (right-left)/2;
    if(right < left){
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

// Función para intercambiar dos valores en una lista
template <class T>
void swap(vector<T> &list, int a, int b)
{
    // validamos que sean diferentes
    if (a!=b)
    {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}



template <class T>
int getPivot(vector<T> &list, int left, int right){
    int aux = left-1;
    int pivot = right;
    for(int i=left; i<right; i++){
        if(list[i]<list[pivot]){
            aux++;
            swap(list, i, aux);
        }
    }
    aux++;
    swap(list, pivot, aux);
    return aux;
}

template <class T>
void quickSort(vector<T> &list, int left, int right){
    if(left<right){
        int pivot = getPivot(list, left, right);
        quickSort(list, left, pivot-1);
        quickSort(list, pivot+1, right);
    }   
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "algorithms.cpp"
using namespace std;

template <class T>
void findNum(vector<T> &list){
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    int find_number = 1;
    while (find_number!=0){
        cout << "Input int (between 1-1,000,000) to find position in list or 0 to terminate: " << endl;
        cin >> find_number;
        startTime(begin);
        cout << "Index using binary search: " << binarySearch(list, find_number) << endl;
        getTime(begin, end);
        startTime(begin);
        cout << "Index using linear search: " << linearSearch(list, find_number) << endl;
        getTime(begin, end);
    }
}

int main(){
    // Semilla para generar números aleatorios
    srand(time(0));
    
    vector<int> list;
    createList(list, 100); 
    int comparisons = 0;
    int swaps = 0;
    shellSort(list, comparisons, swaps);
    print(list);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;

    findNum(list);

    return 0;
}


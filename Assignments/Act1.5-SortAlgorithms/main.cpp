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

void print_comparisons_swaps(int comp, int swap){
    cout << "Comparisons: " << comp << " Swaps: " << swap << endl;
}

int main(){
    // Semilla para generar números aleatorios
    srand(time(0));
    
    vector<int> list;
    int n = 0;
    cout << "Input amount of values: ";
    cin >> n;
    createList(list, n);
     
    vector<string> algorithm_names {"swap sort", "bubble sort",  "selection sort", "insertion sort", "merge sort", "quick sort", "shell sort"};
    for(int i=0; i<algorithm_names.size(); i++){
        cout << i << " - " << algorithm_names[i] << endl;
    }

    int algorithm_index;
    cout << "Input index of the sorting algorithm: " << endl;
    cin >> algorithm_index;

    int comparisons = 0;
    int swaps = 0;

    if(algorithm_index==0){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        swapSort(list, comparisons, swaps);
        print(list);
        print_comparisons_swaps(comparisons, swaps);

    }else if(algorithm_index==1){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        bubbleSort(list, comparisons, swaps);
        print(list);
        print_comparisons_swaps(comparisons, swaps);

    }else if(algorithm_index==2){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        selectionSort(list, comparisons, swaps);
        print(list);
        print_comparisons_swaps(comparisons, swaps);

    }else if(algorithm_index==3){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        insertionSort(list, comparisons, swaps);
        print(list);
        print_comparisons_swaps(comparisons, swaps);

    }else if(algorithm_index==4){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        mergeSort(list, 0, list.size()-1);
        print(list);
        

    }else if(algorithm_index==5){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        quickSort(list, 0, list.size()-1);
        print(list);
        
    }else if(algorithm_index==6){
        cout << algorithm_names[algorithm_index] << ": " << endl;
        shellSort(list, comparisons, swaps);
        print(list);
        print_comparisons_swaps(comparisons, swaps);

    }
    findNum(list);

    return 0;
}


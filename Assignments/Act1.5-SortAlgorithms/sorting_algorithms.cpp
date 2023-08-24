#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir los valores de la lista
template <class T>
void print(vector<T> list)
{
    for (auto l : list)
    {
        cout << l << " ";
    }
    cout << endl;
}
// Función para intercambiar dos valores en una lista
template <class T>
void swap(vector<T> &list, int a, int b)
{
    // validamos que sean diferentes
    if (list[a] != list[b])
    {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template <class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps){
    for(int i=0; i<list.size()-1; i++){
        for(int j=i+1; j<list.size(); j++){
            comparisons++;
            if(list[j]<list[i]){
                swap(list, i, j);
                swaps++;
            }
        }
    }
}

template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps){
    int iter = 0;
    bool control = true;

    while (control && iter <list.size()-1){
        control = false;
        for(int j=1; j<list.size()-iter; j++){
            comparisons++;
            if(list[j]<list[j-1]){
                swap(list, j-1, j);
                swaps++;
                control = true;
            }
        }
        iter++;
    }
    
}

template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps){
    
}

template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps){
    
}

template <class T>
void mergeSort(vector<T> &list, int &comparisons, int &swaps){
    
}

template <class T>
void quickSort(vector<T> &list, int &comparisons, int &swaps){
    
}


int main(){
    vector<int> list{5,7,2,1,4,5,7,8,9};
    print(list);

    vector<int> listAux = list;    
    int comparisons = 0;
    int swaps = 0;
    swapSort(listAux, comparisons, swaps);
    print(listAux);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;

    listAux = list;    
    comparisons = 0;
    swaps = 0;
    bubbleSort(listAux, comparisons, swaps);
    print(listAux);
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;

    return 0;
}
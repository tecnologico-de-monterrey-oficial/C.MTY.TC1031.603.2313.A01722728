#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <sstream>
#include "Log.h"
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

    // Archivo de entrada
    ifstream fileIn("log603-3.txt");
    // Archivo de salida
    ofstream MaxHeapSort("output603-1.txt");
    ofstream MinHeapSort("output603-2.txt");
    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    vector<Log> logs;
    
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn,line)) { 
        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(line);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip >> message;
        // Ciclo para recorrer cada palabra del campo message
        while (ss >> word) {
            message = message + " " + word;
        }
        Log log(year, month, day, time, ip, message);
        logs.push_back(log);
        // Incrementamos el contador de registros
        cont++;
    }

    heapSort(logs, "max");

    // Escribiendo los registros ordenados en el archivo maxHeapSort.txt
    for (int i = 0; i < logs.size(); i++) {
        MaxHeapSort << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
    }

    heapSort(logs, "min");

    // Escribiendo los registros ordenados en el archivo minHeapSort.txt
    for (int i = 0; i < logs.size(); i++) {
        MinHeapSort << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
    }

    fileIn.close();
    MaxHeapSort.close();
    MinHeapSort.close();


    return 0;
}
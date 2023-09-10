#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "algorithms.cpp"
using namespace std;

#include "Log.h"

int main() {

    // Archivo de entrada
    ifstream fileIn("log603.txt");
    // Archivo de salida
    ofstream fileOut("output603.out");
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

    cout << "La cantidad de registros es: " << logs.size() << endl;
    // Quicksort para ordenar el vector logs
    quickSort(logs, 0, logs.size()-1);
    // Ciclo para escribir los registros ordenados en el archivo de salida
    for (int i = 0; i < logs.size(); i++) {
        fileOut << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
    }
    // Cerramos el archivo de entrada   
    fileIn.close();

    return 0;
}
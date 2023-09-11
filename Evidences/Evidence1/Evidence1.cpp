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
    ofstream fileOut("output603.txt");
    ofstream rangeOut("range603.txt");
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
    // variables para fecha final
    string year2;
    string month2;
    string day2;
    string time2;
    
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

    // Quicksort para ordenar el vector logs
    quickSort(logs, 0, logs.size()-1);
    // Escribiendo los registros ordenados en el archivo de salida
    for (int i = 0; i < logs.size(); i++) {
        fileOut << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
    }


    cout << "La cantidad de registros es: " << logs.size() << endl;

    // Asking for a range of dates
    cout << "Using binary search to find dates between range: " << endl;
    cout << "Initial date: " << endl;
    cout << "Year: ";
    cin >> year;
    cout << "Month capitalized and in 3 letter format, (Jan, Feb, Mar): ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Time in 24h format hh:mm:ss: ";
    cin >> time;    
    cout << "Final date: " << endl;
    cout << "Year: ";
    cin >> year2;
    cout << "Month capitalized and in 3 letter format, (Jan, Feb, Mar): ";
    cin >> month2;
    cout << "Day: ";
    cin >> day2;
    cout << "Time in 24h format hh:mm:ss: ";
    cin >> time2;

    Log date1(year, month, day, time, "", "");
    Log date2(year2, month2, day2, time2, "", "");


    for (int i = 0; i < logs.size(); i++) {
        if (date1 < logs[i] && logs[i] < date2) {
            rangeOut << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
        } 
    }
    // Cerramos los archivos de entrada y salida
    fileOut.close(); 
    rangeOut.close();
    fileIn.close();

    return 0;
}
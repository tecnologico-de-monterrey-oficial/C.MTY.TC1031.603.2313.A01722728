#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "DoublyLinkedList.h"


int main() {

    // Archivo de entrada
    ifstream fileIn("log603-2.txt");
    // Archivo de salida
    ofstream datesFile("output602-1.out");
    ofstream ipsFile("output602-2.out");
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
    DoublyLinkedList logs;
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
    
    // Ordenamos los registros
    logs.sort();

    // Escribiendo los registros ordenados en el archivo de salida
    for (size_t i = 0; i < logs.getSize(); i++) {
        datesFile << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
    }


    cout << "La cantidad de registros es: " << logs.getSize() << endl;

    /*

    // Asking for a range of dates
    cout << "Using binary search to find dates between range: " << endl;
    cout << "Initial date: " << endl;
    cout << "Year: ";
    cin >> year;
    cout << "Month capitalized and in 3 letter format, (Jan, Feb, Mar): ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Hour in 24h format: ";
    cin >> time;    

    cout << "Final date: " << endl;
    cout << "Year: ";
    cin >> year2;
    cout << "Month capitalized and in 3 letter format, (Jan, Feb, Mar): ";
    cin >> month2;
    cout << "Day: ";
    cin >> day2;
    cout << "Hour in 24h format: ";
    cin >> time2;

    Log date1(year, month, day, time + ":00:00", "", "");
    Log date2(year2, month2, day2, time2 + ":00:00", "", "");

    // searching for valid dates and writing them in file ipsFile.txt
    for (size_t i = 0; i < logs.getSize(); i++) {
        if (date1 < logs[i] && logs[i] < date2) {
            logs[i].print();
            ipsFile << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
        } 
    }*/

    // Cerramos los archivos de entrada y salida
    datesFile.close(); 
    ipsFile.close();
    fileIn.close();

    return 0;
}
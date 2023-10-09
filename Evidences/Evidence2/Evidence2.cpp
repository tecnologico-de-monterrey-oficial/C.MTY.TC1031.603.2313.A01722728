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
    //Cambiando llaves de fecha a llaves de ips
    for (int i = 0; i < logs.getSize(); i++) {
        datesFile << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
        logs[i].keyToIpKey();
    }

    // Ordenamos los registros por ip
    logs.sort();

    for (int i = 0; i < logs.getSize(); i++) {
        ipsFile << logs[i].ip << " " << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " "  << logs[i].message << endl;
    }


    cout << "La cantidad de registros es: " << logs.getSize() << endl;
    
     

    // Cerramos los archivos de entrada y salida
    datesFile.close(); 
    ipsFile.close();
    fileIn.close();

    return 0;
}
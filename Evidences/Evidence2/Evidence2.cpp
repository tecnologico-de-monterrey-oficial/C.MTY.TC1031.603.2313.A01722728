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
    //salida de ips entre rangos en orden ascendente y descendente
    ofstream ipsAsc("iprange602-a.out");
    ofstream ipsDesc("iprange602-d.out");

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

    //variables para el rango de ips
    DoublyLinkedList ipsInRange;
    string ip2;

    //Variable de contador de ips por mes
    int jan = 0;
    int feb = 0;
    int mar = 0;
    int apr = 0;
    int may = 0;
    int jun = 0;
    int jul = 0;
    int aug = 0;
    int sep = 0;
    int oct = 0;
    int nov = 0;
    int dec = 0;
        
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
    // Cambiando llaves de fecha a llaves de ips
    for (int i = 0; i < logs.getSize(); i++) {
        datesFile << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;
        logs[i].keyToIpKey();
    }

    // Ordenamos los registros por ip
    logs.sort();

    // Escribiendo los registros ordenados en el archivo de ips
    for (int i = 0; i < logs.getSize(); i++) {
        ipsFile << logs[i].ip << " " << logs[i].year << " " << logs[i].month << " " << logs[i].day << " " << logs[i].time << " "  << logs[i].message << endl;
    }
    // asking for ips to search in between
    cout << "Search between Ips: " << endl;
    cout << "Min Ip: 10.14.0.13 " << endl;
    cout << "Max Ip: 10.14.99.97" << endl; 

    cout << "ip1: ";   
    cin >> ip;
    cout << "ip2: ";
    cin >> ip2;

    // searching for ips in between
    for (int i = 0; i < logs.getSize(); i++) {
        if(logs[i].ip >= ip && logs[i].ip <= ip2){
            ipsInRange.push_back(logs[i]);
        }
    }

    // writing ips in between in a file
    for (int i = 0; i < ipsInRange.getSize(); i++) {
        ipsAsc << ipsInRange[i].ip << " " << ipsInRange[i].year << " " << ipsInRange[i].month << " " << ipsInRange[i].day << " " << ipsInRange[i].time << " "  << ipsInRange[i].message << endl;
    }

    // writing ips in between in a file
    for (int i = ipsInRange.getSize()-1; i >= 0; i--) {
        ipsDesc << ipsInRange[i].ip << " " << ipsInRange[i].year << " " << ipsInRange[i].month << " " << ipsInRange[i].day << " " << ipsInRange[i].time << " "  << ipsInRange[i].message << endl;
    }

    //from IpsInRange calculating amount of ips per month
    
    
    for (int i = 0; i < ipsInRange.getSize(); i++) {
        if(ipsInRange[i].month == "Jan"){
            jan++;
        }else if(ipsInRange[i].month == "Feb"){
            feb++;
        }else if(ipsInRange[i].month == "Mar"){
            mar++;
        }else if(ipsInRange[i].month == "Apr"){
            apr++;
        }else if(ipsInRange[i].month == "May"){
            may++;
        }else if(ipsInRange[i].month == "Jun"){
            jun++;
        }else if(ipsInRange[i].month == "Jul"){
            jul++;
        }else if(ipsInRange[i].month == "Aug"){
            aug++;
        }else if(ipsInRange[i].month == "Sep"){
            sep++;
        }else if(ipsInRange[i].month == "Oct"){
            oct++;
        }else if(ipsInRange[i].month == "Nov"){
            nov++;
        }else if(ipsInRange[i].month == "Dec"){
            dec++;
        }
    }

    //displying amount of ips per month to the command line
    cout << "Amount of ips per month: " << endl;
    cout << "Jan: " << jan << endl;
    cout << "Feb: " << feb << endl;
    cout << "Mar: " << mar << endl;
    cout << "Apr: " << apr << endl;
    cout << "May: " << may << endl;
    cout << "Jun: " << jun << endl;
    cout << "Jul: " << jul << endl;
    cout << "Aug: " << aug << endl;
    cout << "Sep: " << sep << endl;
    cout << "Oct: " << oct << endl;
    cout << "Nov: " << nov << endl;
    cout << "Dec: " << dec << endl;

    // Cerramos los archivos de entrada y salida
    ipsAsc.close();
    ipsDesc.close();
    datesFile.close(); 
    ipsFile.close();
    fileIn.close();

    return 0;
}
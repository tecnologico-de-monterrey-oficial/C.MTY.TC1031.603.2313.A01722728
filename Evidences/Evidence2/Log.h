#pragma once
#include <vector>
#include <string>
struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key;
    bool operator<(Log log);
    string keyGenerator();
    void print();

    Log();
    Log(string year, string month, string day, string time, string ip, string message);
};

Log::Log() {
    year = "";
    month = "";
    day = "";
    time = "";
    ip = "";
    message = "";
    key = "";
}

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generar la clave 
    key = keyGenerator();
}

string Log::keyGenerator() {
    string key = "";
    // string vector of month names
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int monthNumber = 0;
    for(string monthName : months){
        if(monthName == month){
            break;
        }
        monthNumber++;
    }

    // string vector of first 12 capital letters
    vector<string> letters = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K","L"};

    // the key uses letters instead of numbers for the month
    // in order to use the sort algorithm properly
    key = key + year + letters[monthNumber] + day + time;
    return key;
}

void Log::print(){
    cout << year << " " << month << " " << day << " " << time << " " << ip << " " << message << endl;
}

bool Log::operator<(Log log) {
    return key < log.key;
}
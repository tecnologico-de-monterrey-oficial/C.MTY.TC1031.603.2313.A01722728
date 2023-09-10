#pragma once

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

    Log(string year, string month, string day, string time, string ip, string message);
};

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
    key = key + year + month + day + time;
    return key;
}

void Log::print(){
    cout << year << " " << month << " " << day << " " << time << " " << ip << " " << message << endl;
}

bool Log::operator<(Log log) {
    return key < log.key;
}
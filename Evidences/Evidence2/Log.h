#pragma once

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key1;
    string key2;
    bool operator<(Log log);
    string key1Generator();
    string key2Generator();
    string getIp();
    Log(string year, string month, string day, string time, string ip, string message);
    friend ostream& operator<<(ostream& os, Log log); 
};

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generar la clave 
    key1 = key1Generator();
    key2 = key2Generator();
}


string Log::getIp() {
    return "10.14.075.001"
}
string Log::key1Generator() {
    string mm;
    if (month == "Jan") {
        mm = "01";
    }
    return year + mm + day + time;
}
string Log::key2Generator() {
    string mm;
    if (month == "Jan") {
        mm = "01";
    }
    return getIp() + year + mm + day + time;
}

bool Log::operator<(Log log) {
    return key < log.key;
}

ostream& operator<<(ostream& os, Log log) {
    os << "Log: " << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message << endl;
    return os;
}
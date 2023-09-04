#include <iostream>
using namespace std;
#include "Log.h"

int main() {

    

    Log log1("2022", "Sep", "17", "06:13:58", "10.45.134.186", "Human error");
    Log log2("2023", "Aug", "07", "10:32:12", "10.136.150.196", "Human error");

    log1.key = "20220927061358";
    log2.key = "20230807103212";
    cout << log1.year << " " << log2.year << endl;

    if (log1 < log2) {
        cout << "s1 es menor a s2" << endl;
    } else {
        cout << "s1 es mayor o igual a s2" << endl;
    }


    return 0;
}
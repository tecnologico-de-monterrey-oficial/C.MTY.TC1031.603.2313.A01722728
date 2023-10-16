#include <iostream>
using namespace std;
#include "Log.h"

int main() {
    string ip1 = "10.148.99.111";
    string ip2 = "10.114.230.135";

    if (ip1>ip2) {
        cout << "1 mayor" << endl;
    } else {
        cout << "2 mayor" << endl;
    }


    return 0;
}
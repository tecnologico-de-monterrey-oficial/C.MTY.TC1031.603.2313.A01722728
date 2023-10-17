#include <iostream>
using namespace std;

#include <vector>
#include "Heap.h"

int main() {

    vector<int> v = {8,5,17,19,21,28};
    Heap<int> heap(v);
    heap.print();
    vector<int> v1 = {9,5,18,44,53,12,1};
    Heap<int> heap1(v1);
    heap1.print();

    return 0;
}
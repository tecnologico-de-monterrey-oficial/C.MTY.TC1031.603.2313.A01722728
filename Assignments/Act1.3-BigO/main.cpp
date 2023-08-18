#include <iostream>
#include <vector>
using namespace std;


int sumOddIterative(vector<int> arr){
    int sum;
    for(int x: arr){
        if(x%2==1){
            sum += x;
        }
    }
    return sum;
}

int sumOddRecursive(vector<int> arr, int n){
    if(n>=0){
        if(arr[n]%2==1){
            return arr[n] + sumOddRecursive(arr, n-1);
        }else{
            return sumOddRecursive(arr, n-1);
        }
    }
    else{
        return 0;
    }
}


int main(){
    vector<int> a {1,2,3,4,5,6,7,8,9};
    cout << "Lista: ";
    for(int x: a){
        cout << x << " ";
    }
    cout << endl;
    cout << "Metodo Iterativo (complejidad O(n)): " << sumOddIterative(a) << endl;
    cout << "Metodo Recursivo (complejidad O(n)): " << sumOddRecursive(a, a.size()-1) << endl;

    return 0;
}

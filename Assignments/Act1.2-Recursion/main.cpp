#include <iostream>
using namespace std;

int sumIterative(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum+=i;
    }
    return sum; 
}

int sumRecursive(int n){
    if(n>0){
        return n + sumRecursive(n-1); 
    }
    else{
        return 0;
    }
}

int sumFormula(int n){
    return (n*(n+1))/2;
}

int fibonacciIterative(int n){
    int sum = 0;
    int a = 0;
    int b = 1;
    for(int i=1; i<n; i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int fibonacciRecursive(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2); 
    }
}

double bacteriasIterative(int n){
    double bact = 1;
    while(n--){
        bact*=1.44;
    }
    return bact;
}

double bacteriasRecursive(int n){
    if(n>0){
        return 1.44 * bacteriasRecursive(n-1);
    }
    else{
        return 1;
    }
}

double investmentIterative(int n, double cant){
    while(n--){
        cant *= 1.1875;
    }
    return cant;
}

double investmentRecursive(int n, double cant){
    if(n==0){
        return cant;
    }
    return investmentRecursive(n-1, cant*1.1875);
}


long powIterative(int n, int y){
    long result = 1;
    for(int i=0; i<y; i++){
        result *= n;
    }

    return result;
}

long powRecursive(int n, int y){
    if(y==0){
        return 1;
    }
    return n * powRecursive(n,y-1);
}


int main(){
    cout << "sumIterative(4): " << sumIterative(4) << endl;
    cout << "sumRecursive(4): " << sumRecursive(4) << endl;
    cout << "sumFormula(4): " << sumFormula(4) << endl;

    cout << "fibonacciIterative(10): " << fibonacciIterative(10) << endl;
    cout << "fibonacciRecursive(10): " << fibonacciRecursive(10) << endl;
    
    cout << "bacteriasIterative(10): " << bacteriasIterative(10) << endl;
    cout << "bacteriasRecursive(10): " << bacteriasRecursive(10) << endl;

    cout << "InvestmentIterative(3,100): " << investmentIterative(3,100) << endl;
    cout << "InvestmentRecursive(3,100): " << investmentRecursive(3,100) << endl;

    cout << "powIterative(4, 3):" << powIterative(4, 3) << endl;
    cout << "powRecursive(4, 3):" << powRecursive(4, 3) << endl;

    return 0;
}
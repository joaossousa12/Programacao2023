#include <iostream>

using namespace std;

unsigned long factorial(unsigned long n){
    unsigned long res = 1;
    for(unsigned long i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

unsigned long bell(unsigned long n){
    if(n == 0 || n == 1){
        return 1;
    }
    unsigned long res = 1;
    for(unsigned long k = 1; k <= n - 1; k++){
        res += (factorial(n - 1) / (factorial(k)*factorial(n - 1 - k))) * bell(k); 
    }
    return res;
}

int main(){
    cout << bell(0) << '\n';
    //1
    cout << bell(1) << '\n';
    //1
    cout << bell(2) << '\n';
    //2
    cout << bell(3) << '\n';
    //5
    cout << bell(4) << '\n';
    //15
    cout << bell(6) << '\n';
    //203
    return 0;
}
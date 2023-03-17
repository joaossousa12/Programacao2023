#include <iostream>

using namespace std;

unsigned long factorial(unsigned long n){
    unsigned long res = 1;
    for(unsigned long i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

unsigned long bc(unsigned long n, unsigned long k){
    return factorial(n) / (factorial(k)*factorial(n - k));
}

int main(){
    cout << bc(5, 0) << '\n';
    //1
    cout << bc(5, 1) << '\n';
    //5
    cout << bc(5, 5) << '\n'; 
    //1
    cout << bc(5, 2) << '\n';
    //10
    cout << bc(12, 7) << '\n'; 
    //792
    cout << bc(20, 10) << '\n'; 
    //184756
    return 0;
}
#include <iostream>

using namespace std;

unsigned long bc(unsigned long n, unsigned long k){
    unsigned long num = 1;
    unsigned long den = 1;
    for(unsigned long i = n; i >= n - k + 1; i--) num *= i;
    for(unsigned long j = k; j >= 1; j--) den *= j;
    return num / den;
}

unsigned long bell(unsigned long n){
    if(n <= 1) return 1;
    unsigned long res = 1;
    for(unsigned long k = 1; k < n; k++){
        res += bc(n - 1, k) * bell(k);
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
#include <iostream>

using namespace std;

unsigned long bc(unsigned long n, unsigned long k){
    unsigned long num = 1;
    unsigned long den = 1;
    for(unsigned long i = n; i >= n - k + 1; i--) num *= i;
    for(unsigned long j = k; j >= 1; j--) den *= j;
    return num / den;
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
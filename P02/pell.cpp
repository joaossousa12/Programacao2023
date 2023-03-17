#include <iostream>

using namespace std;

unsigned long pell(unsigned long n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else{
        unsigned long p1 = 0;
        unsigned long p2 = 1;
        for(unsigned long i = 2; i <= n; i++){
            unsigned long p3 = 2 * p2 + p1;
            p1 = p2;
            p2 = p3;
        }
        return p2;
    }
}

int main(){
    cout << pell(0) << '\n';
    cout << pell(1) << '\n';
    cout << pell(2) << '\n';
    cout << pell(3) << '\n';
    cout << pell(5) << '\n';
    cout << pell(50) << '\n';
    return 0;
}
#include <iostream>

using namespace std;

unsigned long next_mersenne(unsigned long n){
    if(n == 0) return 0;
    unsigned long next = 1;
    while(next < n) next = (next << 1) + 1;
    return next;
}

int main(){
    cout << next_mersenne(0) << '\n';
    //0
    cout << next_mersenne(1) << '\n';
    //1
    cout << next_mersenne(2) << '\n';
    //3
    cout << next_mersenne(4) << '\n';
    //7
    cout << next_mersenne(128) << '\n';
    //255
    cout << next_mersenne(4294967296UL) << '\n';
    //8589934591
    return 0;
}
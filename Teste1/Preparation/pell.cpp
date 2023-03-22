#include <iostream>

using namespace std;

unsigned long pell(unsigned long n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    unsigned long P_n1 = 1;
    unsigned long P_n2 = 0;
    unsigned long tmp;
    for(unsigned long i = 2; i <= n; i++){
        tmp = P_n1;
        P_n1 = 2 * P_n1 + P_n2;
        P_n2 = tmp;
    }
    return P_n1;
}

int main(){
    cout << pell(0) << '\n';
    //0
    cout << pell(1) << '\n';
    //1
    cout << pell(2) << '\n';
    //2
    cout << pell(3) << '\n';
    //5
    cout << pell(5) << '\n';
    //29
    cout << pell(50) << '\n';
    //4866752642924153522
    return 0;
}
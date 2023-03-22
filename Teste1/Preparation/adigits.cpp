#include <iostream>

using namespace std;

int adigits(int a, int b, int c){
    int res;
    if(a >= b && b >= c) res = a * 100 + b * 10 + c;
    else if(a >= c && c >= b) res = a * 100 + c * 10 + b;
    else if(b >= a && a >= c) res = b * 100 + a * 10 + c;
    else if(b >= c && c >= a) res = b * 100 + c * 10 + a;
    else if(c >= a && a >= b) res = c * 100 + a * 10 + b;
    else res = c * 100 + b * 10 + a;
    return res;
}

int main(){
    cout << adigits(4, 2, 5) << '\n';
    //542
    cout << adigits(9, 1, 9) << '\n';
    //991
    cout << adigits(1, 2, 3) << '\n';
    //321
    cout << adigits(1, 0, 0) << '\n';
    //100
    return 0;
}
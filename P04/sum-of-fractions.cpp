#include "fraction.h"
#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

fraction reduce(fraction res){
    fraction tmp = res;
    res.num /= gcd(tmp.num, tmp.den);
    res.den /= gcd(tmp.num, tmp.den);
    if(res.den < 0){
        res.num = -res.num;
        res.den = -res.den;
    }
    return res;
}

fraction add(fraction a, fraction b){
    fraction res;
    if(a.den == b.den){
        res.num = a.num + b.num;
        res.den = a.den;
    }else {
        res.num = (a.num * b.den) + (b.num * a.den);
        res.den = a.den * b.den;
    }
    return reduce(res);
}

fraction sum(const fraction fa[], int n){
    fraction res = reduce(fa[0]);
    for(int i = 1; i < n; i++){
        res = add(res, fa[i]);
    }
    return res;
}

int main(){
    { const int n = 1;
    const fraction fa[n] { {1, 2} };
    cout << sum(fa, n) << '\n'; }
    //1/2
    { const int n = 2;
    const fraction fa[n] { {1, 2}, {-1, 3} };
    cout << sum(fa, n) << '\n'; }
    //1/6
    { const int n = 3;
    const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
    cout << sum(fa, n) << '\n'; }
    //-7/12
    { const int n = 4;
    const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
    cout << sum(fa, n) << '\n'; }
    //0
    { const int n = 5;
    const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa, n) << '\n'; }
    //-13/60
    { const int n = 6;
    const fraction fa[n] { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa, n) << '\n'; }
    //2
    return 0;
}
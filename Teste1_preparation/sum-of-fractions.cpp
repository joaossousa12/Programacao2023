#include "fraction.h"

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

fraction add(fraction a, fraction b){
    if(a.den == b.den) return {a.num  + b.num, b.den};
    else return {a.num * b.den + b.num * a.den, a.den * b.den};
}

fraction reduced(fraction a){
    fraction tmp = a;
    a.num /= gcd(tmp.num, tmp.den);
    a.den /= gcd(tmp.num, tmp.den);
    if(a.den < 0){
        a.num = -a.num;
        a.den = -a.den;
    }
    return a;
}

fraction sum(const fraction fa[], int n){
    fraction result = fa[0];
    for(int i = 1; i < n; i++) result = add(result, fa[i]);
    return reduced(result);
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
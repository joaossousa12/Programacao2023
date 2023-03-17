#include <iostream>

using namespace std;

struct fraction{
    int num;
    int den;
};

int gcd(int a, int b){
    while(b != 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

fraction mul(fraction a, fraction b){
    return {a.num * b.num, a.den * b.den};
}

fraction add(fraction a, fraction b){
    if(a.den == b.den) return {a.num + b.num, a.den};
    else return {a.num * b.den + b.num * a.den, a.den * b.den};
}

fraction reduced(fraction a){
    return {a.num / gcd(a.num, a.den), a.den / gcd(a.num, a.den)};
}

fraction eval(const fraction a[], int n, fraction x){
    fraction a_0 = a[0];
    for(int i = 1; i < n; i++){
        fraction tmp_x = x;
        for(int j = 1; j < i; j++){
            tmp_x = mul(tmp_x, x);
        }
        a_0 = add(a_0, mul(a[i], tmp_x));
    }
    return reduced(a_0);
}

int main(){
    const int n = 2;
    fraction p[n] = { {-3, 4}, {-1,2} };
    fraction x = {0, 1};
    fraction r = eval(p, n, x);
    cout << r.num << '/' << r.den << '\n';
    return 0;
}
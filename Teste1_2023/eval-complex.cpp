#include "complex.h"

complex add(complex a, complex b){
    return {a.real + b.real, a.img + b.img};
}

complex mul(complex a, complex b){
    return {a.real * b.real - a.img * b.img, a.real * b.img + b.real * a.img};
}

complex eval(const complex a[], int n, complex x){
    complex res = a[0];
    for(int i = 1; i < n; i++){
        complex tmp = x;
        complex tmp1 = x;
        for(int j = 1; j < i; j++) tmp = mul(tmp, tmp1);
        res = add(res, mul(a[i], tmp));
    }
    return res;
}

int main(){
    { const int n = 1;
    complex p[n] = { { 1, 2 } };
    complex x = { 3, 4 };
    complex r = eval(p, n, x);
    cout << r.real << ' ' << r.img << '\n'; }

        

    //1 2

    { const int n = 2;
    complex p[n] = { { 3, 4 }, { 1, 2 } };
    complex x = { 1, 2 };
    complex r = eval(p, n, x);
    cout << r.real << ' ' << r.img << '\n'; }

        

    //0 8

    {  const int n = 3;
    complex p[n] = { { 3, 0 }, { 1, 1 }, { 1, 0 } };
    complex x = { 2, 0 };
    complex r = eval(p, n, x);
    cout << r.real << ' ' << r.img << '\n'; }

        

    //9 2

    { const int n = 3;
    complex p[n] = { { 3, 0 }, { 1, 1 }, { 1, 0 } };
    complex x = { 2, 1 };
    complex r = eval(p, n, x);
    cout << r.real << ' ' << r.img << '\n'; }

        

    //7 7

    { const int n = 4;
    complex p[n] = { { 18, -12 }, { 3, -2 }, { 2, -1 }, { 1, 1 } };
    complex x = { -2, -1 };
    complex r = eval(p, n, x);
    cout << r.real << ' ' << r.img << '\n'; }

        

    //29 -19
    return 0;
}
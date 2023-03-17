#include "complex.h"

complex add(complex a, complex b){
    return {a.real + b.real, a.img + b.img};
}

complex mul(complex a, complex b){
    return {a.real * b.real - a.img * b.img, a.real * b.img + b.real * a.img};
}

void mandel(complex c, int n, complex z[]){
    z[0] = {0, 0};
    for(int i = 1; i < n; i++){
        z[i] = add(mul(z[i - 1], z[i - 1]),c);
    }
}

int main(){
    { complex c = { 0, 0 };
    const int n = 1;
    complex z[n];
    mandel(c, n, z);
    print(z, n); }
    //[ 0 ]
    { complex c = { 0, 0 };
    const int n = 3;
    complex z[n];
    mandel(c, n, z);
    print(z, n); }
    //[ 0 0 0 ]
    { complex c = { 1, 1 };
    const int n = 3;
    complex z[n];
    mandel(c, n, z);
    print(z, n); }
    //[ 0 1+1i 1+3i ]
    { complex c = { -1, 0 };
    const int n = 6;
    complex z[n];
    mandel(c, n, z);
    print(z, n); }
    //[ 0 -1 0 -1 0 -1 ]
    { complex c = { 0, 3 };
    const int n = 5;
    complex z[n];
    mandel(c, n, z);
    print(z, n); }
    //[ 0 +3i -9+3i 72-51i 2583-7341i ]
    return 0;
}
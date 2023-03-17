#include "complex.h"
#include <iostream>

using namespace std;

complex mul(complex z1, complex z2){
    return {z1.real * z2.real - z1.img * z2.img, z1.real * z2.img + z2.real * z1.img};
}

complex add(complex z1, complex z2){
    return {z1.real + z2.real, z1.img + z2.img};
}

void mandel(complex c, int n, complex z[]){
    complex z_0 = {0, 0};
    z[0] = z_0;
    for(int i = 1; i < n; i++){
        z[i] = add(mul(z[i - 1], z[i - 1]),c);
        z_0 = z[i - 1];
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
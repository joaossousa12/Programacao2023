#include "complex.h"
#include <iostream>

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r = {a.x + b.x, a.y + b.y};
}

void mul(const complex& a, const complex& b, complex& r){
    r = {a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y};
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    z_n = {0, 0};
 
    for(unsigned int i = 1; i <= n; i++){
        complex tmp;
        mul(z_n, z_n, tmp);
        add(tmp, c, z_n);
    }
}

int main(){
    { complex z_n; mandelbrot({1.2, 3.4}, 0, z_n);
    cout << z_n << '\n'; }
    //0.000+0.000i
    { complex z_n; mandelbrot({1, 1}, 1, z_n);
    cout << z_n << '\n'; }
    //1.000+1.000i
    { complex z_n; mandelbrot({1, 1}, 2, z_n);
    cout << z_n << '\n'; }
    //1.000+3.000i
    { complex z_n; mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n'; }
    //-0.624-2.499i
    { complex z_n; mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n'; }
    //2174.128-13121.836i
    { complex z_n; mandelbrot({-1, 0}, 11, z_n);
    cout << z_n << '\n'; }
    //-1.000+0.000i
    return 0;
}
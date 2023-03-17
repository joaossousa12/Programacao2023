#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r = {a.x + b.x, a.y + b.y};
    /* Other way to resolve the problem but doesn't work for mandelbrot.cpp
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    */
}

void mul(const complex& a, const complex& b, complex& r){
    r = {a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y};
    /* Other way to resolve the problem but doesn't work for mandelbrot.cpp
    r.x = (a.x * b.x - a.y * b.y);
    r.y = (a.x * b.y + b.x * a.y);
    */
}

double norm(const complex& c){
    return sqrt(pow(abs(c.x), 2) + pow(abs(c.y), 2));
}

int main(){
    { complex a { 0, 1 }, b { 2, 1}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //2.000+2.000i -1.000+2.000i 2.828 2.236
    { complex a { 1.2, 3.4 }, b { -1.2, 2.3}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //0.000+5.700i -9.260-1.320i 5.700 9.354
    { complex a { -1.5, 1 }, b { -1, 2}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //-2.500+3.000i -0.500-4.000i 3.905 4.031
    { complex a { -2, 2 }, b { 2, -2}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //0.000+0.000i 0.000+8.000i 0.000 8.000
    { complex a { 0, 0 }, b { 1.2, -3.4}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //1.200-3.400i 0.000+0.000i 3.606 0.000
    { complex a { 2, 0 }, b { 2.5, -3.1}, s, m; add(a, b, s); mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }
    //4.500-3.100i 5.000-6.200i 5.464 7.965
    return 0;
}
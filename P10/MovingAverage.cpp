#include <iostream>
#include <iomanip>
#include "MovingAverage.h"

using namespace std;

MovingAverage::MovingAverage(std::size_t n){
    n_ = n;
}

void MovingAverage::update(double value){
    if(values_.size() == n_){
        values_.pop_front();
    } 
    values_.push_back(value);
}

double MovingAverage::get() const{
    double result = 0;
    for(auto it : values_){
        result += it;
    }
    return result / values_.size();
}

int main(){
    { MovingAverage ma(1); 
    const MovingAverage& r = ma;
    ma.update(1.0); 
    cout << fixed << setprecision(2) << r.get() << '\n'; }
    //1.00
    { MovingAverage ma(1); 
    double a[] { 1.2, 3.4, 5.0 };
    for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
    }
    cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    //1.20 3.40 5.00 5.00
    { MovingAverage ma(2); 
    double a[] { 1.2, 3.4, 5.0 };
    for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
    }
    cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    //1.20 2.30 4.20 4.20
    { MovingAverage ma(3); 
    double a[] { 1.2, 3.4, 5.0 };
    for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
    }
    cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    //1.20 2.30 3.20 3.20
    { MovingAverage ma(4); 
    double a[] { 0.1, 1.2, -1.2, 3.4, 5.6, -2.3, 3.7 };
    for (double x : a) ma.update(x);
    cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    //2.60
    return 0;
}
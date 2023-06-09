#ifndef POINT_H
#define POINT_H

#include <vector>
#include <iostream>

using namespace std;

class Point{
    public:
        Point(); // 0,0
        Point(int x, int y);
        int get_x() const {return x_;};
        int get_y() const {return y_;};
        void show() const { std::cout << "(" << x_ << "," << y_ << ")"; }
    private:
        int x_, y_;
};

#endif
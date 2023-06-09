#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <cmath>
#include <iostream>

class Polygon{
    public:
        Polygon(); // {}
        Polygon(vector<Point> points);
        bool get_vertex(size_t x, Point &p);
        void add_vertex(size_t x, Point p);
        void show() const;
        double perimeter() const;
    private:
        vector<Point> points_;
};

#endif
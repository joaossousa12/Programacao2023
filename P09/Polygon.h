#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>
#include <cmath>

class Polygon{
    public:
        Polygon();
        Polygon(std::vector<Point> points);
        double perimeter() const;
        bool get_vertex(long unsigned int index, Point& p) const;
        bool add_vertex(long unsigned int index, Point p);
        void show() const;
    private:
        std::vector<Point> points_;
};

#endif
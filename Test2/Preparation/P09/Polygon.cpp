#include "Polygon.h"

Polygon::Polygon() : points_({}) {}

Polygon::Polygon(vector<Point> points) : points_(points) {}

bool Polygon::get_vertex(size_t x, Point &p){
    if(x < 1  || x > points_.size()) 
        return false;
    p = points_[x - 1];
    return true;
}

void Polygon::add_vertex(size_t x, Point p){
    if(x > 1 && x <= points_.size() + 1)
        points_.insert(points_.begin() + x - 1, p);
}

double distance_between_2_points(Point p1, Point p2){
    return sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2));
}

double Polygon::perimeter() const{
    double res = 0;
    for(size_t i = 0; i < points_.size(); i++){
        if(i + 1 == points_.size()) res += distance_between_2_points(points_[i], points_[0]);
        else res += distance_between_2_points(points_[i], points_[i + 1]);
    }
    return res;
}

void Polygon::show() const{
    std::cout << "{";
    for(Point p: points_) p.show();
    std::cout << "}";
}
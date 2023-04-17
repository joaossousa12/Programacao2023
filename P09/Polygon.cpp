#include "Polygon.h"

Polygon::Polygon(){
    points_ = {};
}

Polygon::Polygon(std::vector<Point> points){
    points_ = points;
}

double distance_between_2_points(Point p1, Point p2){
    return sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2));
}

double Polygon::perimeter() const{
    double res = 0;
    for(long unsigned int i = 0; i < points_.size(); i++){
        if(i + 1 == points_.size()) res += distance_between_2_points(points_[i], points_[0]);
        else res += distance_between_2_points(points_[i], points_[i + 1]);
    }
    return res;
}

bool Polygon::get_vertex(long unsigned int index, Point& p) const{
    if(index >= 1 && index <= points_.size()){
        p = points_[index - 1];
        return true;
    }
    return false;
}

bool Polygon::add_vertex(long unsigned int index, Point p){
    if(index >= 1 && index <= points_.size() + 1){
        points_.insert(points_.begin() + index - 1, p);
        return true;
    } else return false;
}


void Polygon::show() const{
    std::cout << "{";
    for(Point p: points_) p.show();
    std::cout << "}";
}
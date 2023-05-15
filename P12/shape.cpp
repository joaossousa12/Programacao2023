#include "Shape.h"
#include <cmath>

using namespace std;

class Circle : public Shape{
    public:
        Circle(const point& center, double radius) : Shape(center), radius_(radius) { }
        double area() const { return M_PI * pow(radius_, 2); }
        double perimeter() const { return 2 * M_PI * radius_; }
        bool contains(const point& p) const{
            double distance = sqrt(pow(p.x - get_center().x,2) + pow(p.y - get_center().y, 2));
            return distance < radius_;
        }
    private:
        double radius_;
};

class Rectangle : public Shape{
    public:
        Rectangle(const point& center, double width, double height) : Shape(center), width_(width), height_(height) { }
        double area() const { return width_ * height_; }
        double perimeter() const { return 2 * width_ + 2 * height_; }
        bool contains(const point& p) const{
            return p.x <= get_center().x + width_ / 2 && p.x >= get_center().x - width_ / 2 && p.y <= get_center().y + height_ / 2 && p.y >= get_center().y - height_ / 2;
        }
    private:
        double width_, height_;
};

int main(){
    { Circle c({1.0, 2.0}, 1.0); 
    const point& p = c.get_center();
    cout << fixed << setprecision(2) 
    << '(' << p.x << ',' << p.y << ')' << ' '
    << c.area() << ' ' << c.perimeter() << '\n'; }
    //(1.00,2.00) 3.14 6.28
    { Rectangle r({3.4, 4.5}, 1, 2); 
    const point& p = r.get_center();
    cout << fixed << setprecision(2) 
    << '(' << p.x << ',' << p.y << ')' << ' '
    << r.area() << ' ' << r.perimeter() << '\n'; }
    //(3.40,4.50) 2.00 6.00
    { const Shape& s1 = Circle({1, 2}, 3); 
    const Shape& s2 = Rectangle({4, 5}, 6, 7); 
    cout << fixed << setprecision(2) << boolalpha
    << s1.area() << ' ' << s1.perimeter() << ' '
    << s1.contains({1, 2}) << ' ' << s1.contains({ 4, 5 }) << ' '
    << s2.area() << ' ' << s2.perimeter() <<  ' '
    << s2.contains({1, 2}) << ' ' << s2.contains({ 4, 5 }) << '\n'; }
    //28.27 18.85 true false 42.00 26.00 true true
    { Circle c({1, 2}, 3);
    point a [] { 
    { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0 }, { 3.9,  2.0 }, 
    {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1 }, { 1.0, -1.1 }, 
    {  1.2, -0.3 }, {  5.2,  5.1 }, { 2.1, -0.5 }, { 3.2,  5.5 } };
    cout << fixed << setprecision(2);
    for (point& p : a)  
    if (c.contains(p))
    cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n';  } 
    //(-1.90,2.00)(3.90,2.00)(1.00,4.90)(1.00,-0.90)(1.20,-0.30)(2.10,-0.50)
    { Rectangle r({1, 2}, 6, 8);
    point a [] { 
    { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0 }, { 3.9,  2.0 }, 
    {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1 }, { 1.0, -1.1 }, 
    {  1.2, -0.3 }, {  5.2,  5.1 }, { 2.1, -0.5 }, { 3.2,  5.5 } };
    cout << fixed << setprecision(1);
    for (point& p : a)  
    if (r.contains(p)) 
    cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n'; }
    //(-1.9,2.0)(3.9,2.0)(1.0,4.9)(1.0,-0.9)(1.0,5.1)(1.0,-1.1)(1.2,-0.3)(2.1,-0.5)(3.2,5.5)
    return 0;
}


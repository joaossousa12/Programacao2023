#include "Solid.h"

class Cylinder : public Solid {
    public:
        Cylinder(const point& c, const double radius, const double height) : Solid(c) ,radius_(radius), height_(height) {}
        const double radius() const {return radius_;}
        const double height() const {return height_;}
        double area() const override{
            return 2 * M_PI * radius_ * (radius_ + height_);
        }
    private:
        double radius_, height_;
};


int main(){
    { const Cylinder c({0, 0, 0}, 1, 1);
    cout << c.center() << ' ' 
        << c.radius() << ' ' 
        << c.height() << ' ' 
        << c.area() << endl; }
    //(0.000,0.000,0.000) 1.000 1.000 12.566
    { const Cylinder c({0.1, 2.3, 4.5}, 1.2, 3.4);
    cout << c.center() << ' ' 
        << c.radius() << ' ' 
        << c.height() << ' ' 
        << c.area() << endl; }
    //(0.100,2.300,4.500) 1.200 3.400 34.683
    { const Solid& s = Cylinder({-1.2, -3.4, -5.6}, 1.2, 0.34);
    cout << s.center() << ' ' << s.area() << endl; }
    //(-1.200,-3.400,-5.600) 11.611
    { const Solid& s = Cylinder({12.3, 34.5, 56.7}, 12.3, 0.51);
    cout << s.center() << ' ' << s.area() << endl; }
    //(12.300,34.500,56.700) 989.998
    return 0;
}
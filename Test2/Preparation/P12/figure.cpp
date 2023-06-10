#include "Figure.h"
#include <iostream>
#include <vector>

using namespace std;

class Rectangle : public Figure{
    public:
        Rectangle(double x_center = 0, double y_center= 0, double width = 0, double height = 0) : Figure(x_center, y_center), width_(width), height_(height) {}
        void draw() const override{
            cout << "R(" << Figure::x_center_ << ',' << Figure::y_center_ << ")(" << width_ << ',' << height_ << ')';
        }
    private:
        double width_, height_;
};

class Circle : public Figure{
    public:
        Circle(double x_center= 0, double y_center=0, double radius = 0) : Figure(x_center, y_center), radius_(radius) {}
        void draw() const override{
            cout << "C(" << Figure::x_center_ << ',' << Figure::y_center_ << ")(" << radius_ << ')';
        }
    private:
        double radius_;
};

int main(){
    { Rectangle r(10, 10, 200, 100);
    r.draw(); cout << endl; }
    //R(10,10)(200,100)
    { Circle c (20, 20, 500);
    c.draw(); cout << endl; }
    //C(20,20)(500)
    { Rectangle * r = new Rectangle(10, 10, 200, 100);
    r->draw(); cout << endl; delete r; }
    //R(10,10)(200,100)
    { vector<Figure*> figures = {
    new Rectangle(10,10,200,100),
    new Circle(20,20,500),
    new Rectangle(-10,-20,150,250),
    new Circle(0,0,100) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f; }
    //R(10,10)(200,100)C(20,20)(500)R(-10,-20)(150,250)C(0,0)(100)
    { vector<Figure*> figures = {
    new Rectangle(-10,-10,5,15),
    new Rectangle(0,0,20,10),
    new Circle(5,0,25) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f; }
    //R(-10,-10)(5,15)R(0,0)(20,10)C(5,0)(25)
    return 0;
}
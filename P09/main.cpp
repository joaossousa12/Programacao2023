#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#include "Polygon.h"

int main(){
    { Point p1, p2(0, 1); 
    p1.show(); p2.show(); cout << '\n'; }
    //(0,0)(0,1)

    { Polygon poly1;
    Point p1, p2(0, 1), p3(1, 0);
    Polygon poly2(vector<Point>{ p1, p2, p3 });
    poly1.show(); cout << " "; poly2.show(); cout << '\n'; }
    //{} {(0,0)(0,1)(1,0)}
    
    { Point p1, p2(0, 1), p3(1, 0);
    Polygon poly1(vector<Point> { p1, p2, p3 });
    cout << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }
    //3.414
    
    { Point p1, p2(0, 1), p3(1, 0);
    Polygon poly1(vector<Point>{ p1, p2, p3 });
    Point p;
    if (poly1.get_vertex(2, p)) { p.show(); cout << ' '; }
    else cout << "vertex not found! ";
    if (poly1.get_vertex(0, p)) { p.show(); cout << ' '; }
    else cout << "vertex not found! ";
    cout << '\n'; }
    //(0,1) vertex not found!
    
    { Point p1, p2(0, 1), p3(1, 0), p4(1, 1);
    Polygon poly1 = vector<Point> { p1, p2, p3 };
    poly1.add_vertex(3, p4); 
    poly1.show(); 
    cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }
    //{(0,0)(0,1)(1,1)(1,0)} 4.000
   return 0;
}
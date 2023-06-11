#include "Student.h"
#include <iomanip>
#include <iostream>

using namespace std;

Student::Student(const std::string& name, const std::string& id, 
          short ac, short p1, short p2) : name_(name), id_(id), ac_(ac),
          p1_(p1), p2_(p2) {}

string Student::get_id() const{
    return id_;
}

string Student::get_name() const{
    return name_;
}

double Student::actual_grade() const{
    return 0.1 * ac_ + 0.45 * p1_ + 0.45 * p2_;
}

int main(){
    { Student s("Andre Meira", "up201404877", 20, 18, 10);
    cout << "[" << s.get_id() << "]" << "/";
    cout << fixed << setprecision(2) << s.actual_grade() << endl; }
    //[up201404877]/14.60
    { Student s("John Doe", "up19790007", 20, 20, 20);
    cout << "[" << s.get_id() << "]" << "/";
    cout << fixed << setprecision(2) << s.actual_grade() << endl; }
    //[up19790007]/20.00
    { Student s("Graham Chapman", "up19790077", 10, 10, 10);
    cout << "[" << s.get_id() << "]" << "/";
    cout << fixed << setprecision(2) << s.actual_grade() << endl; }
    //[up19790077]/10.00
    { Student s("John Cleese", "up19790077", 8, 7, 13);
    cout << "[" << s.get_id() << "]" << "/";
    cout << fixed << setprecision(2) << s.actual_grade() << endl; }
    //[up19790077]/9.80

    return 0;
}
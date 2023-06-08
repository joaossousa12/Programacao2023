#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student(const std::string& id) : id_(id) {}

std::string Student::get_id() const{
    return id_;
}

void Student::add(const course& c){
    courses_.push_back(c);
}

double Student::avg() const{
    double num = 0, den = 0;
    for(size_t i = 0; i < courses_.size(); i++){
        num += courses_[i].credits * courses_[i].grade;
        den += courses_[i].credits;
    }
    if(den == 0) return 0;
    return num / den;
}


int main(){
    { Student s("up2022001111");
    s.add({"FP", 6, 20});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl; }
    //[up2022001111]/20.00
    { Student s("up2022002222");
    s.add({"MD", 6, 18}); s.add({"AMI", 6, 16}); s.add({"FSC", 6, 14});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl; }
    //[up2022002222]/16.00
    { Student s("up2022003333");
    s.add({"ALGA", 4.5, 18}); s.add({"AMI", 6, 16}); s.add({"PUP", 1.5, 14});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl; }
    //[up2022003333]/16.50
    { Student s("up2022004444");
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl; }
    //[up2022004444]/0.00
    return 0;
}
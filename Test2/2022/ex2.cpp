#include "Student.h"
#include <iomanip>
#include <iostream>

using namespace std;

Student::Student(const std::string& id){
    id_ = id;
}

string Student::get_id() const {
    return id_;
}

void Student::add(const course& c){
    courses_.push_back(c);
}

double Student::avg() const{
    float den = 0;
    float num = 0;
    for(course courses : courses_){
        if(courses.grade >= 10){
            num += courses.grade * courses.credits;
            den += courses.credits;
        }
    }
    if(den == 0) return den;
    else return num / den;
}

int main(){
    Student s("up2022002222");
    s.add({"MD", 6, 18}); s.add({"AM1", 6, 16}); s.add({"FSC", 6, 14});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
    return 0;
}
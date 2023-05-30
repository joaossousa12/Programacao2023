#include "Student_b.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student(const std::string& id) : id_(id) {}

string Student::get_id() const{
    return id_;
}

void Student::add(const course& c){
    courses_.push_back(c);
}

double Student::avg() const {
    double den = 0;
    double num = 0;
    for(auto c : courses_){
        if(c.grade < 10) continue;
        den += c.credits;
        num += c.credits * c.grade;
    }
    if(den == 0) return 0;
    return num / den;
}

int main(){
    Student s("up2022004444");
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
    return 0;
}
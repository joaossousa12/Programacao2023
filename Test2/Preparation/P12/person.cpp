#include "Person.h"
#include <iostream>

class Student : public Person{
    public:
        Student(int id, const string& name, const string& course) : Person(id, name), course_(course) {}
        const string& course() const {return course_;}
        string to_string() const override{
            ostringstream oss;
            oss << Person::to_string() << '/' << course_;
            return oss.str();
        }
    private:
        std::string course_;
};

class ErasmusStudent : public Student{
    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id, name, course), country_(country) {}
        const string& country() const {return country_;}
        string to_string() const override{
            ostringstream oss;
            oss << Student::to_string() << '/' << country_;
            return oss.str();
        }
    private:
        std::string country_;
};

int main(){
    { const Person& p = Student(123, "Manuel Dias", "LEIC");
    cout << p.id() << ' ' << p.name() << '\n'; }
    //123 Manuel Dias
    { const Student& s = ErasmusStudent(124, "John Zorn", "LXPTO", "United States");
    cout << s.id() << ' ' << s.name() << ' ' << s.course() << '\n'; }
    //124 John Zorn LXPTO
    { Student s(123, "Manuel Dias", "LEIC");
    cout << s.id() << ' ' << s.name() << ' '  << s.course() << '\n'; }
    //123 Manuel Dias LEIC
    { ErasmusStudent es(124, "John Zorn", "LXPTO", "United States");
    cout << es.id() << ' ' << es.name() << ' ' << es.course() << ' ' << es.country() << '\n'; }
    //124 John Zorn LXPTO United States
    { Person p(125, "Marie Curie");
    Student s(126, "Ada Lovelace", "LEIC");
    ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
    cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n'; }
    //125/Marie Curie 126/Ada Lovelace/LEIC 127/Grace Hopper/LXPTO/United States
    return 0;
}
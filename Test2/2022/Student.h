#ifndef INC_2022_STUDENT_H
#define INC_2022_STUDENT_H

#include <string>
#include <vector>

struct course{
    std::string name;
    float credits;
    short grade;
};

class Student {
public:
    // constructor with parameters
    Student(const std::string& id);
    // accessor
    std::string get_id() const;
    //member functions
    void add(const course& c); // add a course grade
    double avg() const; // calculate the average grade
private:
    std::string id_;
    std::vector<course> courses_;
};

#endif //INC_2022_STUDENT_H

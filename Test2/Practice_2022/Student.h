#include <string>

class Student{
    public:
        Student(const std::string& name, const std::string& id, short ac, short p1, short p2);
        std::string get_id() const;
        std::string get_name() const;
        double actual_grade() const;
    private:
        std::string name_;
        std::string id_;
        short ac_, p1_, p2_;
};
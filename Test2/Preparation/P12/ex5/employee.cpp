#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <iostream>
#include <vector>

using namespace std;

void SalariedEmployee::calculate_net_pay(){
    set_net_pay(salary_);
}

void HourlyEmployee::calculate_net_pay(){
    set_net_pay(wage_rate_ * hours_);
}

void read_hours_worked(vector<Employee *> employee){
    for(auto& e : employee){
        HourlyEmployee* hourlyEmployee = dynamic_cast<HourlyEmployee *> (e);
        if(hourlyEmployee != nullptr){
            double h;
            cin >> h;
            hourlyEmployee->set_hours(h);
        }
    }
}

void calculate_pay(vector<Employee *> employee){
    for(auto e: employee){
        e->calculate_net_pay();
    }
}

void print_checks(vector<Employee *> employee){
    cout << "| ";
    for(auto e: employee){
        e->print_check();
        cout << " | ";
    }
    cout << '\n';
}

int main(){
    { vector<Employee*> employees = {
    new SalariedEmployee("John", 2000),
    new HourlyEmployee("Mary", 10) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e; }
    //Entry: 100
    //Result: | John:SE(2000.00)=2000.00 | Mary:HE(100.00,10.00)=1000.00 |
    { vector<Employee*> employees = {
    new HourlyEmployee("Peter", 10.31),  
    new SalariedEmployee("Ann", 1957.4) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e; }
    //Entry: 175.5
    //Result: | Peter:HE(175.50,10.31)=1809.41 | Ann:SE(1957.40)=1957.40 |
    { vector<Employee*> employees = {
    new HourlyEmployee("Philip", 10.75),
    new HourlyEmployee("Elisabeth", 9.5),
    new SalariedEmployee("Charles", 5000) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e; }
    //Entry: 200.25 199.75
    //Result: | Philip:HE(200.25,10.75)=2152.69 | Elisabeth:HE(199.75,9.50)=1897.62 | Charles:SE(5000.00)=5000.00 |
    { vector<Employee*> employees = {
    new SalariedEmployee("John", 2123.5),
    new SalariedEmployee("Peter", 1999.9) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e; }
    //Result: | John:SE(2123.50)=2123.50 | Peter:SE(1999.90)=1999.90 |
    return 0;
}
#include "Date3.h"
#include <sstream>
#include <iomanip>

using namespace std;

Date::Date(){
    yyyymmdd = "00010101";
}

Date::Date(int year, int month, int day){
    if(year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)){
        ostringstream oss;
        oss << setfill('0') << setw(4) << year << setw(2) << month << setw(2) << day;
        yyyymmdd = oss.str();
    } else {
        yyyymmdd = "00000000";
    }
}

Date::Date(const std::string& year_month_day){
    int year, month, day;
    char slash, slash1;
    istringstream iss(year_month_day);
    if(iss >> year >> slash >> month >> slash1 >> day && slash == slash1 && slash == '/' && year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)){
        ostringstream oss;
        oss << setfill('0') << setw(4) << year << setw(2) << month << setw(2) << day;
        yyyymmdd = oss.str();
    } else{
        yyyymmdd = "00000000";
    }
}

int Date::get_year() const{
    return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const{
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const{
    return stoi(yyyymmdd.substr(6, 2));
}

int Date::num_days(int year, int month){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    else if(month == 4 || month == 6 || month == 11) return 30;
    else{
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) return 29;
        else return 28;
    }
}

bool Date::is_valid() const{
    return yyyymmdd != "00000000";
}

int main(){
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    //0001/01/01
    Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    //0000/00/00-invalid
    Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
    //0000/00/00-invalid
    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    //1900/01/01
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
    //0000/00/00-invalid
    return 0;
}
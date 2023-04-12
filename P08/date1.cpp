#include "Date1.h"

using namespace std;

Date::Date(){
    year = 1;
    day = 1;
    month = 1;
}

Date::Date(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_day() const{
    return day;
}

int Date::get_month() const{
    return month;
}

int Date::get_year() const{
    return year;
}

bool is_before(const Date& date1, const Date& date2){
    if(date1.get_year() > date2.get_year() || (date1.get_year() == date2.get_year() && date1.get_month() > date2.get_month()) || (date1.get_year() == date2.get_year() && date1.get_month() == date2.get_month() && date1.get_day() > date2.get_day())){
        return false;
    }
    return true;
}

int main(){
    Date d1; d1.write(); cout << '\n';
    //0001/01/01
    Date d2(2020, 2, 29); d2.write(); cout << '\n';
    //2020/02/29
    Date d3(1925, 4, 30); d3.write(); cout << '\n';
    //1925/04/30
    Date d4, d5(2022,4,29); d4.write(); cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    //0001/01/01-true
    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    //2023/10/31-false

    return 0;
}
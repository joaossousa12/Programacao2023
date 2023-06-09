#include "Date.h"

Date::Date() : year_(1), month_(1), day_(1) {}

Date::Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

bool Date::is_before(const Date& date) const {
    if(year_ < date.year_ || (year_ == date.year_ && month_ < date.month_) || (year_ == date.year_ && month_ == date.month_ && day_ == date.day_))
        return true;
    return false;
}
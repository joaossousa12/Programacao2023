#include "Date.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Date& d){
    os << setw(4) << setfill('0') << d.getYear() << '/' << setw(2) << setfill('0') << d.getMonth() << '/' << setw(2) << setfill('0') << d.getDay();
    return os;
}

bool operator<(Date& d1, Date& d2){
    if(d1.getYear() < d2.getYear() || (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth()) || (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay())) return true;
    else return false;
}

int main(){
    { vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n'; }
    //2021/12/08 2023/11/14 2023/11/15
    { vector<Date> dates = { {2000,1,1}, {2000,2,1}, {2000,12,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n'; }
    //2000/01/01 2000/02/01 2000/12/31 
    { vector<Date> dates = { {2001,10,31}, {2005,10,31}, {2010,10,31}, {1992,10,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n'; }
    //1992/10/31 2001/10/31 2005/10/31 2010/10/31
    { vector<Date> dates = { {2023,4,28}, {999,1,1} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n'; }
    //0999/01/01 2023/04/28
    { vector<Date> dates = { {2075,2,2}, {2077,10,10}, {2075,2,2}};
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n'; }
    //2075/02/02 2075/02/02 2077/10/10
    return 0;
}


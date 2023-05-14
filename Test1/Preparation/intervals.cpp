#include "interval.h"

bool is_greater(time_of_day a, time_of_day b){
    if(a.h > b.h || (a.h == b.h && a.m > b.m)) return true;
    else return false;
}

bool checker(time_of_day t, time_of_day start, time_of_day end){
    if(t.h > start.h || (t.h == start.h && t.m >= start.m)){
        if(t.h < end.h || (t.h == end.h && t.m < end.m)) return true;
    }
    return false;
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    int result = 0;
    u = {t, t};
    for(int i = 0; i < n; i++){
        if(checker(t, a[i].start, a[i].end)){
            if(is_greater(u.start, a[i].start)) u.start = a[i].start;
            if(!is_greater(u.end, a[i].end)) u.end = a[i].end;
            result = (u.end.h - u.start.h) * 60 + u.end.m - u.start.m;
        }
    }
    return result;
}

int main(){
    { const int n = 1;
    const time_of_day t = { 13, 00 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }
    //120 [12:30,14:30[
    { const int n = 2;
    const time_of_day t = { 14, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }
    //60 [14:30,15:30[
    { const int n = 2;
    const time_of_day t = { 12, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }
    //120 [12:30,14:30[
    { const int n = 2;
    const time_of_day t = { 15, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; } 
    //0 [15:30,15:30[
    { const int n = 5;
    const time_of_day t = { 15, 15 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
    { { 14, 30 }, { 15, 30 } }, 
    { { 15, 10 }, { 16, 10 } }, 
    { {  9, 30 }, { 15, 15 } }, 
    { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; } 
    //385 [09:45,16:10[
    return 0;
}
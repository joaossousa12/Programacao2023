#include <iostream> 
#include "interval.h"

using namespace std;

bool is_greater(time_of_day a, time_of_day b){
    if(a.h > b.h || (a.h == b.h && a.m > b.m)) return true;
    else return false;
}

bool is_greater_or_equal(time_of_day a, time_of_day b){
    if(a.h == b.h && a.m == b.m) return true;
    else if(a.h > b.h || (a.h == b.h && a.m > b.m)) return true;
    else return false;
}

interval intersection(interval a, interval b){
    if((is_greater_or_equal(a.start, b.end)) || (is_greater_or_equal(b.start, a.end))) return {{0, 0}, {0, 0}};
    if(a.start.h == b.start.h && a.start.m == b.start.m){
        if(is_greater(a.end, b.end)) return {a.start, a.end};
        else return {a.start, b.end};
    }
    if(is_greater(a.start, b.start)){ // b.start (will be the start hour)
        if(is_greater(a.end, b.end)) return {a.start, b.end};
        else return {a.start, a.end};
    } else{
        if(is_greater(a.end, b.end)) return {b.start, b.end};
        else return {b.start, a.end};
    }
}

int main(){
    cout << intersection( { { 12, 30 }, { 14, 30 } }, { { 17, 30 }, { 18, 30 } } ) << '\n';
    //[00:00,00:00[
    cout << intersection( { { 12, 30 }, { 14, 30 } }, { { 14, 30 }, { 18, 30 } } ) << '\n';
    //[00:00,00:00[
    cout << intersection( { { 12, 30 }, { 14, 31 } }, { { 14, 30 }, { 18, 30 } } ) << '\n';
    //[14:30,14:31[
    cout << intersection( { { 14, 30 }, { 15, 59 } }, { { 11, 30 }, { 14, 31 } } ) << '\n';
    //[14:30,14:31[
    cout << intersection( { {  4, 30 }, {  7, 59 } }, { {  4,  0 }, {  7, 29 } } ) << '\n';
    //[04:30,07:29[
    cout << intersection( { { 23,  0 }, { 23, 58 } }, { { 22, 45 }, { 23, 59 } } ) << '\n';
    //[23:00,23:58[
    return 0;
}
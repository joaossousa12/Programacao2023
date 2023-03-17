#include <iostream>

using namespace std;

bool is_leap_year(int y){
    if(y % 4 == 0){
        if(y % 100 == 0 && y % 400 != 0) return false;
        return true;
    }
    return false;
}

void advance(int delta, int& d, int& m, int& y){
    while(delta != 0){
        switch(m){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                d++;
                delta--;
                if(d > 31){
                    d = 1;
                    m++;
                    if(m > 12){
                        m = 1;
                        y++;
                    }
                }
                break;
            case 2:
                d++;
                delta--;
                if(is_leap_year(y)){
                    if(d > 29){
                        d = 1;
                        m++;
                    }
                } else{
                    if(d > 28){
                        d = 1;
                        m++;
                    }
                }
                break;
            default:
                d++;
                delta--;
                if(d > 30){
                    d = 1;
                    m++;
                }
                break;
        }
    }
}


int main(){
    int d = 1, m = 1, y = 2022; 
    advance(0, d, m, y); 
    cout << d << ' ' << m << ' ' << y;
    //1 1 2022
    d = 1, m = 10, y = 2022; 
    advance(10, d, m, y); 
    cout << d << ' ' << m << ' ' << y;
    //11 10 2022
    d = 2, m = 6, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //3 7 2022
    d = 2, m = 7, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //2 8 2022
    d = 25, m = 2, y = 2000; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //29 2 2000
    d = 25, m = 2, y = 2001; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //1 3 2001
    d = 2, m = 12, y = 1900; 
    advance(365 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //7 12 1901
    d = 31, m = 3, y = 1903; 
    advance(365 + 366 + 30 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    //5 5 1905
    return 0;
}
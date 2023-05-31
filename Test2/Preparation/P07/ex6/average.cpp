#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

double average(const string& fname){
    ifstream in(fname);
    double x;
    double den = 0.0;
    int num = 0;
    while(!in.eof()){
        if(in >> x){
            den += x;
            num++;
        } else{
            in.clear();
            in.ignore(1);
        }
    }
    return den / num;
}

int main(){
    { double m = average("p6_test1.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //2.50
    { double m = average("p6_test2.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //2.50
    { double m = average("p6_test3.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //0.75
    { double m = average("p6_test4.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //1.00
    { double m = average("p6_test5.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //3.50
    return 0;
}
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

double average(const string& fname){
    ifstream in(fname);
    double num;
    double result = 0.0;
    int counter = 0;
    while(!in.eof()){
        if(in >> num){
            result += num;
            counter ++;
        } else{
            in.clear();
            in.ignore(1);
        }
    }
    return result / counter;
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
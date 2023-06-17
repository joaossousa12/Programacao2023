#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

string student_lowest_avg(map<string, list<int>> m){
    double lowest = 22.0;
    string result;
    for(auto c : m){
        double num = 0.0, den = 0.0;
        for(auto l: c.second){
            den++;
            num += l;
        }
        if((num / den) < lowest){
            lowest = (num / den);
            result = c.first;
        }

    }
    return result;
}

int main(){
    { map<string, list<int>> m1 = {
      {"Jerry", {10, 20, 15}}};
    cout << student_lowest_avg(m1) << endl; }
    //Jerry
    { map<string, list<int>> m2 = {
        {"Newman", {15, 18, 14, 16}}, {"Elaine", {18, 12, 19}}};
    cout << student_lowest_avg(m2) << endl; }
    //Newman
    { map<string, list<int>> m3 = {
        {"Tim", {10, 10}}, {"Bania", {11, 12, 14}}, {"Frank", {15, 10, 13}}};
    cout << student_lowest_avg(m3) << endl; }
    //Tim
    { map<string, list<int>> m4 = {
        {"Kramer", {0, 11}}, {"Costanza", {8, 12}}};
    cout << student_lowest_avg(m4) << endl; }
    //Kramer
    { map<string, list<int>> m5 = {
        {"Costanza", {10, 15}}, {"Frank", {10, 14}}};
    cout << student_lowest_avg(m5) << endl; }
    //Frank
    return 0;
}
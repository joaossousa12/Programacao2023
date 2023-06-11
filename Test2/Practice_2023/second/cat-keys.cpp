#include <iostream>
#include <list>
#include <map>
#include <climits>

using namespace std;

string cat_keys(list<map<string, unsigned>> lst){
    string result;
    unsigned min = UINT_MAX;
    for(auto l : lst){
        string temp;
        int flag = 0;
        for(auto m : l){
            temp += m.first;
            if(m.second < min){
                flag = 1;
                min = m.second;
            }
        }
        if(flag == 1) result = temp;
    }
    return result;
}

int main(){
    { list<map<string, unsigned>> m2 = {
    { {"s1", 13}, {"s2", 2} } };
    cout << cat_keys(m2) << endl; }
    //s1s2
    { list<map<string, unsigned>> m1 = {
    { {"s1", 1} } };
    cout << cat_keys(m1) << endl; }
    //s1
    { list<map<string, unsigned>> m3 = {
    { {"s1", 13}, {"s2", 2} }, 
    { {"s3", 3}, {"s4", 4} }, { {"s5", 16} } };
    cout << cat_keys(m3) << endl; }
    //s1s2
    { list<map<string, unsigned>> m4 = {
    { {"s1", 13}, {"s2", 4} }, { {"s3", 3}, {"s4", 4} } };
    cout << cat_keys(m4) << endl; }
    //s3s4
    return 0;
}
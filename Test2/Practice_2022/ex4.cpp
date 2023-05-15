#include <iostream>
#include <list>
#include <map>
#include <climits>
#include <sstream>

using namespace std;

string cat_keys(list<map<string,unsigned>> lst){
    string first = "";
    unsigned second = UINT_MAX;
    string res = "";
    for(auto it : lst){
        for(auto m: it){
            if(m.second < second){
                second = m.second;
                first = m.first;
                res = "";
                for(auto m : it) res+=m.first;
            }
        }
    }
    return res;
}

int main(){
    {
        list<map<string, unsigned>> m2 = {{{"s1", 13}, {"s2", 2}}};
        cout << cat_keys(m2) << endl; //s1s2
    }
    {
        list<map<string, unsigned>> m1 = {{{"s1", 1}}};
        cout << cat_keys(m1) << endl; //s1
    }
    {
        list<map<string, unsigned>> m3 = {{{"s1", 13}, {"s2", 2}}, {{"s3", 3}, {"s4", 4}}, {{"s5", 16}}};
        cout << cat_keys(m3) << endl; //s1s2
    }
    {
        list<map<string, unsigned>> m4 = {{{"s1", 13}, {"s2", 4}}, {{"s3", 3}, {"s4", 4}}};
        cout << cat_keys(m4) << endl; //s3s4
    }
    return 0;
}
#include <map>
#include <climits>
#include <iostream>
#include <list>
#include <string>

using namespace std;

string smallest_sum_key(map<string, list<int>> m){
    int min = INT_MAX;
    string result;
    for(auto m1 : m){
        int sum = 0;
        for(auto it : m1.second){
            sum += it;
        }
        if(min > sum){
            result = m1.first;
            min = sum;
        }
    }

    return result;
}

int main(){
    map<string, list<int>> m3 = {
        {"s1", {10,100}}, {"s2",{101,100,100}}, {"s3", {100,5,4}}
    };
    cout << smallest_sum_key(m3) << endl;
    return 0;
}
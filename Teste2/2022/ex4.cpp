#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

string smallest_sum_key(map<string, list<int>> m){
    string key;
    int smallest_sum = INT_MAX;
    for(auto s : m){
        int curr = 0;
        for(int l : s.second){
            curr += l;
        }
        if(curr < smallest_sum){
            smallest_sum = curr;
            key = s.first;
        }
    }

    return key;
}

int main(){
    map<string, list<int>> m4 = {
        {"s1", {-100, -100}}, {"s2", {-200, -100}}
    };
    cout << smallest_sum_key(m4) << endl;
    return 0;
}
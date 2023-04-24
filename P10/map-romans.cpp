#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

unsigned roman_to_arab(const string& roman){
    unsigned result = 0;
    for(size_t i = 0; i < roman.size() - 1;  i++){
        int first;
        int second;

        for(auto p: roman_to_int){
            if(p.first == roman[i]) first = p.second;
            if(p.first == roman[i + 1]) second = p.second;
        }

        if(first >= second){
            result += first;
        } else {
            result -= first;
        }

        if(i == roman.size() - 2) result += second;
    }
    return result;
}

int main(){
    { string r = "XV"; cout << roman_to_arab(r) << '\n'; }
    //15
    { string r = "LXXXIV"; cout << roman_to_arab(r) << '\n'; }
    //84
    { string r = "CMLXIV"; cout << roman_to_arab(r) << '\n'; }
    //964
    { string r = "MMMCMXCIX"; cout << roman_to_arab(r) << '\n'; }
    //3999
    { string r = "MMMDCCCLXXXVIII"; cout << roman_to_arab(r) << '\n'; }
    //3888
    return 0;
}
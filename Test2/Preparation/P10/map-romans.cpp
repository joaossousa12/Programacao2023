#include <string>
#include <iostream>
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

unsigned get_value(char c){
    for(auto r : roman_to_int){
        if(r.first==c)
            return r.second;
    }
    return 0; // should never reach here anyways
}

unsigned roman_to_arab(const string& roman){
    unsigned result = 0;
    for(size_t i = 0; i < roman.size() - 1; i++){
        if(get_value(roman[i]) < get_value(roman[i + 1])){
            result -= get_value(roman[i]);
        } else {
            result += get_value(roman[i]);
        }
    }

    return result + get_value(roman[roman.size() - 1]);
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
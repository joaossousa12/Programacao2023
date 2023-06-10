#include <iostream>
#include <string>
#include <map>

using namespace std;

void replace(const map<char, char>& r, string& s){
    for(auto &c : s){
        for(auto r1 : r){
            if(r1.first==c) {
                c = r1.second;
                break;
            }
        }
    }
}

int main(){
    { string s = "C / C++ @ LEIC";
    replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
    cout << s << '\n'; }
    //z / z-- @ XEIz
    { string s = "C / C++ @ LEIC";
    replace({ }, s);
    cout << s << '\n'; }
    //C / C++ @ LEIC
    { string s = "A B C D E F";
    replace({ {' ', '_'}}, s);
    cout << s << '\n'; }
    //A_B_C_D_E_F
    { string s = "A B C D E F";
    replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
    cout << s << '\n'; }
    //? B C D E !
    return 0;
}
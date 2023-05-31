#include "print_string.h"

void split(const string& s, vector<string>& v){
    size_t i = 0;
    while(i < s.size()){
        string::size_type n = s.find(' ', i);
        if(n == string::npos){
            n = s.size();
        }
        if(n > i){
            v.push_back(s.substr(i, n - i));
        }
        i = n + 1;
    }
}


int main(){
    { string s = "";
    vector<string> v;
    split(s, v);
    print(v); }
    //[ ]
    { string s = "    ";
    vector<string> v;
    split(s, v);
    print(v); }
    //[ ]
    { string s = "  a b  c ";
    vector<string> v;
    split(s, v);
    print(v); }
    //[ "a" "b" "c" ]
    { string s = "C++ LEIC FCUP FEUP";
    vector<string> v;
    split(s, v);
    print(v); }
    //[ "C++" "LEIC" "FCUP" "FEUP" ]
    { string s = "       C++        ";
    vector<string> v;
    split(s, v);
    print(v); }
    //[ "C++" ]
    return 0;
}
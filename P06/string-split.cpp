#include "print_string.h"

void split(const string& s, vector<string>& v){
    long unsigned int pos = 0;
    int len = 0;
    while(pos < s.length()){
        if(s.find(' ', pos) == pos){
            if(len > 0){
                v.push_back(s.substr(pos - len, len));
                len = 0;
            }
        }
        else len++;
        pos++;
    }
    if(len > 0){
        v.push_back(s.substr(pos - len, len));
        len = 0;
    }
}

int main(){
    { string s = "";
    vector
    <string>
    v;
    split(s, v);
    print(v); }
    //[ ]
    { string s = "    ";
    vector
    <string>
    v;
    split(s, v);
    print(v); }
    //[ ]
    { string s = "  a b  c ";
    vector
    <string>
    v;
    split(s, v);
    print(v); }
    //[ "a" "b" "c" ]
    { string s = "C++ LEIC FCUP FEUP";
    vector
    <string>
    v;
    split(s, v);
    print(v); }
    //[ "C++" "LEIC" "FCUP" "FEUP" ]
    { string s = "       C++        ";
    vector
    <string>
    v;
    split(s, v);
    print(v); }
    //[ "C++" ]
    return 0;
}
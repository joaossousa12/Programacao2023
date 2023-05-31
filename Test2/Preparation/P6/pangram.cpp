#include <iostream>
#include <string>

using namespace std;

bool pangram(const string& s, string& m){
    bool result = true;
    int alphabet[26] {0};

    for(auto c : s){
        if(c >= 'a' && c <= 'z') alphabet[c - 'a']++;
        else if(c >= 'A' && c <= 'Z') alphabet[c - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(alphabet[i] == 0){
            m += 'a' + i;
            result = false;
        }
    }

    return result;
}

int main(){
    { string s = "";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" "
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"" false "abcdefghijklmnopqrstuvwxyz"
    { string s = "The quick brown fox jumps over the lazy dog";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"The quick brown fox jumps over the lazy dog" true ""
    { string s = "A quick brown fox jumps over a classy dog";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"A quick brown fox jumps over a classy dog" false "htz"
    { string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ " true ""
    { string s = " Stu yZ abC GhI MnO pQr   ";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //" Stu yZ abC GhI MnO pQr   " false "defjklvwx"
    return 0;
}
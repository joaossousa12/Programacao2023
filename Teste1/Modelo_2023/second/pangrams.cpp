#include <iostream>

using namespace std;

bool pangram(const char s[], char m[]){
    int alphabet[26] {0};
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <= 'z') alphabet[s[i] - 'a']++;
        else if(s[i] >= 'A' && s[i] <= 'Z') alphabet[s[i] - 'A']++;
        i++;
    }
    int k = 0;
    for(int j = 0; j < 26; j++){
        if(alphabet[j] == 0){
            m[k] = 'a' + j;
            k++;
        }
    }
    if(m[k] == -1){
        m[k] = '\0';
        return true;
    }
    m[k] = '\0';
    return false;
    
}

int main(){
    { char s[] = "";
    char m[27] = { -1 };
    bool r = pangram(s, m);
    cout << '\"' << s << "\" "
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"" false "abcdefghijklmnopqrstuvwxyz"
    { char s[] = "The quick brown fox jumps over the lazy dog";
    char m[27] = { -1 };
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"The quick brown fox jumps over the lazy dog" true ""
    { char s[] = "A quick brown fox jumps over a classy dog";
    char m[27] = { -1 };
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //"A quick brown fox jumps over a classy dog" false "htz"
    { char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char m[27] = { -1 };
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ " true ""
    { char s[] = " Stu yZ abC GhI MnO pQr   ";
    char m[27] = { -1 };
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
    << boolalpha << r << " \"" << m << "\"\n"; }
    //" Stu yZ abC GhI MnO pQr   " false "defjklvwx"
    return 0;
}
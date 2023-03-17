#include <iostream>

using namespace std;

int nrl(const char s[], char low[]){
    int alphabet[26] {0};
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            i++;
            continue;
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            alphabet[s[i] - 'a']++;
        } else{
            alphabet[s[i] - 'A']++;
        }
        i++;
    }
    int counter = 0;
    int j = 0;
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == 1){
            counter++;
            low[j] = 'a' + i;
            j++;
        }
    }
    low[j] = '\0';
    return counter;
}

int main(){
    { const char s[] = "";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }
    //"" 0 ""
    { const char s[] = "  F C U P  F E U P  Porto  ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }
    //"  F C U P  F E U P  Porto  " 4 "cert"
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ " 26 "abcdefghijklmnopqrstuvwxyz"
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz" 0 ""
    { const char s[] = "The quick brown fox jumps over the lazy dog";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }
    //"The quick brown fox jumps over the lazy dog" 20 "abcdfgijklmnpqsvwxyz"
    return 0;
}
#include <iostream>

using namespace std;

int nrl(const char s[], char low[]){
    int alphabet[27] {0};
    int i = 0;
    int res = 0;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            i++;
            continue;
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            alphabet[s[i] - 'a']++;
            i++;
        } else{
            alphabet[s[i] - 'A']++;
            i++;
        }
    }
    int j = 0;
    for(int x = 0; x < 27; x++){
        if(alphabet[x] == 1){
            low[j] = 'a' + x;
            j++;
            res++;
        }
    }
    if(res == 0) low[0] = '\0';
    return res;
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
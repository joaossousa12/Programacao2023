#include <iostream>

using namespace std;

bool heterogram(const char s[], char r[]){
    int alphabet[26] {0};
    // spaces should be ignored
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <= 'z') alphabet[s[i] - 'a']++;
        else alphabet[s[i] - 'A']++;
        i++;
    }
    int k = 0;
    for(int j = 0; j < 26; j++){
        if(alphabet[j] > 1){
            r[k] = 'a' + j;
            k++;
        }
    }
    if(r[0] == -1){
        r[k] = '\0';
        return true; 
    }
    r[k] = '\0';
    return false; 
}

int main(){
    char s[] = "Aha Zzz heterogram  ";
    char r[27] = { -1 };
    bool b = heterogram(s, r);
    cout << '\"' << s << "\" " << boolalpha << b << " \"" << r << "\"\n";
    return 0;
}
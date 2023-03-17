#include <iostream>

using namespace std;

bool heterogram(const char s[], char r[]){
    int alphabet[26] {0};
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <= 'z') alphabet[s[i] - 'a']++;
        else if(s[i] >= 'A' && s[i] <= 'Z') alphabet[s[i] - 'A']++;
        i++;
    }
    int k = 0;
    for(int j = 0; j < 26; j++){
        if(alphabet[j] > 1){
            r[k] = 'a' + j;
            k++;
        }
    }
    if(r[k] == -1){
        r[k] = '\0';
        return true;
    }
    r[k] = '\0';
    return false;
}

int main(){
    char s[] = "MOon";
    char r[27] = {-1};
    bool b = heterogram(s, r);
    cout << '\"' << s << "\" " << boolalpha << b << " \"" << r << "\"\n"; 
    return 0;
}
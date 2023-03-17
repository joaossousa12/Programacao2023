#include <iostream>

using namespace std;

void trim(char s[]){
    int length = 0;
    while(s[length] != '\0') length++;
    int i = 0;
    int j = 0;
    int flag = 1;
    while(s[i] == ' ') i++;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            flag = 1;
            for(int k = i; k < length; k++){
                if(s[k] != ' '){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
        s[j] = s[i];
        j++;
        i++;
    }
    s[j] = '\0';
}

int main(){
    { char s[] = " abc! def? ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //" abc! def? " => "abc! def?"
    { char s[] = "#abc";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"#abc" => "#abc"
    { char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"    abc def" => "abc def"
    { char s[] = "abc def.   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"abc def.   " => "abc def."
    { char s[] = "   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"   " => ""
    { char s[] = "";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"" => ""
    { char s[] = " abc  _  def  _  ghi ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //" abc  _  def  _  ghi " => "abc  _  def  _  ghi"
    { char s[] = "a           ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"a           " => "a"
    return 0;
}
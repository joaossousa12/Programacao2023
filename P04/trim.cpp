#include <iostream>

using namespace std;

int counter(char s[]){
    int result = 0;
    while(s[result] != '\0') result++;
    return result;
}

void trim(char s[]){
    if(s[0] == '\0') return;
    else{
        int i = 0;
        int j = counter(s) - 1;
        while(s[i] == ' ') i++;
        while(s[j] == ' ' && j >= i) j--;
        int k = 0;
        for(int n = i; n <= j; n++) s[k++] = s[n];
        s[k] = '\0';
    }
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
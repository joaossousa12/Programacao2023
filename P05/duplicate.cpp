#include <iostream>

using namespace std;

char* duplicate(const char s[]){
    int n = 1;
    int i = 0;
    while(s[i++] != '\0') n++;
    char* result = new char[n];
    i = 0;
    while(s[i] != '\0'){
        result[i] = s[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

int main(){
    { char* s = duplicate("");
    cout << "\"" << s << "\"\n";
    delete [] s; }
    //""
    { char* s = duplicate("a");
    cout << "\"" << s << "\"\n";
    delete [] s; }
    //"a"
    { char* s = duplicate("C++");
    cout << "\"" << s << "\"\n";
    delete [] s; }
    //"C++"
    { char* s = duplicate("0123 456 789 @ abc");
    cout << "\"" << s << "\"\n";
    delete [] s; }
    //"0123 456 789 @ abc"
    return 0;
}
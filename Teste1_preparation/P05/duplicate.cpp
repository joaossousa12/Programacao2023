#include <iostream>

using namespace std;

char* duplicate(const char s[]){
    int i = 0;
    while(s[i] != '\0') i++;
    char* result = new char[i + 1];
    for(int j = 0; j <= i; j++) result[j] = s[j];
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
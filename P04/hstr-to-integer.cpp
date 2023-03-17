#include <iostream>
#include <cmath>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long result = 0;
    int i = 0;
    while(hstr[i] != '\0'){
        unsigned long ac = 0;
        if(hstr[i] >= '0' && hstr[i] <= '9') ac += (hstr[i] - '0');
        else if(hstr[i] >= 'a' && hstr[i] <= 'f') ac += (hstr[i] - 'a' + 10);
        else ac += (hstr[i] - 'A' + 10);
        result = result * 16 + ac;
        i++;
    }
    return result;
}

int main(){
    cout << hstr_to_integer("0");
    //0
    cout << hstr_to_integer("A");
    //10
    cout << hstr_to_integer("19");
    //25
    cout << hstr_to_integer("fF");
    //255
    cout << hstr_to_integer("CafeBabe2022");
    //223195403526178
    return 0;
}
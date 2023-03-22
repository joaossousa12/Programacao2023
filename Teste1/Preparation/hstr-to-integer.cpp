#include <iostream>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long result = 0;
    int i = 0;
    while(hstr[i] != '\0'){
        unsigned long tmp;
        if(hstr[i] >= '0' && hstr[i] <= '9'){
            tmp = hstr[i] - '0';
        } else if(hstr[i] >= 'a' && hstr[i] <= 'z'){
            tmp = hstr[i] - 'a' + 10;
        } else{
            tmp = hstr[i] - 'A' + 10;
        }
        result = result * 16 + tmp;
        i++;
    }
    return result;
}

int main(){
    cout << hstr_to_integer("0") << endl;
    //0
    cout << hstr_to_integer("A") << endl;
    //10
    cout << hstr_to_integer("19") << endl;
    //25
    cout << hstr_to_integer("fF") << endl;
    //255
    cout << hstr_to_integer("CafeBabe2022") << endl;
    //223195403526178
    return 0;
}
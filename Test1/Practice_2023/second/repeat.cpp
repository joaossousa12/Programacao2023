#include <iostream>

using namespace std;

char* repeat(const char str[], int n){
    int length = 0;
    while(str[length] != '\0') length++;
    char* res = new char[length * n + 1];
    int i = 0; // number of repetitions
    int k = 0; // index for res
    while(i < n){
        int j = 0; // index for str
        while(str[j] != '\0'){
            res[k] = str[j];
            k++;
            j++;
        }
        i++;
    }
    res[k] = '\0';
    return res;
}

int main(){
    { const char str[] = "H e l l o";
    char* r = repeat(str, 2);
    cout << "\"" << r << "\"\n";
    delete [] r; }
    //"H e l l oH e l l o"
    { const char str[] = "C++";
    char* r = repeat(str, 1);
    cout << "\"" << r << "\"\n";
    delete [] r; }
    //"C++"
    { const char str[] = "";
    char* r = repeat(str, 99);
    cout << "\"" << r << "\"\n";
    delete [] r; }
    //""
    { const char str[] = "C/C++@LEIC.";
    char* r = repeat(str, 5);
    cout << "\"" << r << "\"\n";
    delete [] r; }
    //"C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC."
    { const char str[] = "x";
    char* r = repeat(str, 15);
    cout << "\"" << r << "\"\n";
    delete [] r; }
    //"xxxxxxxxxxxxxxx"
    return 0;
}
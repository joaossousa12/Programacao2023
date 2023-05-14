#include <iostream>

using namespace std;

const char* longest(const char* pa[]){
    int j = 0; // iterate throught the array of chars array
    int max_length = 0;
    int k = 0; // index of max char array
    while(pa[j] != nullptr){
        int tmp_length = 0; // temporary length 
        while(pa[j][tmp_length] != '\0') tmp_length++;
        if(tmp_length >= max_length){
            k = j;
            max_length = tmp_length;
        }
        j++;
    }
    return pa[k];
}

int main(){
    { const char* pa[] = { "C++", nullptr };
    cout << "\"" << longest(pa) << "\"\n"; }
    //"C++"
    { const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
    cout << "\"" << longest(pa) << "\"\n"; }
    //"world"
    { const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
    cout << "\"" << longest(pa) << "\"\n"; }
    //"Hello world"
    { const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
    cout << "\"" << longest(pa) << "\"\n"; }
    //"Hello world!"
    { const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
    cout << "\"" << longest(pa) << "\"\n"; }
    //"Typescript"
    return 0;
}
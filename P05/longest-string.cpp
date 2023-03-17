#include <iostream>

using namespace std;

const char* longest(const char* pa[]){
    int k = 0; 
    int res_i; // result index
    int max_chararray = 0;
    while(pa[k] != nullptr){
        int tmp = 0;
        int i = 0;
        while(pa[k][i++] != '\0') tmp++;
        if(tmp >= max_chararray){
            max_chararray = tmp;
            res_i = k;
        }
        k++;
    }
    return pa[res_i];
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
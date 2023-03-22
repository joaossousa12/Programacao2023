#include "print_array.h"
#include <iostream>

using namespace std;

int filter_duplicates(const int a[], int n, int b[]){
    int counter = 1;
    int i = 1;
    b[0] = a[0]; 
    for(int j = 1; j < n; j++){
        if(a[j] != b[i - 1]){
            b[i] = a[j];
            i++;
            counter++;
        }
    }
    return counter;
}

int main(){
    { const int n = 12;
    const int a[n] = { 1, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 3 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[1,2,3,1,2,3]
    { const int n = 1;
    const int a[n] = { 1 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[1]
    { const int n = 2;
    const int a[n] = { 999, 999 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[999]
    { const int n = 3;
    const int a[n] = { 3, 2, 1 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[3,2,1]
    { const int n = 7;
    const int a[n] = { -1, -1, -1, -1, 2, -3, -3 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[-1,2,-3]
    { const int n = 11;
    const int a[n] = { 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 33 };
    int b[n] = { 0 };
    int nf = filter_duplicates(a, n, b);
    print_array(b, nf); }
    //[1,0,1,0,33]
    return 0;
}
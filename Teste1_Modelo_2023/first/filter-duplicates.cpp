#include <iostream>
#include "print_array.h"

using namespace std;

int filter_duplicates(const int a[], int n, int b[]){
    int copied = 1;
    int duplicate = a[0];
    b[0] = a[0];
    int j = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == duplicate) continue;
        else{
            duplicate = a[i];
            b[j] = a[i];
            j++;
            copied++;
        }
    }
    return copied;
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
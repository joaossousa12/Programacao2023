#include "print_array.h"
#include <iostream>

using namespace std;

int* merge_arrays(const int a[], int na, const int b[], int nb){
    int* result = new int[na + nb];
    int i = 0, j = 0; // i -> na    j -> nb
    int c1 = 0; // index of result
    while(i != na && j != nb){
        if(a[i] > b[j]){
            result[c1] = b[j]; 
            j++;
        }
        else {
            result[c1] = a[i];
            i++;
        }
        c1++;
    }
    while(i != na){
        result[c1] = a[i];
        c1++;
        i++;
    }
    while(j != nb){
        result[c1] = b[j];
        c1++;
        j++;
    }
    return result;
}

int main(){
    { const int NA = 4, NB = 6;
    int a[NA] = { 1, 2, 4, 7};
    int b[NB] = { 0, 3, 5, 6, 8, 9};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c; }
    //[0,1,2,3,4,5,6,7,8,9]
    { const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c; }
    //[0,1,2,3,4,5,6,7,8,9]
    { const int NA = 2, NB = 3;
    int a[NA] = { 0, 1 };
    int b[NB] = { 2, 3, 4 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c; }
    //[0,1,2,3,4]
    { const int NA = 3, NB = 2;
    int a[NA] = { 2, 3, 4 };
    int b[NB] = { 0, 1 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c; }
    //[0,1,2,3,4]
    { const int NA = 15, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c; }
    //[0,0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9,9,9]
    return 0;
}
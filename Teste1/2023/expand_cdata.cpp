#include "cdata.h"

int* expand_cdata(const cdata a[], int n){
    int size = 0;
    for(int i = 0; i < n; i++){
        size += a[i].count;
    }
    int* res = new int[size];
    int k= 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].count; j++){
            res[k] = a[i].value;
            k++;
        }
    }
    return res;
}

int main(){
    { const int n = 1;
    const cdata a[] { { 3, 999 } };
    int* r = expand_cdata(a, n);
    print_array(r, 3);
    delete [] r; }

        

    //[999,999,999]

    { const int n = 3;
    const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
    int* r = expand_cdata(a, n);
    print_array(r, 6);
    delete [] r; } 

        

   // [100,100,100,200,200,300]

    { const int n = 1;
    const cdata a[] { { 1, 999 } };
    int* r = expand_cdata(a, n);
    print_array(r, 1);
    delete [] r; }

        

    //[999]

    { const int n = 2;
    const cdata a[] { { 20, 1 }, { 17, 2} };
    int* r = expand_cdata(a, n);
    print_array(r, 37);
    delete [] r; } 

        

   // [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

    { const int n = 4;
    const cdata a[] { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
    int* r = expand_cdata(a, n);
    print_array(r, 13);
    delete [] r; }

        

    //[5,5,2,0,0,0,-1,-1,-1,-1,-1,-1,-1]
    return 0;
}
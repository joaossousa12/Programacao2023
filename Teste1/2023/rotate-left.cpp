#include "print_array.h"

void rotate_left(int a[], int n, int k){
    int j = 0;
    while(j < k){
        for(int i = 0; i < n - 1; i++){
            int tmp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = tmp;
        }
        j++;
    }
}

int main(){
    { int a[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(a) / sizeof(int);
    rotate_left(a, size, 1);
    print_array(a, size); }

        

    //[2,3,4,5,1]

    { int a[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(a) / sizeof(int);
    rotate_left(a, size, 2);
    print_array(a, size); }

        

    //[3,4,5,1,2]

    { int a[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(a) / sizeof(int);
    rotate_left(a, size, -1);
    print_array(a, size); }

        

    //[1,2,3,4,5]

    { int a[] = { 10, 20, 30, 40 };
    int size = sizeof(a) / sizeof(int);
    rotate_left(a, size, 4);
    print_array(a, size); }

        

    //[10,20,30,40]

    { int a[] = { -3, -5, -7 };
    int size = sizeof(a) / sizeof(int);
    rotate_left(a, size, 5);
    print_array(a, size); }

        

    //[-7,-3,-5]

    return 0;
}
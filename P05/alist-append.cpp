#include "alist.h"
#include <iostream>

using namespace std;

void append(alist* a, const alist* b){
    if(b->size == 0){
        return;
    }
    if(a->size == 0){
        a->size = b->size;
        a->elements = new int[b->size];
        for(int i = 0; i < b->size; i++) a->elements[i] = b->elements[i];
        return;
    }
    int length_a = a->size;
    int* tmp = new int[a->size];
    for(int i = 0; i < a->size; i++) tmp[i] = a->elements[i];
    a->size = a->size + b->size;
    delete[] a->elements; // dava memory leak se n desse delete antes de alocar memória outra vez
    a->elements = new int[a->size];
    for(int i = 0; i < length_a; i++) a->elements[i] = tmp[i];
    int indice = length_a;
    while(length_a != a->size){
        a->elements[length_a] = b->elements[length_a - indice];
        length_a++;
    }
    delete [] tmp;
}

int main(){
    { alist* a = empty();
    const alist* b = empty();
    append(a, b);
    print(a);
    destroy(a);
    destroy(b); }
    //[ ]
    { alist* a = empty();
    const int nB = 2;
    int eB[nB] = { 1, 2 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b); }
    //[ 1 2 ]
    { const int nA = 2;
    int eA[nA] = { 1, 2 }; 
    alist* a = build(nA, eA);
    const alist* b = empty();
    append(a, b);
    print(a);
    destroy(a); 
    destroy(b); }
    //[ 1 2 ]
    { const int nA = 2;
    int eA[nA] = { 1, 2 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 3, 4, 5 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b); }
    //[ 1 2 3 4 5 ]
    { const int nA = 4;
    int eA[nA] = { 1, 2, 3, 4 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 5, 6, 7 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b); }
    //[ 1 2 3 4 5 6 7 ]
    return 0;
}
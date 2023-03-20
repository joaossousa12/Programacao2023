#include "smatrix.h"

void sum(const smatrix& a, const smatrix& b, smatrix& r){
    unsigned long int i = 0; // index of a
    unsigned long int j = 0; // index of b
    while(i < a.size() && j < b.size()){
        if(a[i].row < b[j].row){
            r.push_back(a[i]);
            i++;
        } else if(a[i].row > b[j].row){
            r.push_back(b[j]);
            j++;
        } else{
            if(a[i].col < b[j].col){
                r.push_back(a[i]);
                i++;
            } else if(a[i].col > b[j].col){
                r.push_back(b[j]);
                j++;
            } else{
                if(a[i].value + b[j].value != 0) r.push_back({a[i].row, a[i].col, a[i].value + b[j].value});
                i++;
                j++;
            }
        }
    }
    while(i < a.size()){
        r.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        r.push_back(b[j]);
        j++;
    }
}

int main(){
    { smatrix r;
    sum({ },
    { {0, 3, 1}, {0, 50, 1} },
    r);
    print(r); }
    //[ (0, 3, 1) (0, 50, 1) ]
    { smatrix r;
    sum({ {0, 0, 1}, {1, 0, 1} },
    { {0, 3, 1}, {0, 50, 1} },
    r);
    print(r); }
    //[ (0, 0, 1) (0, 3, 1) (0, 50, 1) (1, 0, 1) ]
    { smatrix r;
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
    { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
    r);
    print(r); }
    //[ (0, 0, 2) (5, 10, 20) (10, 5, 20) (99, 10, 30) (99, 11, 31) (99, 12, 32) ]
    { smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
    { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
    r);
    print(r); }
    //[ (5, 10, 20) ]
    { smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
    { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
    r);
    print(r); }
    //[ ]
    return 0;
}
#include "smatrix.h"


void sum(const smatrix& a, const smatrix& b, smatrix& r){
    r = a;
    for(auto c : b){
        int flag = 0;
        for(auto &d : r){
            if(c.col == d.col && c.row == d.row) {
                d.value += c.value;
                flag = 1;
            }
        }
        if(flag == 0) r.push_back(c);
    }
    size_t i = 0;
    while(i < r.size() - 1){
        if(r[i].row > r[i + 1].row || (r[i].row == r[i + 1].row && r[i].col > r[i + 1].col)){
            swap(r[i], r[i + 1]);
            i = 0;
            continue;
        }
        i++;
    }
    size_t j = 0;
    while(j < r.size()){
        if(r[j].value == 0){
            r.erase(r.begin() + j);
            j = 0;
            continue;
        }
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
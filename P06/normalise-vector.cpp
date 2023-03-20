#include "print_vector.h"
#include <string>

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    for(T& a : v){
        if(a < min) a = min;
        else if(a > max) a = max;
    }
}

int main(){
    { vector<int> v { }; normalise(v, 0, 1); print(v); }
    //[ ]
    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 1, 5); print(v); }
    //[ 1 2 3 4 5 ]
    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 3, 4); print(v); }
    //[ 3 3 3 4 4 ]
    { vector<double> v { -1.2, 2.2, -3.5, 4.3, 5.2 }; normalise(v, 0.5, 5.1); print(v); }
    //[ 0.5 2.2 0.5 4.3 5.1 ]
    { vector<string> v { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
    normalise(v, string("Antonio"), string("Zacarias")); print(v); }
    //[ Diego Antonio Antonio Bernardo Tolentino Zacarias Xavier ]
    return 0;
}
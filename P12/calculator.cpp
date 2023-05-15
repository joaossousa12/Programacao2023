#include "Operation.h"
#include <iostream>

using namespace std;

class Sum : public Operation{
    public:
        Sum(int op1, int op2) : Operation(op1,op2) {}
        int operation() const{
            return get_op1() + get_op2();
        }
};

class Power : public Operation{
    public:
        Power(int op1, int op2) : Operation(op1,op2) {}
        int operation() const{
            if(get_op2() == 0) return 1;
            int res = get_op1();
            for(int i = 1; i < get_op2(); i++){
                res *= get_op1();
            } 
            return res;
        }
};

int main(){
    { const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
    const Operation& p = Power(2, 10); cout << p.operation() << endl; }
    //12 1024
    { Sum s(6, -2); cout << s.operation() << ' '; 
    Power p(-3, 0); cout << p.operation() << endl; }
    //4 1
    { Sum s(-6, 2); cout << s.operation() << ' '; 
    Power p(-2, 5); cout << p.operation() << endl; }
    //-4 -32
    { Sum s(-6, -2); cout << s.operation() << ' '; 
    Power p(2, 7); cout << p.operation() << endl; }
    //-8 128
    return 0;
}
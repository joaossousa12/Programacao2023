#include "Account.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Regular : public Account{
    private:
        float balance_;
    public:
        Regular(int number) : balance_(0), Account(number) {}
        void increase_balance(float amount){
            balance_ += amount;
        }
        float get_balance() const{
            return balance_;
        }
};

class Deposits : public Account{
    private:
        vector<float> deposits_;
    public:
        Deposits(int number) : Account(number) {}
        void add_deposit(float amount){
            deposits_.push_back(amount);
        }
        float get_deposit(int deposit_number) const{
            return deposits_[deposit_number -1];
        }
        float get_balance() const{
            float result = 0;
            for(auto d : deposits_) result +=d;
            return result;
        }
};

int main(){
    Regular a1(10001); const Account& r = a1;
    float v = r.get_balance();
    a1.increase_balance(34.50);
    cout << fixed << setprecision(2)
         << r.get_number() << ' ' << v << ' ' << r.get_balance() << endl;
    return 0;
}


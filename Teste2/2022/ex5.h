#include <iostream>
#include <vector>
#include <iomanip>
#include "Account.h"

using namespace std;

class Regular : public Account { // means that regular is inheriting from the account class
    public:
        Regular(int number){
            Account(number);
            regular_balance_ = 0;
        }
        void increase_balance(float amount){
            regular_balance_ += amount;
        }
        float get_balance() const override {
            return regular_balance_;
        }
    private:
        float regular_balance_;
};

class Deposits : public Account {
    public:
        Deposits(int number){
            Account(number);
        }
        void add_deposit(float amount){
            balances_.push_back(amount);
        }
        float get_deposit(int deposit_number) const{
            return balances_[deposit_number - 1];
        }
        float get_balance() const override{
            float lol = 0;
            for(const auto bal : balances_){
                lol += bal;
            }
            return lol;
        }
    private:
        vector<float> balances_;
};
#ifndef INC_2022_ACCOUNT_H
#define INC_2022_ACCOUNT_H

class Account{
    public:
        Account(int number) : number_(number) { }
        int get_number() const { return number_; }
        virtual float get_balance() const = 0;
    protected:
        int number_; // account number
};

#endif
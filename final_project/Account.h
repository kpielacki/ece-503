#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>


class Account {

    public:
        Account();
        ~Account();
        double get_balance();
        void set_balance(double);
        void add_balance(double);
        void sub_balance(double);

    private:
        double balance;

};

#endif

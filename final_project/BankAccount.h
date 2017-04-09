#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_


#include <string>
#include "BankAccount.h"

class BankAccount : public Account {

    public:
        BankAccount();
        ~BankAccount();
        void view_balance(double);
        void deposit(double);
        void withdraw(double);
        void print_history();

};


#endif

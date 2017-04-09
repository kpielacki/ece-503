#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_


#include <string>
#include "BankAccount.h"

class BankAccount : public Account {

    public:
        BankAccount();
        BankAccount(std::string);
        ~BankAccount();

        void view_account_balance();
        void deposit(double);
        void withdraw(double);
};


#endif

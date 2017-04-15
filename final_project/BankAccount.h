#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_


#include <string>
#include "Account.h"

class BankAccount : public Account {

    public:
        BankAccount();
        BankAccount(std::string);
        ~BankAccount();

        void view_account_balance();
        void deposit(double);
        void withdraw(double);

        void print_transaction_history();

    private:
        std::string transaction_history_filename;

};


#endif

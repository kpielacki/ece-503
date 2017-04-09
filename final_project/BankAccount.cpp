#include <iostream>
#include <string>
#include "Account.h"
#include "BankAccount.h"


BankAccount::BankAccount() : Account() {

}


BankAccount::~BankAccount() {

}


void BankAccount::withdraw(double amount) {
    if (amount > 0) {
        BankAccount::sub_balance(amount);
    } else {
        std::cout << "Withdrawal amount must be postive, cancelling transaction" << std::endl;
    }


}


void BankAccount::deposit(double amount) {
    if (amount > 0) {
        BankAccount::add_balance(amount);
    } else {
        std::cout << "Withdrawal amount must be postive, cancelling transaction" << std::endl;
    }


}

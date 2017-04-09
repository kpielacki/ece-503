#include <iostream>
#include <string>
#include "Account.h"
#include "BankAccount.h"


BankAccount::BankAccount() : Account() {

}


BankAccount::BankAccount(std::string username_in) : Account(username_in) {

}


BankAccount::~BankAccount() {

}


void BankAccount::withdraw(double amount) {
    if (amount > 0) {
        BankAccount::set_cash_balance(get_cash_balance() - amount);
    } else {
        std::cout << "Withdrawal amount must be postive, cancelling transaction" << std::endl;
    }
}


void BankAccount::deposit(double amount) {
    if (amount > 0) {
        BankAccount::set_cash_balance(get_cash_balance() + amount);
    } else {
        std::cout << "Deposit amount must be postive, cancelling transaction" << std::endl;
    }
}


void BankAccount::view_account_balance() {
    std::cout << "You have $" << get_cash_balance() << " in your account." << std::endl;
}

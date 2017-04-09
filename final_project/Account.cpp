#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"


Account::Account() {
    username = "Default";
    // Set initial balance to 10000.
    balance = 10000;

    std::ofstream user_balance_record;
    user_balance_record.open ("example.txt");
}


Account::Account(std::string username_in) {
    username = username_in;
    // Set initial balance to 10000.
    balance = 10000;
}



Account::~Account() {

}


double Account::get_balance() {
    return balance;
}


void Account::set_balance(double balance_in) {
    balance = balance_in;
}


void Account::add_balance(double balance_in) {
    balance = balance + balance_in;
}


void Account::sub_balance(double balance_in) {
    balance = balance - balance_in;
}

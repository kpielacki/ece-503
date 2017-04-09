#include <iostream>
#include <string>
#include "Account.h"


Account::Account() {
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

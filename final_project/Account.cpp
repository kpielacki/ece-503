#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"


Account::Account() {
    // Set username to "Default" if none is provided.
    // I use this to prefix all .txt files that hold
    // account information.
    username = "Default";
    cash_balance_filename = username + "_cash_balance.txt";

    // Initialize user account if first time user.
    if (!is_active()) {
       init_account();
    }
}


Account::Account(std::string username_in) {
    // Use passed username to prefix all .txt files
    // that hold user account information.
    username = username_in;
    cash_balance_filename = username + "_cash_balance.txt";

    // Initialize user account if first time user.
    if (!is_active()) {
       init_account();
    }
}


Account::~Account() {

}


// Checks if a cash balance file can be found for the user.
bool Account::is_active() {
    bool account_active;

    std::ifstream cash_balance_file;
    cash_balance_file.open(cash_balance_filename.c_str());

    // Returns true if cash_balance_file can be found.
    account_active = cash_balance_file.good();

    cash_balance_file.close();

    return account_active;
}


// Creates a user account with an intial cash balance of $10,000.
void Account::init_account() {
    std::ofstream cash_balance_file;
    cash_balance_file.open(cash_balance_filename.c_str());
    cash_balance_file << 10000;
    cash_balance_file.close();
}


// Returns the number stored in <username>_cash_balance.
double Account::get_cash_balance() {
    double cash_balance;
    std::ifstream cash_balance_file;
    cash_balance_file.open(cash_balance_filename.c_str());
    cash_balance_file >> cash_balance;
    cash_balance_file.close();

    return cash_balance;
}


void Account::set_cash_balance(double balance_in) {
  std::ofstream cash_balance_file;                       
  cash_balance_file.open(cash_balance_filename.c_str());
  cash_balance_file << balance_in;
  cash_balance_file.close();
}


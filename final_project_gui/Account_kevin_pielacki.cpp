#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Account_kevin_pielacki.h"


Account::Account() {
    // Set username to "Default" if none is provided.
    // I use this to prefix all .txt files that hold
    // account information.
    username = "Default";
    cash_balance_filename = username + "_cash_balance.txt";

    // Sets scaling factor for decimal precision.
    scale = 0.01;
    // Sets acceptable difference when comparing two double values.
    min_diff = 0.000000001;

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

    // Sets scaling factor for decimal precision of 2.
    scale = 0.01;
    // Sets acceptable difference when comparing two double values.
    min_diff = 0.000000001;

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
    cash_balance_file << std::fixed << std::setprecision(2) << 10000;
    cash_balance_file.close();
}


// Getter for username.
std::string Account::get_username() {
    return username;
}


// Getter for scale decimal place management.
double Account::get_scale() {
    return scale;
}

// Getter for min_diff for acceptable difference between double comparison.
double Account::get_min_diff() {
    return min_diff;
}


// Returns true if the entered value is within the scale constraint of decimal
// places.
// Default checks for two decimal place entries.
bool Account::check_scale(double value) {
    double value_check;
    double diff_check;

    value_check = std::floor(value / get_scale() + 0.5) * get_scale();
    diff_check = value_check - value;

    // Checks if decimal difference is acceptable.
    // Comparing two double values with == operator can prove to be unreliable.
    if ((diff_check < get_min_diff()) && (-diff_check < get_min_diff())) {
        return true;
    } else {
        return false;
    }
}


// Returns the number stored in <username>_cash_balance.
double Account::get_cash_balance() {
    std::string line;
    double cash_balance;

    std::ifstream cash_balance_file;
    cash_balance_file.open(cash_balance_filename.c_str());

    getline(cash_balance_file, line);
    std::istringstream ss(line);
    ss >> cash_balance;

    cash_balance_file.close();
    return cash_balance;
}


void Account::set_cash_balance(double balance_in) {
  std::ofstream cash_balance_file;
  cash_balance_file.open(cash_balance_filename.c_str());
  cash_balance_file << std::fixed << std::setprecision(2) << balance_in;
  cash_balance_file.close();
}

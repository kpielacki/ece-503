#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Account.h"
#include "BankAccount.h"


BankAccount::BankAccount() : Account() {
    transaction_history_filename = get_username() + "_bank_transaction_history.txt";
}


BankAccount::BankAccount(std::string username_in) : Account(username_in) {
    transaction_history_filename = get_username() + "_bank_transaction_history.txt";
}


BankAccount::~BankAccount() {

}


// Deducts input amount from check balance if postive value and greater than current cash balance.
// Stores transaction in <username>_bank_transaction_history.txt.
void BankAccount::withdraw(double amount) {
    if (amount > 0) {
        double new_balance = get_cash_balance() - amount;

        // Do not allow withdrawal larger than current balance.
        if (new_balance < 0) {
            std::cout << "You cannot afford this transaction, cancelling." << std::endl;
        } else {
            // Open file to append new transcation.
            std::ofstream transaction_history_file;
            transaction_history_file.open(transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
            transaction_history_file << "Withdrawal " << amount << " DATE " << new_balance << "\n";

            // Adjust cash balance to reflect transaction.
            BankAccount::set_cash_balance(new_balance);
        }
    } else {
        std::cout << "Withdrawal amount must be postive, cancelling transaction" << std::endl;
    }
}


// Adds input amount from check balance if postive value.
// Stores transaction in <username>_bank_transaction_history.txt.
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        double new_balance = get_cash_balance() + amount;

        // Open file to append new transcation.
        std::ofstream transaction_history_file;
        transaction_history_file.open(transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
        transaction_history_file << "Deposit " << amount << " DATE " << new_balance << "\n";

        // Adjust cash balance to reflect transaction.
        BankAccount::set_cash_balance(new_balance);
    } else {
        std::cout << "Deposit amount must be postive, cancelling transaction" << std::endl;
    }
}


// Prints current cash balance.
void BankAccount::view_account_balance() {
    std::cout << "You have $" << get_cash_balance() << " in your account." << std::endl;
}


// Prints all user transactions.
void BankAccount::print_transaction_history() {
    // Print transaction history headers.
    std::string line, event, date;
    double amount, balance;

    // Open transaction hisotry file.
    std::ifstream transaction_history_file;
    transaction_history_file.open(transaction_history_filename.c_str());

    // Header and transaction history print.
    printf("%-12s%-16s%-12s%-16s\n", "Event", "Amount", "Date", "Balance");
    while (getline(transaction_history_file, line)) {
	std::istringstream ss(line);
	ss >> event >> amount >> date >> balance;
        printf("%-12s$%-15.2f%-12s$%-15.2f\n", event.c_str(), amount, date.c_str(), balance);
    }
    transaction_history_file.close();
}

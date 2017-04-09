#include <iostream>
#include <fstream>
#include <string>
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
            transaction_history_file << "Withdrawal\t$" << amount << "\tDATE\t" << new_balance << "\n";

            // Adjust cash balance to reflect transaction.
            BankAccount::set_cash_balance(new_balance);
        }
    } else {
        std::cout << "Withdrawal amount must be postive, cancelling transaction" << std::endl;
    }
}


void BankAccount::deposit(double amount) {
    if (amount > 0) {
        double new_balance = get_cash_balance() + amount;

        // Open file to append new transcation.
        std::ofstream transaction_history_file;
        transaction_history_file.open(transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
        transaction_history_file << "Deposit\t$" << amount << "\tDATE\t" << new_balance << "\n";

        // Adjust cash balance to reflect transaction.
        BankAccount::set_cash_balance(new_balance);
    } else {
        std::cout << "Deposit amount must be postive, cancelling transaction" << std::endl;
    }
}


void BankAccount::view_account_balance() {
    std::cout << "You have $" << get_cash_balance() << " in your account." << std::endl;
}


void BankAccount::print_transaction_history() {
    // Print transaction history headers.
    std::string line;
    std::ifstream transaction_history_file;
    transaction_history_file.open(transaction_history_filename.c_str());

    // Header and transaction history print.
    std::cout << "Event\tAmount\tDate\tBalance" << std::endl;
    while (std::getline(transaction_history_file, line)) {
        std::cout << line << std::endl;
    }
    transaction_history_file.close();
}

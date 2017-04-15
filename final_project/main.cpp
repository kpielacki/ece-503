#include <iostream>
#include <string>
#include "Account.h"
#include "PortfolioAccount.h"
#include "BankAccount.h"


void portfolio_account_menu(std::string username) {
    int menu_selection;
    bool in_menu = true;
    std::string stock_symbol;
    double amount;
    PortfolioAccount portfolio(username);

    while (in_menu) {
        std::cout << std::endl << "Please select an option:" << std::endl;
        std::cout << "1. Display the price for a stock symbol" << std::endl;
        std::cout << "2. Display the current portfolio" << std::endl;
        std::cout << "3. Buy shares" << std::endl;
        std::cout << "4. Sell shares" << std::endl;
        std::cout << "5. View a graph for the portfolio value" << std::endl;
        std::cout << "6. View transaction history" << std::endl;
        std::cout << "7. Return to previous menu" << std::endl << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_selection;

        switch (menu_selection) {
            case 1: {
               std::cout << "Enter the stock symbol (use \"*\" to print all): ";
               std::cin >> stock_symbol;
               portfolio.display_stock_value(stock_symbol);
               break;
            } case 2: {
                std::cout << 2 << std::endl;
                break;
            } case 3: {
                std::cout << 3 << std::endl;
                break;
            } case 4: {
                std::cout << 4 << std::endl;
                break;
            } case 5: {
                std::cout << 5 << std::endl;
                break;
            } case 6: {
                portfolio.print_transaction_history();
                break;
            } case 7: {
                std::cout << "Exiting portfolio menu." << std::endl;
                in_menu = false;
                break;
            } default: {
                std::cout << "Invalid menu option." << std::endl;
            }
        }
    }
}


void checking_account_menu(std::string username) {
    int menu_selection;
    bool in_menu = true;
    double amount;
    BankAccount checking(username);

    while (in_menu) {
        std::cout << std::endl << "Please select an option:" << std::endl;
        std::cout << "1. View account balance" << std::endl;
        std::cout << "2. Deposit money" << std::endl;
        std::cout << "3. Withdraw money" << std::endl;
        std::cout << "4. Print out history" << std::endl;
        std::cout << "5. Return to previous menu" << std::endl << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_selection;

        switch (menu_selection) {
            case 1: {
               checking.view_account_balance();
               break;
            } case 2: {
                std::cout << "Please select the amount you wish to deposit: $";
                std::cin >> amount;
                checking.deposit(amount);
                break;
            } case 3: {
                std::cout << "Please select the amount you with to withdraw: $";
                std::cin >> amount;
                checking.withdraw(amount);
                break;
            } case 4: {
                checking.print_transaction_history();
                break;
            } case 5: {
                std::cout << "Exiting checking menu." << std::endl;
                in_menu = false;
                break;
            } default: {
                std::cout << "Invalid menu option." << std::endl;
            }
        }
    }
}


void account_selection_menu(std::string username) {
    int menu_selection;
    bool in_menu = true;

    while (in_menu) {
        std::cout << std::endl << "Welcome " << username << ", please select an account to access:" << std::endl;
        std::cout << "1. Stock Portfolio Account" << std::endl;
        std::cout << "2. Bank Account" << std::endl;
        std::cout << "3. Exit" << std::endl << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_selection;

        switch (menu_selection) {
            case 1: {
                portfolio_account_menu(username);
                break;
            } case 2: {
                checking_account_menu(username);
                break;
            } case 3: {
                std::cout << "Exiting" << std::endl;
                in_menu = false;
                break;
            } default: {
                std::cout << "Invalid menu option." << std::endl;
            }
        }
    }
}


int main() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;
    account_selection_menu(username);
    return 0;
}

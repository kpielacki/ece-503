#include <iostream>
#include <string>
#include "Account.h"
#include "PortfolioAccount.h"
#include "BankAccount.h"


void portfolio_account_menu(std::string username) {
    int menu_selection;
    bool in_menu = true;
    std::string stock_symbol;
    int share_purchase_count;
    int sorting_selection;
    double amount;
    PortfolioAccount portfolio(username);

    while (in_menu) {
        std::cout << std::endl << "Please select an option:" << std::endl;
        std::cout << "1. Display the price for a stock symbol" << std::endl;
        std::cout << "2. Display the current portfolio (descending)" << std::endl;
        std::cout << "3. Display the current portfolio (ascending)" << std::endl;
        std::cout << "4. Buy shares" << std::endl;
        std::cout << "5. Sell shares" << std::endl;
        std::cout << "6. View a graph for the portfolio value" << std::endl;
        std::cout << "7. View transaction history" << std::endl;
        std::cout << "8. Select sorting method" << std::endl;
        std::cout << "9. Return to previous menu" << std::endl << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_selection;

        switch (menu_selection) {
            case 1: {
               std::cout << "Enter the stock symbol (use \"*\" to print all): ";
               std::cin >> stock_symbol;
               portfolio.display_stock_value(stock_symbol);
               break;
            } case 2: {
                portfolio.print_portfolio_desc();
                break;
            } case 3: {
                portfolio.print_portfolio_asc();
                break;
            } case 4: {
                std::cout << "Enter the stock symbol you wish to purchase: ";
                std::cin >> stock_symbol;
                std::cout << "Enter the number of shares you wish to purchase: ";
                std::cin >> share_purchase_count;
                std::cout << "Enter the max price per share you wish to pay: $";
                std::cin >> amount;
                portfolio.buy_shares(stock_symbol, share_purchase_count, amount);
                break;
            } case 5: {
                std::cout << "Enter the stock symbol you wish to sell: ";
                std::cin >> stock_symbol;
                std::cout << "Enter the number of shares you wish to sell: ";
                std::cin >> share_purchase_count;
                std::cout << "Enter the minimum price per share you wish to sell for: $";
                std::cin >> amount;
                portfolio.sell_shares(stock_symbol, share_purchase_count, amount);
                break;
            } case 6: {
                portfolio.plot_portfolio_trend();
                break;
            } case 7: {
                portfolio.print_transaction_history();
                break;
            } case 8: {
                std::cout << "Current sorting method set to \"" << portfolio.get_sort_method() << "\"" << std::endl;
                std::cout << "Sort Options:" << std::endl;
                std::cout << "1. Selection" << std::endl;
                std::cout << "2. Bubble" << std::endl << std::endl;
                std::cout << "Option: ";
                std::cin >> sorting_selection;
                switch (sorting_selection) {
                    case 1: {
                        portfolio.set_sort_method(sorting_selection);
                        break;
                    } case 2: {
                        portfolio.set_sort_method(sorting_selection);
                        break;
                    } default: {
                        std::cout << "Invalid sorting method selection, canceling." << std::endl;
                    }
                }
                std::cout << "Sort method currently set to \"" << portfolio.get_sort_method() << "\"" << std::endl;
                break;
            } case 9: {
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

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Account.h"
#include "PortfolioAccount.h"
#include "date_str.h"


PortfolioAccount::PortfolioAccount() : Account() {
    srand(time(NULL));
    result_min = 1;
    result_max = 2;
    transaction_history_filename = get_username() + "_bank_transaction_history.txt";
    portfolio_info_filename = get_username() + "_portfolio_info.txt";

    load_portfolio();
}


PortfolioAccount::PortfolioAccount(std::string username_in) : Account(username_in) {
    srand(time(NULL));
    result_min = 1;
    result_max = 2;
    transaction_history_filename = get_username() + "_bank_transaction_history.txt";
    portfolio_info_filename = get_username() + "_portfolio_info.txt";

    load_portfolio();
}


PortfolioAccount::~PortfolioAccount() {
    std::ofstream portfolio_info_file;
    portfolio_info_file.open(portfolio_info_filename.c_str());

    // Store portfolio information in text file when finished.
    PortfolioNode *current_node = node_list_head;
    while (current_node) {
        portfolio_info_file << current_node->stock_symbol << " " << current_node->share_count << "\n";
        current_node = current_node->next;
    }
    portfolio_info_file.close();
}


// Loads information in <username>_portfolio_info.txt to doubly linked list.
void PortfolioAccount::load_portfolio() {
    std::string line, stock_symbol;
    unsigned int share_count;

    // Open transaction history file.
    std::ifstream portfolio_info_file;
    portfolio_info_file.open(portfolio_info_filename.c_str());

    bool first_node = true;
    PortfolioNode* prev_node = NULL;
    while (getline(portfolio_info_file, line)) {
        std::istringstream ss(line);
        ss >> stock_symbol >> share_count;

        PortfolioNode* new_node = new PortfolioNode(stock_symbol, share_count);

        if (first_node) {
            node_list_head = new_node;
            first_node = false;
        } else {
            prev_node->next = new_node;
        }
        new_node->prev = prev_node;
        new_node->next = NULL;

        prev_node = new_node;
        node_list_tail = new_node;
    }

    // If no information in portfolio account set head and tail to NULL.
    if (first_node) {
        node_list_head = NULL;
        node_list_tail = NULL;
    }
}


// Saves current portfolio doubly linked list to txt file.
void PortfolioAccount::save_portfolio() {
    std::ofstream portfolio_info_file;
    portfolio_info_file.open(portfolio_info_filename.c_str());

    // Store portfolio information in text file when finished.
    PortfolioNode *current_node = node_list_head;
    while (current_node) {
        portfolio_info_file << current_node->stock_symbol << " " << current_node->share_count << "\n";
        current_node = current_node->next;
    }
    portfolio_info_file.close();
}


void PortfolioAccount::add_shares(std::string stock_symbol, int share_count) {
    if (share_count > 0) {
        PortfolioNode *prev_node = node_list_head;
        PortfolioNode *current_node = node_list_head;

        // Prints all user portfollio information
        if (current_node) {
            bool create_new_node = true;
            while (current_node) {
                if (current_node->stock_symbol == stock_symbol) {
                  current_node->share_count = current_node->share_count + share_count;
                  create_new_node = false;
                  break;
                }
                prev_node = current_node;
                current_node = current_node->next;
            }

            if (create_new_node) {
                PortfolioNode* new_node = new PortfolioNode(stock_symbol, share_count);
                prev_node->next = new_node;
                new_node->prev = prev_node;
                new_node->next = NULL;
                node_list_tail = new_node;
            }
        } else {
            PortfolioNode* new_node = new PortfolioNode(stock_symbol, share_count);
            new_node->prev = NULL;
            new_node->next = NULL;
            node_list_head = new_node;
            node_list_tail = new_node;
        }
    }
    save_portfolio();
}


void PortfolioAccount::print_portfolio() {
    PortfolioNode *current_node = node_list_head;

    // Prints all user portfollio information
    if (current_node) {
        double current_total_value;
        printf("%-14s%-14s%-14s\n", "Stock Symbol", "Share Count", "Total Value");
        while (current_node) {
            current_total_value = get_stock_value(current_node->stock_symbol) * current_node->share_count;
            printf("%-14s%-14d$%-13.2f\n", current_node->stock_symbol.c_str(), current_node->share_count, current_total_value);
            current_node = current_node->next;
        }
    } else {
        std::cout << "No portfolio information found." << std::endl;
    }
}


// Returns the current value of the selected stock symbol. If invalid stock
// symbol return -1.
double PortfolioAccount::get_stock_value(std::string stock_symbol_in) {
    std::stringstream rand_val;
    std::string line;
    std::string stock_symbol;
    double stock_price;

    rand_val << rand() % result_max + result_min;
    std::string stock_result_filename = "Results " + rand_val.str() + ".txt";

    // Open stock result.
    std::ifstream stock_result_file;
    stock_result_file.open(stock_result_filename.c_str());

    // Header and stock price print.
    bool found = false;
    while (getline(stock_result_file, line)) {
        std::istringstream ss(line);
        ss >> stock_symbol >> stock_price;

        if (stock_symbol == stock_symbol_in) {
            found = true;
            break;
        }
    }

    if (!found) {
        return -1;
    } else {
        return stock_price;
    }
}


// Displays the stock pricing information of the passed stock symbold. If "*"
// is entered all stock information is displayed.
void PortfolioAccount::display_stock_value(std::string stock_symbol_in) {
    std::stringstream rand_val;
    std::string line;
    std::string stock_symbol;
    double stock_price;
    bool print_all = false;

    rand_val << rand() % result_max + result_min;
    std::string stock_result_filename = "Results " + rand_val.str() + ".txt";

    // Open stock result.
    std::ifstream stock_result_file;
    stock_result_file.open(stock_result_filename.c_str());

    // Checks for print all argument.
    if (stock_symbol_in == "*") {
        print_all = true;
    }

    // Header and stock price print.
    bool found = false;
    while (getline(stock_result_file, line)) {
        std::istringstream ss(line);
        ss >> stock_symbol >> stock_price;

        if (print_all) {
            printf("%-8s$%-10.2f\n", stock_symbol.c_str(), stock_price);
            found = true;
        } else {
            if (stock_symbol == stock_symbol_in) {
                printf("%-8s$%-10.2f\n", stock_symbol.c_str(), stock_price);
                found = true;
                break;
            }
        }
    }

    // Tell user when cannot find entered stock symbol.
    if (!found) {
        std::cout << "Unable to find entered stock symbol." << std::endl;
    }
}


// Deducts input amount from check balance if postive value and greater than current cash balance.
// Stores transaction in <username>_bank_transaction_history.txt.
void PortfolioAccount::buy_shares(std::string stock_symbol, int share_purchase_count, double max_price_per_share) {
    // Validators set to false to cancel invalid transaction. 
    bool valid_transaction = true;

    // Check if entered price per share offer is two digit number.
    if (!check_scale(max_price_per_share)) {
        std::cout << "Entered price per share cannot be more precise than two digits" << std::endl;
        valid_transaction = false;
    }

    // Do not allow user to offer non-postive price per share.
    if (max_price_per_share <= 0) {
        std::cout << "Purchase price per share must be postive." << std::endl;
        valid_transaction = false;
    }

    // Get the current price of the share.
    double current_share_price = get_stock_value(stock_symbol);

    // Check for valid stock symbol.
    // The get_stock_value method returns -1 for invalid stock symbols.
    if (current_share_price <= 0) {
        std::cout << "Invalid stock symbol " << stock_symbol << "." << std::endl;
        valid_transaction = false;
    }

    // Check if user acceptable offer is large enough to purchase stock.
    if (current_share_price > max_price_per_share) {
        printf("Current %s stock price of $%.2f is larger than your max offer of $%.2f.\n", stock_symbol.c_str(), current_share_price, max_price_per_share);
        valid_transaction = false;
    }

    // Gets new cash balance that appears once transaction has been completed.
    double purchase_price = share_purchase_count * current_share_price;
    double new_balance = get_cash_balance() - purchase_price;

    // Do not allow purchase larger than current balance.
    if (new_balance < 0) {
        std::cout << "You cannot afford this transaction." << std::endl;
        valid_transaction = false;
    }

    // If valid transaction prompt user to confirm.
    if (valid_transaction) {
        std::string user_confirmation;
        printf("You wish to buy %d %s shares at $%.2f per share totaling $%.2f, enter \"yes\" to continue: ", share_purchase_count, stock_symbol.c_str(), current_share_price, purchase_price);
        std::cin >> user_confirmation;

        // Deduct the cost from current cash balance and add new stock purchase to doubly linked list.
        if (user_confirmation == "yes") {
            // Open file to append new transcation.
            std::ofstream transaction_history_file;
            transaction_history_file.open(transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
            transaction_history_file << "Purchase " << purchase_price << " " << today_str() << " " << new_balance << "\n";

            // Adjust cash balance to reflect transaction.
            add_shares(stock_symbol, share_purchase_count);
            PortfolioAccount::set_cash_balance(new_balance);
            std::cout << "Transaction Complete" << std::endl;
        } else {
            std::cout << "Transaction Cancelled" << std::endl;
        }
    } else {
        std::cout << "Transaction Cancelled" << std::endl;
    }
}

// Prints all user transactions.
void PortfolioAccount::print_transaction_history() {
    // Print transaction history headers.
    std::string line, event, date;
    double amount, balance;

    // Open transaction history file.
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

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Account.h"
#include "PortfolioAccount.h"
#include "date_str.h"
#include "time_str.h"

// Matlab engine for plotting.
#include "engine.h"


PortfolioAccount::PortfolioAccount() : Account() {
    srand(time(NULL));
    result_min = 1;
    result_max = 2;
    bank_transaction_history_filename = get_username() + "_bank_transaction_history.txt";
    portfolio_transaction_history_filename = get_username() + "_portfolio_transaction_history.txt";
    portfolio_info_filename = get_username() + "_portfolio_info.txt";
    portfolio_value_history_filename = get_username() + "_portfolio_value_history.txt";

    // Set default sort option to bubble.
    set_sort_method(2);
    portfolio_node_count = 0;
    load_portfolio();
}


PortfolioAccount::PortfolioAccount(std::string username_in) : Account(username_in) {
    srand(time(NULL));
    result_min = 1;
    result_max = 2;
    bank_transaction_history_filename = get_username() + "_bank_transaction_history.txt";
    portfolio_transaction_history_filename = get_username() + "_portfolio_transaction_history.txt";
    portfolio_info_filename = get_username() + "_portfolio_info.txt";
    portfolio_value_history_filename = get_username() + "_portfolio_value_history.txt";

    // Set default sort option to bubble.
    set_sort_method(2);
    portfolio_node_count = 0;
    load_portfolio();
}


// Destructor to save current portfolio in text file and delete all nodes in doubly linked list.
PortfolioAccount::~PortfolioAccount() {
    double * _ = sort_portfolio();
    delete [] _;

    std::ofstream portfolio_info_file;
    portfolio_info_file.open(portfolio_info_filename.c_str());

    // Store portfolio information in text file when finished.
    PortfolioNode *current_node = node_list_head;
    PortfolioNode *temp_node;
    double total_portfolio_value = 0;
    while (current_node) {
        portfolio_info_file << current_node->stock_symbol << " " << current_node->share_count << "\n";
        total_portfolio_value +=  current_node->share_count * get_stock_value(current_node->stock_symbol);
        temp_node = current_node->next;
        delete current_node;
        current_node = temp_node;
    }
    portfolio_info_file.close();

    // Log portfolio value on close.
    std::string current_time = now_str();
    std::ofstream portfolio_value_history_file;
    portfolio_value_history_file.open(portfolio_value_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    portfolio_value_history_file << current_time.c_str() << " " << std::fixed << std::setprecision(2) << total_portfolio_value << " " << std::fixed << std::setprecision(2) << get_cash_balance() << "\n";
    portfolio_value_history_file.close();
}


// Gets the sorting method used.
std::string PortfolioAccount::get_sort_method() {
    switch (sort_method) {
        case 1: {
            return "Selection";
            break;
        } case 2: {
            return "Bubble";
            break;
        } default: {
            return "Invalid Sort Option";
        }
    }
}


// Sets the sorting method used.
//  1. Selection
//  2. Bubble
void PortfolioAccount::set_sort_method(int sort_method_in) {
    if (sort_method_in == 1 || sort_method_in == 2) {
        sort_method = sort_method_in;
    } else {
        std::cout << "Invalid sort method, current sort method " << get_sort_method() << " remains." << std::endl;
    }
}


// Loads information in <username>_portfolio_info.txt to doubly linked list.
void PortfolioAccount::load_portfolio() {
    portfolio_node_count = 0;

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
        portfolio_node_count++;
    }

    // If no information in portfolio account set head and tail to NULL.
    if (first_node) {
        node_list_head = NULL;
        node_list_tail = NULL;
    }

    double * _ = sort_portfolio();
    delete [] _;
}


// Calls on appropriate sort algorithm based on current value of sort_method.
//  1. Selection
//  2. Bubble
double * PortfolioAccount::sort_portfolio() {
    // Call on appropriate sorting algorithm or return list of unsorted values if bad sorting selection found.
    double * current_values_p;
    switch (sort_method) {
        case 1: {
            current_values_p = sort_portfolio_selection();
            break;
        } case 2: {
            current_values_p = sort_portfolio_bubble();
            break;
        } default: {
            std::cout << "WARNING: Invalid sorting method selection found. Current portfolio remains unsorted." << std::endl;
            PortfolioNode *current_node = node_list_head;
            for (int i = 0; i < portfolio_node_count; i++) {
                // Get all the current portfolio value in an array to keep values consistent while sorting.
                *(current_values_p + i) = get_stock_value(current_node->stock_symbol) * current_node->share_count;
                current_node = current_node->next;
            }
            current_values_p = new double[portfolio_node_count];
        }
    }

    return current_values_p;
}


// Uses selection sorting algorithm to sort all nodes in doubly link list that
// hold user portfolio information. Returns the pointer to the array of current
// portfolio values used to sort the list since each time the stock value is
// read a random value is found meaning before sorting all values must be read
// to enforce the sorting critiria.
// This is not using a different data structure to perform the sorting. It is
// only keeping a temporary record of the values that were used to perform the
// sorting so there is not a disagreement from the sorted list and the values
// seen when the list is printed.
double * PortfolioAccount::sort_portfolio_selection() {
    PortfolioNode *current_node = node_list_head;

    // Load current portfolio values into array.
    // This is to keep values consistent during sorting operations.
    double *current_values_p;
    current_values_p = new double[portfolio_node_count];
    for (int i = 0; i < portfolio_node_count; i++) {
        // Get all the current portfolio value in an array to keep values consistent while sorting.
        *(current_values_p + i) = get_stock_value(current_node->stock_symbol) * current_node->share_count;
        current_node = current_node->next;
    }

    // Selection sorting based on array of current portfolio values current_values_p.
    int swap_index;
    PortfolioNode *current_node_swap = NULL;
    PortfolioNode *current_node_i = node_list_head;
    for (int i = 0; i < portfolio_node_count; i++) {
        int current_max = *(current_values_p + i);
        // Set swap to current index. Will overwrite if lesser value found.
        swap_index = i;
        PortfolioNode *current_node_j = current_node_i->next;
        for (int j = i + 1; j < portfolio_node_count; j++) {
            // Select min element and set to first value with
            if (*(current_values_p + j) > current_max) {
                current_max = *(current_values_p + j);
                swap_index = j;
                current_node_swap = current_node_j;
            }
            current_node_j = current_node_j->next;
        }

        // Swap nodes if selected node i is not the max of the remaining list.
        if (swap_index != i) {
            // Swap array value for next sorting step.
            *(current_values_p + swap_index) = *(current_values_p + i);
            *(current_values_p + i) = current_max;

            // Handle swapping involving head node.
            if (i == 0) {
                node_list_head = current_node_swap;
            }
            
            // Handle swapping involving tail node.
            if (swap_index == portfolio_node_count - 1) {
                node_list_tail = current_node_i;
            }

            // Perform pointer swap for portfolio node list.
            if (i == swap_index - 1) {
                // Handle swap when two nodes are neighbors.

                // Handle neighbor node updates if not end of list.
                if (current_node_i->prev) {
                    current_node_i->prev->next = current_node_swap;
                }
                if (current_node_swap->next) {
                    current_node_swap->next->prev = current_node_i;
                }
                
                current_node_i->next = current_node_swap->next;
                current_node_swap->next = current_node_i;
                current_node_swap->prev = current_node_i->prev;
                current_node_i->prev = current_node_swap;
            } else {
                // Handle swap when two nodes are not neighbors.
                PortfolioNode * temp_node;
                current_node_swap->prev->next = current_node_i;
                
                // Handle neighbor node updates if not end of list.
                if (current_node_i->prev) {
                    current_node_i->prev->next = current_node_swap;
                }
                if (current_node_swap->next) {
                    current_node_swap->next->prev = current_node_i;
                }

                current_node_i->next->prev = current_node_swap;
                temp_node = current_node_i->next;
                current_node_i->next = current_node_swap->next;
                current_node_swap->next = temp_node;

                temp_node = current_node_i->prev;
                current_node_i->prev = current_node_swap->prev;
                current_node_swap->prev = temp_node;

            }
            // Set the current node the the newly placed sorted node in it's place.
            current_node_i = current_node_swap;
        }
        current_node_i = current_node_i->next;
    }

    return current_values_p;
}


// Uses bubble sorting algorithm to sort all nodes in doubly link list that
// hold user portfolio information. Returns the pointer to the array of current
// portfolio values used to sort the list since each time the stock value is
// read a random value is found meaning before sorting all values must be read
// to enforce the sorting critiria.
// This is not using a different data structure to perform the sorting. It is
// only keeping a temporary record of the values that were used to perform the
// sorting so there is not a disagreement from the sorted list and the values
// seen when the list is printed.
double * PortfolioAccount::sort_portfolio_bubble() {
    PortfolioNode *current_node = node_list_head;

    // Load current portfolio values into array.
    // This is to keep values consistent during sorting operations.
    double *current_values_p;
    current_values_p = new double[portfolio_node_count];
    for (int i = 0; i < portfolio_node_count; i++) {
        // Get all the current portfolio value in an array to keep values consistent while sorting.
        *(current_values_p + i) = get_stock_value(current_node->stock_symbol) * current_node->share_count;
        current_node = current_node->next;
    }

    // Bubble sorting based on array of current portfolio values current_values_p.
    PortfolioNode *current_node_i = node_list_head;
    double temp;
    for (int sorted_count = 0; sorted_count < portfolio_node_count; sorted_count++) {
        // Offset by already sorted nodes and one less than total list count for look ahead.
        PortfolioNode *current_node = node_list_head;
        for (int i = 0; i < portfolio_node_count - sorted_count  - 1; i++) {
            // Swap current and right node if current node less than right node.
            if (*(current_values_p + i) < *(current_values_p + i + 1)) {
                // Update the array used to reference values.
                temp = *(current_values_p + i);
                *(current_values_p + i) = *(current_values_p + i + 1);
                *(current_values_p + i + 1) = temp;
                
                PortfolioNode *current_node_swap = current_node->next;

                // Handle swapping involving head node.
                if (i == 0) {
                    node_list_head = current_node_swap;
                }
                
                // Handle swapping involving tail node.
                if (i + 1 == portfolio_node_count - 1) {
                    node_list_tail = current_node;
                }

                // Handle neighbor node updates if not end of list.
                if (current_node->prev) {
                    current_node->prev->next = current_node_swap;
                }
                if (current_node_swap->next) {
                    current_node_swap->next->prev = current_node;
                }

                
                // Handle swap when two nodes are neighbors.
                current_node->next = current_node_swap->next;
                current_node_swap->next = current_node;
                current_node_swap->prev = current_node->prev;
                current_node->prev = current_node_swap;

                // Set the current node the the newly placed sorted node in it's place.
                current_node = current_node_swap;
            }

            // Update to next node.
            current_node = current_node->next;

        }
    }

    return current_values_p;
}


// Saves current portfolio doubly linked list to txt file.
void PortfolioAccount::save_portfolio() {
    double * _ = sort_portfolio();
    delete [] _;

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


// Add shares to existing or new node if stock symbol not in current list.
// Returns true upon successful transaction.
// Fails upon invalid additon count.
bool PortfolioAccount::add_shares(std::string stock_symbol, int share_count) {
    bool success = false;
    if (share_count > 0) {
        PortfolioNode *prev_node = node_list_head;
        PortfolioNode *current_node = node_list_head;

        // Check if current user has any entries in current portfolio.
        // If not begin doubly linked list.
        if (current_node) {
            bool create_new_node = true;
            while (current_node) {
                if (current_node->stock_symbol == stock_symbol) {
                  current_node->share_count = current_node->share_count + share_count;
                  create_new_node = false;
                  success = true;
                  break;
                }
                prev_node = current_node;
                current_node = current_node->next;
            }
            // Append new node to list.
            if (create_new_node) {
                PortfolioNode* new_node = new PortfolioNode(stock_symbol, share_count);
                prev_node->next = new_node;
                new_node->prev = prev_node;
                new_node->next = NULL;
                node_list_tail = new_node;
                success = true;
                portfolio_node_count++;
            }
        } else {
            // Add first node to doubly linked list.
            PortfolioNode* new_node = new PortfolioNode(stock_symbol, share_count);
            new_node->prev = NULL;
            new_node->next = NULL;
            node_list_head = new_node;
            node_list_tail = new_node;
            success = true;
            portfolio_node_count++;
        }
    }

    // Save portfolio upon successful transaction.
    if (success) {
        save_portfolio();
    }
    return success;
}


// Remove shares from existing node or delete node entirely if count reduced to zero.
// Returns true upon successful transaction.
// Fails upon invalid stock symbol, share removal count larger than currently owned count,
// or remove count not postive valued.
bool PortfolioAccount::remove_shares(std::string stock_symbol, int share_count) {
    bool success = false;
    if (share_count > 0) {
        PortfolioNode *prev_node = node_list_head;
        PortfolioNode *current_node = node_list_head;

        int new_share_count;
        while (current_node) {
            if (current_node->stock_symbol == stock_symbol) {
                new_share_count = current_node->share_count - share_count;

                if (new_share_count < 0) {
                    // Fail if asked to remove more shares than you currently own.
                    success = false;
                } else if (new_share_count == 0) {
                    // Remove node if share count reduced to zero.
                    if (current_node->next && current_node->prev) {
                        // Handle center node removal.
                        // Have next and previous pointers of surrounding nodes skip node to be deleted.
                        prev_node->next = current_node->next;
                        current_node->next->prev = prev_node;
                        delete current_node;
                        success = true;
                        portfolio_node_count--;
                    } else if (!current_node->prev) {
                        // Handle head node removal.
                        if (!current_node->next) {
                            // If only node in list set head and tail to NULL.
                            node_list_head = NULL;
                            node_list_tail = NULL;
                        } else {
                            // If other nodes exist shift new head to next node and set new heads previous pointer to NULL.
                            node_list_head = current_node->next;
                            node_list_head->prev = NULL;
                        }
                        delete current_node;
                        success = true;
                        portfolio_node_count--;
                    } else if (!current_node->next && current_node->prev) {
                        // Handle tail node removal.
                        delete current_node;
                        prev_node->next = NULL;
                        node_list_tail = prev_node;
                        success = true;
                        portfolio_node_count--;
                    }
                } else {
                    // Remove share count if not all shares are sold.
                    current_node->share_count = current_node->share_count - share_count;
                    success = true;
                }
                break;
            }
            prev_node = current_node;
            current_node = current_node->next;
        }
    }

    // Save portfolio information upon successful transaction.
    if (success) {
        save_portfolio();
    }
    return success;
}


// Prints user cash balance, current stock symbols, their share counts, and their current values in decreasing order.
void PortfolioAccount::print_portfolio_desc() {
    // Print user cash balance.
    printf("%-28s$%-13.2f\n\n", "Cash Balance:", get_cash_balance());

    // Prints all user portfollio information
    double * current_portfolio_values_p = sort_portfolio();
    PortfolioNode *current_node = node_list_head;
    if (current_node) {
        double current_total_value;
        double current_total_value_all;

        current_total_value_all = get_cash_balance();
        printf("%-14s%-14s%-14s\n", "Stock Symbol", "Share Count", "Total Value");
        int i = 0;
        while (current_node) {
            current_total_value = *(current_portfolio_values_p + i);
            current_total_value_all += current_total_value;
            printf("%-14s%-14d$%-13.2f\n", current_node->stock_symbol.c_str(), current_node->share_count, current_total_value);
            current_node = current_node->next;
            i++;
        }
        printf("%-28s$%-13.2f\n", "Total Value:", current_total_value_all);

    } else {
        std::cout << "No portfolio information found." << std::endl;
    }
    // Delete temporary values to free space.
    delete [] current_portfolio_values_p;
}


// Prints user cash balance, current stock symbols, their share counts, and their current values in increasing order.
void PortfolioAccount::print_portfolio_asc() {
    // Print user cash balance.
    printf("%-28s$%-13.2f\n\n", "Cash Balance:", get_cash_balance());

    // Prints all user portfollio information
    double * current_portfolio_values_p = sort_portfolio();
    PortfolioNode *current_node = node_list_tail;
    if (current_node) {
        double current_total_value;
        double current_total_value_all;

        current_total_value_all = get_cash_balance();
        printf("%-14s%-14s%-14s\n", "Stock Symbol", "Share Count", "Total Value");
        int i = portfolio_node_count - 1;
        while (current_node) {
            current_total_value = *(current_portfolio_values_p + i);
            current_total_value_all += current_total_value;
            printf("%-14s%-14d$%-13.2f\n", current_node->stock_symbol.c_str(), current_node->share_count, current_total_value);
            current_node = current_node->prev;
            i--;
        }
        printf("%-28s$%-13.2f\n", "Total Value:", current_total_value_all);
    } else {
        std::cout << "No portfolio information found." << std::endl;
    }
    // Delete temporary values to free space.
    delete [] current_portfolio_values_p;
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


// Returns current count of shares owned for passed stock symbol.
// Returns 0 for invalid stock symbols and stock symbols not currently owned.
int PortfolioAccount::get_current_share_count(std::string stock_symbol) {
    PortfolioNode *current_node = node_list_head;

    // Iterate through all entries in list.
    // Node list criteria forces unique stock symbol.
    int stock_share_count = 0;
    while (current_node) {
        if (stock_symbol == current_node->stock_symbol) {
            stock_share_count = current_node->share_count;
            break;
        }
        current_node = current_node->next;
    }

    return stock_share_count;
}


// Returns the current total portfolio value.
double PortfolioAccount::get_portfolio_value() {
    double total_value = 0;
    PortfolioNode *current_node = node_list_head;

    // Iterate through all entries in list.
    while (current_node) {
        total_value += current_node->share_count * get_stock_value(current_node->stock_symbol);
        current_node = current_node->next;
    }
    return total_value;
}


// Purchase shares for passed input symbol for input share_purchase_count if max price per share is greater than current price.
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

    if (share_purchase_count <= 0) {
        std::cout << "Share purchase count must be a positive value." << std::endl;
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
            // Use get_portfolio_value to calculate total value before new purchase and add agreed upon price to value
            // to avoid mismatch between agreed purchase price and possible change due to value randomness.
            double total_value;
            total_value = get_portfolio_value() + purchase_price;
            std::string current_time = now_str();

            // Check if share removal was successful otherwise do not go through with transaction.
            valid_transaction = add_shares(stock_symbol, share_purchase_count);

            if (!valid_transaction) {
                std::cout << "Something has gone wrong, cancelling transaction." << std::endl;
            } else {
                // Open file to append new transcations for bank and portfolio account.
                std::ofstream bank_transaction_history_file;
                bank_transaction_history_file.open(bank_transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
                bank_transaction_history_file << "Withdrawal " << std::fixed << std::setprecision(2) << purchase_price << " " << today_str() << " " << std::fixed << std::setprecision(2) << new_balance << "\n";
                bank_transaction_history_file.close();

                std::ofstream portfolio_transaction_history_file;
                portfolio_transaction_history_file.open(portfolio_transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
                portfolio_transaction_history_file << "Buy " << stock_symbol << " " << share_purchase_count << " " << std::fixed << std::setprecision(2) << current_share_price << " " << std::fixed << std::setprecision(2) << total_value << " " << current_time << "\n";
                portfolio_transaction_history_file.close();

                // Adjust cash balance to reflect transaction.
                PortfolioAccount::set_cash_balance(new_balance);
                std::cout << "Transaction Complete" << std::endl;
            }
        } else {
            std::cout << "Transaction Cancelled" << std::endl;
        }
    } else {
        std::cout << "Transaction Cancelled" << std::endl;
    }
}


// Sells shares for passed input symbol for input share_sale_count if min sale price less than current price.
void PortfolioAccount::sell_shares(std::string stock_symbol, int share_sale_count, double min_price_per_share) {
    // Validators set to false to cancel invalid transaction. 
    bool valid_transaction = true;

    // Check if entered price per share offer is two digit number.
    if (!check_scale(min_price_per_share)) {
        std::cout << "Entered price per share cannot be more precise than two digits" << std::endl;
        valid_transaction = false;
    }

    // Do not allow user to offer non-postive price per share.
    if (min_price_per_share <= 0) {
        std::cout << "Sale price per share must be postive." << std::endl;
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

    // Check if user acceptable sales offer is not above current stock value.
    // Only display if user has entered a valid stock option.
    if (current_share_price < min_price_per_share && current_share_price > 0) {
        printf("Current %s stock price of $%.2f is less than your minimum acceptable offer of $%.2f.\n", stock_symbol.c_str(), current_share_price, min_price_per_share);
        valid_transaction = false;
    }

    // Ensure share sale count is postive valued.
    if (share_sale_count <= 0) {
        std::cout << "Share sale count must be a positive value." << std::endl;
        valid_transaction = false;
    }

    // Check if user has enough shares needed for transaction.
    int new_share_count;
    int current_share_count;
    current_share_count = get_current_share_count(stock_symbol);
    new_share_count = current_share_count - share_sale_count;

    // Do not allow sale for more shares than you currently own.
    // Since share counts for non existant stock symbols also return 0 check that the
    // price is also valid so this message only appears for valid stock symbols.
    if (new_share_count < 0 && current_share_price > 0) {
        // Gets new cash balance that appears once transaction has been completed.
        std::cout << "You currently only own " << current_share_count << " " << stock_symbol << " shares but attempting to sell " << share_sale_count << " shares, please do not try to sell more shares than you currently own."<< std::endl;
        valid_transaction = false;
    }

    // If valid transaction prompt user to confirm.
    if (valid_transaction) {
        double sale_price = share_sale_count * current_share_price;
        double new_balance = get_cash_balance() + sale_price;

        std::string user_confirmation;
        printf("You wish to sell %d %s shares at $%.2f per share totaling $%.2f, enter \"yes\" to continue: ", share_sale_count, stock_symbol.c_str(), current_share_price, sale_price);
        std::cin >> user_confirmation;

        // Deduct the cost from current cash balance and add new stock purchase to doubly linked list.
        if (user_confirmation == "yes") {
            // Use get_portfolio_value to calculate total value before new purchase and subtract agreed upon price
            // to avoid mismatch between agreed purchase price and possible change due to value randomness.
            double total_value;
            total_value = get_portfolio_value() - sale_price;
            std::string current_time = now_str();

            // Open file to append new transcation.
            valid_transaction = remove_shares(stock_symbol, share_sale_count);

            // If shares failed to be removed on coding error cancel entire transaction.
            if (!valid_transaction) {
                std::cout << "Something has gone wrong, cancelling transaction." << std::endl;
            } else {
                std::ofstream bank_transaction_history_file;
                bank_transaction_history_file.open(bank_transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
                bank_transaction_history_file << "Deposit " << std::fixed << std::setprecision(2) << sale_price << " " << today_str() << " " << std::fixed << std::setprecision(2) << new_balance << "\n";
                bank_transaction_history_file.close();

                std::ofstream portfolio_transaction_history_file;
                portfolio_transaction_history_file.open(portfolio_transaction_history_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
                portfolio_transaction_history_file << "Sell " << stock_symbol << " " << share_sale_count << " " << std::fixed << std::setprecision(2) << current_share_price << " " << std::fixed << std::setprecision(2) << total_value << " " << current_time << "\n";
                portfolio_transaction_history_file.close();

                // Adjust cash balance to reflect transaction.
                PortfolioAccount::set_cash_balance(new_balance);
                std::cout << "Transaction Complete" << std::endl;
            }
        } else {
            std::cout << "Transaction Cancelled" << std::endl;
        }
    } else {
        std::cout << "Transaction Cancelled" << std::endl;
    }
}


void PortfolioAccount::plot_portfolio_trend() {
    Engine *m_pEngine;

    m_pEngine = engOpen(NULL);
    if (m_pEngine == NULL) {
        std::cout << "Error: Failed to open Matlab." << std::endl;
    } else {
        int array_size = 100;
        int plot_x[array_size];
        double plot_y[array_size];

        for (int i = 0; i < array_size; i++) {
            plot_x[i] = i;
            plot_y[i] = i * 1.2424;            
        }

        mxArray* PLOT = mxCreateDoubleMatrix(array_size, 1, mxREAL);
        std::memcpy((void *) mxGetPr(PLOT), (void *) plot_y, sizeof(double) * array_size);
        engPutVariable(m_pEngine, "Portfolio Value Trend", PLOT);
    }

}


// Prints all user portfolio transactions.
void PortfolioAccount::print_transaction_history() {
    // Print transaction history headers.
    std::string line, event, stock_symbol, current_time;
    int stock_count;
    double price_per_share, total_value;

    // Open transaction history file.
    std::ifstream portfolio_transaction_history_file;
    portfolio_transaction_history_file.open(portfolio_transaction_history_filename.c_str());

    // Header and portfolio transaction history print.
    printf("%-12s%-16s%-12s%-16s%-16s%-26s\n", "Event", "CompSymbol", "Number", "PricePerShare", "TotalValue", "DateTime");
    while (getline(portfolio_transaction_history_file, line)) {
        std::istringstream ss(line);
        ss >> event >> stock_symbol >> stock_count >> price_per_share >> total_value >> current_time;
        printf("%-12s%-16s%-12d$%-15.2f$%-15.2f%-26s\n", event.c_str(), stock_symbol.c_str(), stock_count, price_per_share, total_value, current_time.c_str());
    }
    portfolio_transaction_history_file.close();
}

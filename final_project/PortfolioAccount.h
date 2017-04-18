#ifndef PORTFOLIO_ACCOUNT_H_
#define PORTFOLIO_ACCOUNT_H_


#include <string>
#include "Account.h"
#include "PortfolioNode.h"

class PortfolioAccount : public Account {

    public:
        PortfolioAccount();
        PortfolioAccount(std::string);
        ~PortfolioAccount();

        void load_portfolio();
        void add_end_node(std::string, int);
        double get_stock_value(std::string);
        void display_stock_value(std::string);
        void print_portfolio();
        void buy_shares(std::string, int, double);
        void print_transaction_history();

    private:
        unsigned int result_min;
        unsigned int result_max;

        std::string transaction_history_filename;
        std::string portfolio_info_filename;

        PortfolioNode *node_list_head;
        PortfolioNode *node_list_tail;
};


#endif

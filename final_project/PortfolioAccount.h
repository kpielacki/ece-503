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
        void save_portfolio();
        void print_portfolio();
        void print_transaction_history();

        void display_stock_value(std::string);
        int get_current_share_count(std::string);
        double get_stock_value(std::string);

        void add_shares(std::string, int);
        bool remove_shares(std::string, int);

        void buy_shares(std::string, int, double);
        void sell_shares(std::string, int, double);

    private:
        unsigned int result_min;
        unsigned int result_max;

        std::string transaction_history_filename;
        std::string portfolio_info_filename;

        PortfolioNode *node_list_head;
        PortfolioNode *node_list_tail;
};


#endif

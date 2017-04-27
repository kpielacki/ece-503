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
        std::string get_sort_method();
        void set_sort_method(int);
        double * sort_portfolio();
        double * sort_portfolio_selection();
        double * sort_portfolio_bubble();
        void print_portfolio_desc();
        void print_portfolio_asc();
        void print_transaction_history();

        void display_stock_value(std::string);
        int get_current_share_count(std::string);
        double get_stock_value(std::string);
        double get_portfolio_value();

        bool add_shares(std::string, int);
        bool remove_shares(std::string, int);

        void buy_shares(std::string, int, double);
        void sell_shares(std::string, int, double);

    private:
        unsigned int result_min;
        unsigned int result_max;
        unsigned int portfolio_node_count;
        unsigned int sort_method;

        std::string bank_transaction_history_filename;
        std::string portfolio_transaction_history_filename;
        std::string portfolio_info_filename;

        PortfolioNode *node_list_head;
        PortfolioNode *node_list_tail;
};


#endif

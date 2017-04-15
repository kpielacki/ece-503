#ifndef PORTFOLIO_ACCOUNT_H_
#define PORTFOLIO_ACCOUNT_H_


#include <string>
#include "Account.h"

class PortfolioAccount : public Account {

    public:
        PortfolioAccount();
        PortfolioAccount(std::string);
        ~PortfolioAccount();

        double get_stock_value(std::string);
        void display_stock_value(std::string);
        void print_transaction_history();

    private:
        unsigned int result_min;
        unsigned int result_max;

        std::string transaction_history_filename;
};


#endif

#ifndef PORTFOLIO_NODE_H_
#define PORTFOLIO_NODE_H_


#include <string>


class PortfolioNode {

    friend class PortfolioAccount;

    public:
        PortfolioNode(std::string &stock_symbol_in, unsigned int stock_count_in): stock_symbol(stock_symbol_in), stock_count(stock_count_in) {
            this->prev = NULL;
            this->next = NULL;
        }

    private:
        std::string stock_symbol;
        unsigned int share_count;
        PortfolioNode *prev;
        PortfolioNode *next;
};

#endif

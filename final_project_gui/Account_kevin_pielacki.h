#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>


class Account {

    public:
        Account();
        Account(std::string);
        ~Account();

        bool is_active();
        void init_account();
        std::string get_username();
        double get_scale();
        double get_min_diff();
        bool check_scale(double);

        double get_cash_balance();
        void set_cash_balance(double);

        virtual void print_transaction_history() = 0;

    private:
        double scale;
        double min_diff;
        std::string username;
        std::string cash_balance_filename;

};

#endif

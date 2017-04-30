#include "buy_sell_window.h"
#include "ui_buy_sell_window.h"
#include "PortfolioAccount_kevin_pielacki.h"
#include "sort_select_var.h"
#include <iostream>


buy_sell_window::buy_sell_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buy_sell_window)
{
    ui->setupUi(this);
}

buy_sell_window::~buy_sell_window()
{
    delete ui;
}


void buy_sell_window::on_buttonBox_accepted()
{
    std::string stock_symbol = ui->stock_symbol_input->text().toLocal8Bit().constData();
    int share_count = ui->share_count_input->value();
    double amount = ui->amount_input->value();

    PortfolioAccount portfolio(username);
    portfolio.set_sort_method(sort_method);
    switch (transaction_type) {
        case 1:
            // buy
            portfolio.buy_shares(stock_symbol, share_count, amount);
            break;

        case 2:
            // sell
            portfolio.sell_shares(stock_symbol, share_count, amount);
            break;
        default:
            std::cout << "ERROR: Invalid transaction type " << transaction_type << std::endl;
   }
}

#include "portfolioaccountselection.h"
#include "ui_portfolioaccountselection.h"
#include "PortfolioAccount_kevin_pielacki.h"
#include "stockvaluewindow.h"
#include "sort_select_var.h"
#include "sortselectionwindow.h"
#include <iostream>

int sort_method = 2;


PortfolioAccountSelection::PortfolioAccountSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortfolioAccountSelection)
{
    ui->setupUi(this);
}

PortfolioAccountSelection::~PortfolioAccountSelection()
{
    delete ui;
}

void PortfolioAccountSelection::on_return_button_released()
{
    this->close();
}

void PortfolioAccountSelection::on_print_portfoio_asc_button_released()
{
    PortfolioAccount portfolio(username);
    portfolio.set_sort_method(sort_method);
    portfolio.print_portfolio_asc();
}

void PortfolioAccountSelection::on_print_portfoio_desc_button_released()
{
    PortfolioAccount portfolio(username);
    portfolio.set_sort_method(sort_method);
    portfolio.print_portfolio_desc();
}

void PortfolioAccountSelection::on_stock_prices_button_released()
{
    StockValueWindow stock_value_window;
    stock_value_window.username = username;
    stock_value_window.exec();
}

void PortfolioAccountSelection::on_transaction_history_button_released()
{
    PortfolioAccount portfolio(username);
    portfolio.set_sort_method(sort_method);
    portfolio.print_transaction_history();
}

void PortfolioAccountSelection::on_sort_select_button_released()
{
    SortSelectionWindow sort_selection_window;
    sort_selection_window.exec();
}

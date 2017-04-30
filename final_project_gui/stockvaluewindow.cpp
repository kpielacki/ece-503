#include "stockvaluewindow.h"
#include "ui_stockvaluewindow.h"
#include "PortfolioAccount_kevin_pielacki.h"
#include <iostream>

StockValueWindow::StockValueWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockValueWindow)
{
    ui->setupUi(this);
}

StockValueWindow::~StockValueWindow()
{
    delete ui;
}


// Display stock symbol.
void StockValueWindow::on_confirm_button_accepted()
{
    PortfolioAccount portfolio(username);
    std::string stock_symbol = ui->stock_symbol_input->text().toLocal8Bit().constData();
    portfolio.display_stock_value(stock_symbol);
}

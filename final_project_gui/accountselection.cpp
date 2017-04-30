#include "accountselection.h"
#include "ui_accountselection.h"
#include "bankaccountselection.h"
#include "portfolioaccountselection.h"
#include <QString>
#include <cstring>
#include <string>


AccountSelection::AccountSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountSelection)
{
    ui->setupUi(this);
}

AccountSelection::~AccountSelection()
{
    delete ui;
}


void AccountSelection::update_text() {
    QString text = QString("Welcome %1, please select an account to access:").arg(username.c_str());
    ui->header_label->setText(text);
}


void AccountSelection::on_logout_button_released() {
    this->close();
}


void AccountSelection::on_bank_account_button_released() {
    BankAccountSelection bank_account_selection_window;
    bank_account_selection_window.username = AccountSelection::username;
    bank_account_selection_window.exec();
}

void AccountSelection::on_stock_account_button_released()
{
    PortfolioAccountSelection portfolio_account_selection_window;
    portfolio_account_selection_window.username = AccountSelection::username;
    portfolio_account_selection_window.exec();
}

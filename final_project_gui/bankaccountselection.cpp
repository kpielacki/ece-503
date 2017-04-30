#include "bankaccountselection.h"
#include "ui_bankaccountselection.h"


BankAccountSelection::BankAccountSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankAccountSelection)
{
    ui->setupUi(this);
}


BankAccountSelection::~BankAccountSelection()
{
    delete ui;
}


void BankAccountSelection::on_bank_return_button_released()
{
    this->close();
}

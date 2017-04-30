#include "bankaccountselection.h"
#include "ui_bankaccountselection.h"
#include "BankAccount_kevin_pielacki.h"
#include "bank_transaction_prompt.h"


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

void BankAccountSelection::on_view_account_balance_button_released()
{
    BankAccount checking(username);
    checking.view_account_balance();
}

void BankAccountSelection::on_print_history_button_released()
{
    BankAccount checking(username);
    checking.print_transaction_history();
}


// Prompt bank transaction for deposit by setting transaction type to 0.
void BankAccountSelection::on_deposit_button_released()
{
    bank_transaction_prompt bank_transaction_prompt_window;
    bank_transaction_prompt_window.transaction_type = 0;
    bank_transaction_prompt_window.username = username;
    bank_transaction_prompt_window.update_text();
    bank_transaction_prompt_window.exec();
}


// Prompt bank transaction for withdraw by setting transaction type to 1.
void BankAccountSelection::on_withdraw_button_released()
{
    bank_transaction_prompt bank_transaction_prompt_window;
    bank_transaction_prompt_window.transaction_type = 1;
    bank_transaction_prompt_window.username = username;
    bank_transaction_prompt_window.update_text();
    bank_transaction_prompt_window.exec();
}

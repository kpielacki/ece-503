#include "bank_transaction_prompt.h"
#include "ui_bank_transaction_prompt.h"
#include "BankAccount_kevin_pielacki.h"


bank_transaction_prompt::bank_transaction_prompt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bank_transaction_prompt)
{
    ui->setupUi(this);
}

bank_transaction_prompt::~bank_transaction_prompt()
{
    delete ui;
}


void bank_transaction_prompt::update_text() {
    switch (transaction_type) {
        case 0:
            ui->action_label->setText("Deposit");
            break;
        case 1:
            ui->action_label->setText("Withdraw");
            break;
        default:
            ui->action_label->setText("ERROR");
    }
}


void bank_transaction_prompt::on_confirm_button_accepted()
{
    double amount;
    amount = ui->doubleSpinBox->value();

    BankAccount checking(username);
    switch (transaction_type) {
        case 0:
            checking.deposit(amount);
            break;
        case 1:
            checking.withdraw(amount);
            break;
        default:
            ui->action_label->setText("ERROR");
    }
}

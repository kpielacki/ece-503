#include "checking_balance_window.h"
#include "ui_checking_balance_window.h"

checking_balance_window::checking_balance_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checking_balance_window)
{
    ui->setupUi(this);
}

checking_balance_window::~checking_balance_window()
{
    delete ui;
}

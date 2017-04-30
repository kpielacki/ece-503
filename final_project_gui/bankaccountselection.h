#ifndef BANKACCOUNTSELECTION_H
#define BANKACCOUNTSELECTION_H

#include <QDialog>
#include <string>


namespace Ui {
class BankAccountSelection;
}

class BankAccountSelection : public QDialog
{
    Q_OBJECT

public:
    explicit BankAccountSelection(QWidget *parent = 0);
    ~BankAccountSelection();

    std::string username;

private slots:
    void on_bank_return_button_released();

private:
    Ui::BankAccountSelection *ui;
};

#endif // BANKACCOUNTSELECTION_H

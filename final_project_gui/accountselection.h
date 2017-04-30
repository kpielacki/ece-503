#ifndef ACCOUNTSELECTION_H
#define ACCOUNTSELECTION_H

#include <QDialog>
#include <string>


namespace Ui {
class AccountSelection;
}

class AccountSelection : public QDialog
{
    Q_OBJECT

public:
    explicit AccountSelection(QWidget *parent = 0);
    ~AccountSelection();

    std::string username;
    void update_text();

private slots:
    void on_logout_button_released();

    void on_bank_account_button_released();

private:
    Ui::AccountSelection *ui;
};

#endif // ACCOUNTSELECTION_H

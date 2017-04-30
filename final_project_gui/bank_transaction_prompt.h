#ifndef BANK_TRANSACTION_PROMPT_H
#define BANK_TRANSACTION_PROMPT_H

#include <QDialog>
#include <string>


namespace Ui {
class bank_transaction_prompt;
}

class bank_transaction_prompt : public QDialog
{
    Q_OBJECT

public:
    explicit bank_transaction_prompt(QWidget *parent = 0);
    ~bank_transaction_prompt();

    std::string username;
    int transaction_type;
    void update_text();

private slots:
    void on_confirm_button_accepted();

private:
    Ui::bank_transaction_prompt *ui;
};

#endif // BANK_TRANSACTION_PROMPT_H

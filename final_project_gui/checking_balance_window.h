#ifndef CHECKING_BALANCE_WINDOW_H
#define CHECKING_BALANCE_WINDOW_H

#include <QDialog>

namespace Ui {
class checking_balance_window;
}

class checking_balance_window : public QDialog
{
    Q_OBJECT

public:
    explicit checking_balance_window(QWidget *parent = 0);
    ~checking_balance_window();

private:
    Ui::checking_balance_window *ui;
};

#endif // CHECKING_BALANCE_WINDOW_H

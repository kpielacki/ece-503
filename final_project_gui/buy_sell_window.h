#ifndef BUY_SELL_WINDOW_H
#define BUY_SELL_WINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class buy_sell_window;
}

class buy_sell_window : public QDialog
{
    Q_OBJECT

public:
    explicit buy_sell_window(QWidget *parent = 0);
    ~buy_sell_window();

    std::string username;
    int transaction_type;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::buy_sell_window *ui;
};

#endif // BUY_SELL_WINDOW_H

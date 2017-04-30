#ifndef STOCKVALUEWINDOW_H
#define STOCKVALUEWINDOW_H

#include <QDialog>

namespace Ui {
class StockValueWindow;
}

class StockValueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StockValueWindow(QWidget *parent = 0);
    ~StockValueWindow();

    std::string username;

private slots:
    void on_confirm_button_accepted();

private:
    Ui::StockValueWindow *ui;
};

#endif // STOCKVALUEWINDOW_H

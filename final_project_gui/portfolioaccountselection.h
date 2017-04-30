#ifndef PORTFOLIOACCOUNTSELECTION_H
#define PORTFOLIOACCOUNTSELECTION_H

#include <QDialog>

namespace Ui {
class PortfolioAccountSelection;
}

class PortfolioAccountSelection : public QDialog
{
    Q_OBJECT

public:
    explicit PortfolioAccountSelection(QWidget *parent = 0);
    ~PortfolioAccountSelection();

    std::string username;

private slots:
    void on_return_button_released();

    void on_print_portfoio_asc_button_released();

    void on_print_portfoio_desc_button_released();

    void on_stock_prices_button_released();

    void on_transaction_history_button_released();

    void on_sort_select_button_released();

private:
    Ui::PortfolioAccountSelection *ui;
};

#endif // PORTFOLIOACCOUNTSELECTION_H

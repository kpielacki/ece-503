#ifndef SORTSELECTIONWINDOW_H
#define SORTSELECTIONWINDOW_H

#include <QDialog>

namespace Ui {
class SortSelectionWindow;
}

class SortSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SortSelectionWindow(QWidget *parent = 0);
    ~SortSelectionWindow();

private slots:
    void on_bubble_button_released();

    void on_pushButton_2_released();

private:
    Ui::SortSelectionWindow *ui;
};

#endif // SORTSELECTIONWINDOW_H

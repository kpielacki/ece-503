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

private:
    Ui::SortSelectionWindow *ui;
};

#endif // SORTSELECTIONWINDOW_H

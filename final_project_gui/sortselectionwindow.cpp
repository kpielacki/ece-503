#include "sortselectionwindow.h"
#include "ui_sortselectionwindow.h"

SortSelectionWindow::SortSelectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortSelectionWindow)
{
    ui->setupUi(this);
}

SortSelectionWindow::~SortSelectionWindow()
{
    delete ui;
}

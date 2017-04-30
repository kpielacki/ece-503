#include "sortselectionwindow.h"
#include "ui_sortselectionwindow.h"
#include "sort_select_var.h"


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

void SortSelectionWindow::on_bubble_button_released()
{
    // 2 for bubble sorting.
    sort_method = 2;
    this->close();
}

void SortSelectionWindow::on_pushButton_2_released()
{
    // 1  for selection sorting.
    sort_method = 1;
    this->close();
}

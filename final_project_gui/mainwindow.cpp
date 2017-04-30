#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "accountselection.h"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_submit_released()
{
    // Open account selection for user in window.
    std::string username_in = ui->login_input->text().toLocal8Bit().constData();
    AccountSelection account_selection_window;
    account_selection_window.username = username_in;
    account_selection_window.update_text();
    account_selection_window.exec();
}

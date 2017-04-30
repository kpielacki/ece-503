#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDir>
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QDir::currentPath();
    w.show();



    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDir>
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    // Print path of executable.
    // Make sure Results.txt files are place in here.
    QDir::currentPath();

    w.show();

    return a.exec();
}

#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T13:30:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalProject_gui_kevin_pielacki
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    accountselection.cpp \
    bankaccountselection.cpp \
    Account_kevin_pielacki.cpp \
    BankAccount_kevin_pielacki.cpp \
    date_str_kevin_pielacki.cpp \
    PortfolioAccount_kevin_pielacki.cpp \
    time_str.cpp \
    checking_balance_window.cpp \
    bank_transaction_prompt.cpp

HEADERS  += mainwindow.h \
    accountselection.h \
    bankaccountselection.h \
    Account_kevin_pielacki.h \
    BankAccount_kevin_pielacki.h \
    date_str_kevin_pielacki.h \
    PortfolioAccount_kevin_pielacki.h \
    PortfolioNode_kevin_pielacki.h \
    time_str_kevin_pielacki.h \
    checking_balance_window.h \
    bank_transaction_prompt.h

FORMS    += mainwindow.ui \
    accountselection.ui \
    bankaccountselection.ui \
    checking_balance_window.ui \
    bank_transaction_prompt.ui

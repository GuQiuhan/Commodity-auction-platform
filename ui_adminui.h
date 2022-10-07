/********************************************************************************
** Form generated from reading UI file 'adminui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUI_H
#define UI_ADMINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AdminUI
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QTableView *tableView;

    void setupUi(QDialog *AdminUI)
    {
        if (AdminUI->objectName().isEmpty())
            AdminUI->setObjectName(QString::fromUtf8("AdminUI"));
        AdminUI->resize(720, 500);
        AdminUI->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(AdminUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 211, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(128, 0, 2);"));
        comboBox = new QComboBox(AdminUI);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(510, 20, 201, 32));
        tableView = new QTableView(AdminUI);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 701, 431));

        retranslateUi(AdminUI);

        QMetaObject::connectSlotsByName(AdminUI);
    } // setupUi

    void retranslateUi(QDialog *AdminUI)
    {
        AdminUI->setWindowTitle(QCoreApplication::translate("AdminUI", "Administrator", nullptr));
        label->setText(QCoreApplication::translate("AdminUI", "Hello! Administrator!", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AdminUI", "Choose\302\267\302\267\302\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AdminUI", "Check Orders", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AdminUI", "Check Users", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("AdminUI", "Check Commodities", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("AdminUI", "Search Commodities", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("AdminUI", "Remove Commodities", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("AdminUI", "Remove Users", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("AdminUI", "Log Out", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AdminUI: public Ui_AdminUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUI_H

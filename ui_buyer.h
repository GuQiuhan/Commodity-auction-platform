/********************************************************************************
** Form generated from reading UI file 'buyer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYER_H
#define UI_BUYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Buyer
{
public:
    QTableView *tableView;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *Buyer)
    {
        if (Buyer->objectName().isEmpty())
            Buyer->setObjectName(QString::fromUtf8("Buyer"));
        Buyer->resize(720, 500);
        tableView = new QTableView(Buyer);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 701, 431));
        comboBox = new QComboBox(Buyer);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(490, 20, 221, 32));
        label = new QLabel(Buyer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 201, 21));
        label->setStyleSheet(QString::fromUtf8("color:rgb(128, 0, 2);\n"
"font: 18pt \"Times\";"));

        retranslateUi(Buyer);

        QMetaObject::connectSlotsByName(Buyer);
    } // setupUi

    void retranslateUi(QDialog *Buyer)
    {
        Buyer->setWindowTitle(QCoreApplication::translate("Buyer", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Buyer", "Choose\302\267\302\267\302\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Buyer", "Check Commodities", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Buyer", "Search Commodities", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Buyer", "Buy Commodities", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Buyer", "Check My Orders", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Buyer", "Back", nullptr));

        label->setText(QCoreApplication::translate("Buyer", "as a BUYER:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buyer: public Ui_Buyer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYER_H

/********************************************************************************
** Form generated from reading UI file 'seller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLER_H
#define UI_SELLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Seller
{
public:
    QComboBox *comboBox;
    QTableView *tableView;
    QLabel *label;

    void setupUi(QDialog *Seller)
    {
        if (Seller->objectName().isEmpty())
            Seller->setObjectName(QString::fromUtf8("Seller"));
        Seller->resize(720, 500);
        comboBox = new QComboBox(Seller);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(500, 10, 211, 32));
        tableView = new QTableView(Seller);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(10, 50, 701, 441));
        label = new QLabel(Seller);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 191, 16));
        label->setStyleSheet(QString::fromUtf8("color:rgb(128, 0, 2);\n"
"font: 18pt \"Times\";"));

        retranslateUi(Seller);

        QMetaObject::connectSlotsByName(Seller);
    } // setupUi

    void retranslateUi(QDialog *Seller)
    {
        Seller->setWindowTitle(QCoreApplication::translate("Seller", "Seller", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Seller", "Choose\302\267\302\267\302\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Seller", "Launch Commodities", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Seller", "Check My Commodities", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Seller", "Modify My Commodities", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Seller", "Remove Commodities", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Seller", "Check My Orders", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Seller", "Back", nullptr));

        label->setText(QCoreApplication::translate("Seller", "as a SELLER:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Seller: public Ui_Seller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLER_H

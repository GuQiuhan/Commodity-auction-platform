/********************************************************************************
** Form generated from reading UI file 'buygood.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYGOOD_H
#define UI_BUYGOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BuyGood
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QTableView *tableView;
    QLabel *balance;
    QPushButton *pushButton;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;

    void setupUi(QDialog *BuyGood)
    {
        if (BuyGood->objectName().isEmpty())
            BuyGood->setObjectName(QString::fromUtf8("BuyGood"));
        BuyGood->resize(720, 500);
        label = new QLabel(BuyGood);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 381, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        comboBox = new QComboBox(BuyGood);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(390, 10, 221, 32));
        tableView = new QTableView(BuyGood);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 80, 701, 371));
        balance = new QLabel(BuyGood);
        balance->setObjectName(QString::fromUtf8("balance"));
        balance->setGeometry(QRect(10, 470, 301, 16));
        balance->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";\n"
"color:rgb(128, 0, 2)"));
        pushButton = new QPushButton(BuyGood);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 460, 112, 32));
        label_2 = new QLabel(BuyGood);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 411, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        spinBox = new QSpinBox(BuyGood);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(410, 50, 42, 22));
        pushButton_2 = new QPushButton(BuyGood);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(640, 40, 71, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color:rgb(253, 128, 8)"));

        retranslateUi(BuyGood);

        QMetaObject::connectSlotsByName(BuyGood);
    } // setupUi

    void retranslateUi(QDialog *BuyGood)
    {
        BuyGood->setWindowTitle(QCoreApplication::translate("BuyGood", "Buy", nullptr));
        label->setText(QCoreApplication::translate("BuyGood", "Choose the ID of the commodity you want to buy:", nullptr));
        balance->setText(QCoreApplication::translate("BuyGood", "Your balance:", nullptr));
        pushButton->setText(QCoreApplication::translate("BuyGood", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("BuyGood", "Choose the number of the commodity you want to buy:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BuyGood", "BUY ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyGood: public Ui_BuyGood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYGOOD_H

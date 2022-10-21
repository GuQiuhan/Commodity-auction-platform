/********************************************************************************
** Form generated from reading UI file 'auctionbuygood.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUCTIONBUYGOOD_H
#define UI_AUCTIONBUYGOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AuctionBuyGood
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QLabel *balance;
    QPushButton *pushButton;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QDialog *AuctionBuyGood)
    {
        if (AuctionBuyGood->objectName().isEmpty())
            AuctionBuyGood->setObjectName(QString::fromUtf8("AuctionBuyGood"));
        AuctionBuyGood->resize(720, 500);
        label = new QLabel(AuctionBuyGood);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 381, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        label_2 = new QLabel(AuctionBuyGood);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 411, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        comboBox = new QComboBox(AuctionBuyGood);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(380, 10, 221, 32));
        spinBox = new QSpinBox(AuctionBuyGood);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(420, 50, 42, 22));
        pushButton_2 = new QPushButton(AuctionBuyGood);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(640, 50, 71, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tableView = new QTableView(AuctionBuyGood);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 110, 701, 341));
        balance = new QLabel(AuctionBuyGood);
        balance->setObjectName(QString::fromUtf8("balance"));
        balance->setGeometry(QRect(10, 470, 301, 16));
        balance->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";\n"
"color:rgb(128, 0, 2)"));
        pushButton = new QPushButton(AuctionBuyGood);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 460, 112, 32));
        label_3 = new QLabel(AuctionBuyGood);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 411, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        doubleSpinBox = new QDoubleSpinBox(AuctionBuyGood);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(400, 80, 62, 22));

        retranslateUi(AuctionBuyGood);

        QMetaObject::connectSlotsByName(AuctionBuyGood);
    } // setupUi

    void retranslateUi(QDialog *AuctionBuyGood)
    {
        AuctionBuyGood->setWindowTitle(QCoreApplication::translate("AuctionBuyGood", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AuctionBuyGood", "Choose the ID of the commodity you want to buy:", nullptr));
        label_2->setText(QCoreApplication::translate("AuctionBuyGood", "Choose the number of the commodity you want to buy:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AuctionBuyGood", "BUY ", nullptr));
        balance->setText(QCoreApplication::translate("AuctionBuyGood", "Your balance:", nullptr));
        pushButton->setText(QCoreApplication::translate("AuctionBuyGood", "Back", nullptr));
        label_3->setText(QCoreApplication::translate("AuctionBuyGood", "Choose the price of the commodity you can provide:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuctionBuyGood: public Ui_AuctionBuyGood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUCTIONBUYGOOD_H

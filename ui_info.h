/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *name;
    QLineEdit *contact;
    QLineEdit *address;
    QLineEdit *balance;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(371, 265);
        label = new QLabel(Info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 81, 16));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 58, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 58, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label_4 = new QLabel(Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 160, 58, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        name = new QLineEdit(Info);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(120, 40, 221, 21));
        contact = new QLineEdit(Info);
        contact->setObjectName(QString::fromUtf8("contact"));
        contact->setGeometry(QRect(110, 80, 231, 21));
        address = new QLineEdit(Info);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(110, 120, 231, 21));
        balance = new QLineEdit(Info);
        balance->setObjectName(QString::fromUtf8("balance"));
        balance->setGeometry(QRect(110, 160, 231, 21));
        pushButton = new QPushButton(Info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 200, 71, 32));
        pushButton_2 = new QPushButton(Info);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 200, 112, 32));
        pushButton_3 = new QPushButton(Info);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 200, 71, 32));

        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", "Personal Info", nullptr));
        label->setText(QCoreApplication::translate("Info", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("Info", "Contact:", nullptr));
        label_3->setText(QCoreApplication::translate("Info", "Address:", nullptr));
        label_4->setText(QCoreApplication::translate("Info", "Balance:", nullptr));
        pushButton->setText(QCoreApplication::translate("Info", "Save", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Info", "Recharge", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Info", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H

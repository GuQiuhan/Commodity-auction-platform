/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *Username_label;
    QLabel *Password_label;
    QLabel *Password_label_2;
    QLineEdit *Username_lineEdit;
    QLineEdit *Password_lineEdit;
    QLineEdit *Password_lineEdit_2;
    QPushButton *Register_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(400, 300);
        Username_label = new QLabel(Register);
        Username_label->setObjectName(QString::fromUtf8("Username_label"));
        Username_label->setGeometry(QRect(20, 60, 81, 20));
        Password_label = new QLabel(Register);
        Password_label->setObjectName(QString::fromUtf8("Password_label"));
        Password_label->setGeometry(QRect(20, 100, 81, 20));
        Password_label_2 = new QLabel(Register);
        Password_label_2->setObjectName(QString::fromUtf8("Password_label_2"));
        Password_label_2->setGeometry(QRect(20, 140, 121, 20));
        Username_lineEdit = new QLineEdit(Register);
        Username_lineEdit->setObjectName(QString::fromUtf8("Username_lineEdit"));
        Username_lineEdit->setGeometry(QRect(110, 60, 221, 21));
        Password_lineEdit = new QLineEdit(Register);
        Password_lineEdit->setObjectName(QString::fromUtf8("Password_lineEdit"));
        Password_lineEdit->setGeometry(QRect(110, 100, 221, 21));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        Password_lineEdit_2 = new QLineEdit(Register);
        Password_lineEdit_2->setObjectName(QString::fromUtf8("Password_lineEdit_2"));
        Password_lineEdit_2->setGeometry(QRect(130, 140, 201, 21));
        Password_lineEdit_2->setEchoMode(QLineEdit::Password);
        Register_pushButton = new QPushButton(Register);
        Register_pushButton->setObjectName(QString::fromUtf8("Register_pushButton"));
        Register_pushButton->setGeometry(QRect(40, 220, 112, 32));
        cancel_pushButton = new QPushButton(Register);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));
        cancel_pushButton->setGeometry(QRect(230, 220, 112, 32));

        retranslateUi(Register);
        QObject::connect(cancel_pushButton, SIGNAL(clicked()), Register, SLOT(close()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Register", nullptr));
        Username_label->setText(QCoreApplication::translate("Register", "Username:", nullptr));
        Password_label->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        Password_label_2->setText(QCoreApplication::translate("Register", "Password again:", nullptr));
        Register_pushButton->setText(QCoreApplication::translate("Register", "Register", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("Register", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

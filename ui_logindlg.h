/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *Login_pushButton;
    QPushButton *Register_pushButton;
    QPushButton *Exit_pushButton;
    QLabel *Username_label;
    QLabel *Password_label;
    QLineEdit *Username_lineEdit;
    QLineEdit *Password_lineEdit;
    QLabel *Image_label;
    QCommandLinkButton *Manual_LinkButton;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(613, 306);
        LoginDlg->setStyleSheet(QString::fromUtf8(""));
        Login_pushButton = new QPushButton(LoginDlg);
        Login_pushButton->setObjectName(QString::fromUtf8("Login_pushButton"));
        Login_pushButton->setGeometry(QRect(140, 170, 121, 32));
        Register_pushButton = new QPushButton(LoginDlg);
        Register_pushButton->setObjectName(QString::fromUtf8("Register_pushButton"));
        Register_pushButton->setGeometry(QRect(140, 210, 121, 32));
        Exit_pushButton = new QPushButton(LoginDlg);
        Exit_pushButton->setObjectName(QString::fromUtf8("Exit_pushButton"));
        Exit_pushButton->setGeometry(QRect(140, 250, 121, 32));
        Username_label = new QLabel(LoginDlg);
        Username_label->setObjectName(QString::fromUtf8("Username_label"));
        Username_label->setGeometry(QRect(27, 60, 71, 20));
        Password_label = new QLabel(LoginDlg);
        Password_label->setObjectName(QString::fromUtf8("Password_label"));
        Password_label->setGeometry(QRect(27, 100, 61, 20));
        Username_lineEdit = new QLineEdit(LoginDlg);
        Username_lineEdit->setObjectName(QString::fromUtf8("Username_lineEdit"));
        Username_lineEdit->setGeometry(QRect(110, 60, 181, 21));
        Password_lineEdit = new QLineEdit(LoginDlg);
        Password_lineEdit->setObjectName(QString::fromUtf8("Password_lineEdit"));
        Password_lineEdit->setGeometry(QRect(110, 100, 181, 21));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        Image_label = new QLabel(LoginDlg);
        Image_label->setObjectName(QString::fromUtf8("Image_label"));
        Image_label->setGeometry(QRect(340, 0, 261, 271));
        Image_label->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/Images/1.jpg);"));
        Manual_LinkButton = new QCommandLinkButton(LoginDlg);
        Manual_LinkButton->setObjectName(QString::fromUtf8("Manual_LinkButton"));
        Manual_LinkButton->setGeometry(QRect(520, 270, 81, 31));

        retranslateUi(LoginDlg);
        QObject::connect(Exit_pushButton, SIGNAL(clicked()), LoginDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QCoreApplication::translate("LoginDlg", "Login", nullptr));
        Login_pushButton->setText(QCoreApplication::translate("LoginDlg", "Login", nullptr));
        Register_pushButton->setText(QCoreApplication::translate("LoginDlg", "Register", nullptr));
        Exit_pushButton->setText(QCoreApplication::translate("LoginDlg", "Exit", nullptr));
        Username_label->setText(QCoreApplication::translate("LoginDlg", "Username:", nullptr));
        Password_label->setText(QCoreApplication::translate("LoginDlg", "Password:", nullptr));
        Image_label->setText(QString());
        Manual_LinkButton->setText(QCoreApplication::translate("LoginDlg", "Manual", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H

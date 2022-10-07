/********************************************************************************
** Form generated from reading UI file 'userui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERUI_H
#define UI_USERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserUI
{
public:
    QLabel *label_2;
    QWidget *widget;
    QComboBox *comboBox;

    void setupUi(QDialog *UserUI)
    {
        if (UserUI->objectName().isEmpty())
            UserUI->setObjectName(QString::fromUtf8("UserUI"));
        UserUI->resize(463, 237);
        label_2 = new QLabel(UserUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 171, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(128, 0, 2);"));
        widget = new QWidget(UserUI);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 10, 271, 221));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/Images/2.jpg);"));
        comboBox = new QComboBox(UserUI);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 70, 161, 32));

        retranslateUi(UserUI);

        QMetaObject::connectSlotsByName(UserUI);
    } // setupUi

    void retranslateUi(QDialog *UserUI)
    {
        UserUI->setWindowTitle(QCoreApplication::translate("UserUI", "User", nullptr));
        label_2->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("UserUI", "Choose\302\267\302\267\302\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("UserUI", "I am a SELLER", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("UserUI", "I am a BUYER", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("UserUI", "Personal Info", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("UserUI", "Log Out", nullptr));

    } // retranslateUi

};

namespace Ui {
    class UserUI: public Ui_UserUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERUI_H

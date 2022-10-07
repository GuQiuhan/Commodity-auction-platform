/********************************************************************************
** Form generated from reading UI file 'recharge.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHARGE_H
#define UI_RECHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recharge
{
public:
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Recharge)
    {
        if (Recharge->objectName().isEmpty())
            Recharge->setObjectName(QString::fromUtf8("Recharge"));
        Recharge->resize(396, 106);
        label = new QLabel(Recharge);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 311, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        doubleSpinBox = new QDoubleSpinBox(Recharge);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(290, 11, 81, 31));
        pushButton = new QPushButton(Recharge);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 50, 112, 32));
        pushButton_2 = new QPushButton(Recharge);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 50, 112, 32));

        retranslateUi(Recharge);

        QMetaObject::connectSlotsByName(Recharge);
    } // setupUi

    void retranslateUi(QDialog *Recharge)
    {
        Recharge->setWindowTitle(QCoreApplication::translate("Recharge", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Recharge", "Input how much you want to recharge:", nullptr));
        pushButton->setText(QCoreApplication::translate("Recharge", "OK ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Recharge", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recharge: public Ui_Recharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHARGE_H

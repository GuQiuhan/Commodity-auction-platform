/********************************************************************************
** Form generated from reading UI file 'prepare.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPARE_H
#define UI_PREPARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Prepare
{
public:
    QLabel *label;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *Prepare)
    {
        if (Prepare->objectName().isEmpty())
            Prepare->setObjectName(QString::fromUtf8("Prepare"));
        Prepare->resize(353, 99);
        label = new QLabel(Prepare);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        label->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Times New Roman\";"));
        checkBox = new QCheckBox(Prepare);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(90, 40, 86, 20));
        checkBox_2 = new QCheckBox(Prepare);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(90, 70, 151, 20));
        commandLinkButton = new QCommandLinkButton(Prepare);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(290, 60, 61, 31));

        retranslateUi(Prepare);

        QMetaObject::connectSlotsByName(Prepare);
    } // setupUi

    void retranslateUi(QDialog *Prepare)
    {
        Prepare->setWindowTitle(QCoreApplication::translate("Prepare", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Prepare", "Choose the MODE:", nullptr));
        checkBox->setText(QCoreApplication::translate("Prepare", "Auction", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Prepare", "Normal Purchase", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("Prepare", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prepare: public Ui_Prepare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPARE_H

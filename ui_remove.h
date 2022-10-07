/********************************************************************************
** Form generated from reading UI file 'remove.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVE_H
#define UI_REMOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Remove
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Remove)
    {
        if (Remove->objectName().isEmpty())
            Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->resize(278, 140);
        label = new QLabel(Remove);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 241, 20));
        label->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(Remove);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 231, 21));
        buttonBox = new QDialogButtonBox(Remove);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 90, 164, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Remove);

        QMetaObject::connectSlotsByName(Remove);
    } // setupUi

    void retranslateUi(QDialog *Remove)
    {
        Remove->setWindowTitle(QCoreApplication::translate("Remove", "Remove", nullptr));
        label->setText(QCoreApplication::translate("Remove", "Input what you want to remove(ID):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Remove: public Ui_Remove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVE_H

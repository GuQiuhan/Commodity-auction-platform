/********************************************************************************
** Form generated from reading UI file 'modify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_H
#define UI_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Modify
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QLineEdit *name;
    QSpinBox *number;
    QDoubleSpinBox *price;
    QTextEdit *description;

    void setupUi(QDialog *Modify)
    {
        if (Modify->objectName().isEmpty())
            Modify->setObjectName(QString::fromUtf8("Modify"));
        Modify->resize(468, 345);
        label = new QLabel(Modify);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 321, 16));
        label->setStyleSheet(QString::fromUtf8("color:rgb(128, 0, 2);\n"
"font: 18pt \"Times\";"));
        pushButton = new QPushButton(Modify);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 300, 112, 32));
        pushButton_2 = new QPushButton(Modify);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 300, 112, 32));
        label_3 = new QLabel(Modify);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 58, 16));
        label_4 = new QLabel(Modify);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 58, 16));
        label_5 = new QLabel(Modify);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 140, 58, 16));
        label_6 = new QLabel(Modify);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 180, 81, 16));
        comboBox = new QComboBox(Modify);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(350, 10, 101, 32));
        name = new QLineEdit(Modify);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(70, 60, 261, 21));
        number = new QSpinBox(Modify);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(80, 140, 42, 22));
        price = new QDoubleSpinBox(Modify);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(70, 100, 62, 22));
        description = new QTextEdit(Modify);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(100, 180, 351, 101));

        retranslateUi(Modify);

        QMetaObject::connectSlotsByName(Modify);
    } // setupUi

    void retranslateUi(QDialog *Modify)
    {
        Modify->setWindowTitle(QCoreApplication::translate("Modify", "Modify", nullptr));
        label->setText(QCoreApplication::translate("Modify", "Select the commodity you want to change:", nullptr));
        pushButton->setText(QCoreApplication::translate("Modify", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Modify", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("Modify", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("Modify", "Price:", nullptr));
        label_5->setText(QCoreApplication::translate("Modify", "Number:", nullptr));
        label_6->setText(QCoreApplication::translate("Modify", "Description:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modify: public Ui_Modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H

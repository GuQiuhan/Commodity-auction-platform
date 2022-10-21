/********************************************************************************
** Form generated from reading UI file 'launchgood.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHGOOD_H
#define UI_LAUNCHGOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LaunchGood
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *name;
    QSpinBox *number;
    QDoubleSpinBox *price;
    QTextEdit *description;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *LaunchGood)
    {
        if (LaunchGood->objectName().isEmpty())
            LaunchGood->setObjectName(QString::fromUtf8("LaunchGood"));
        LaunchGood->resize(421, 323);
        label = new QLabel(LaunchGood);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 371, 16));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";\n"
"color:rgb(128, 0, 2)"));
        label_2 = new QLabel(LaunchGood);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 58, 16));
        label_3 = new QLabel(LaunchGood);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 100, 58, 16));
        label_4 = new QLabel(LaunchGood);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 140, 58, 16));
        label_5 = new QLabel(LaunchGood);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 180, 81, 16));
        name = new QLineEdit(LaunchGood);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(70, 60, 301, 21));
        number = new QSpinBox(LaunchGood);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(90, 140, 42, 22));
        price = new QDoubleSpinBox(LaunchGood);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(70, 100, 62, 22));
        description = new QTextEdit(LaunchGood);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(100, 180, 301, 81));
        pushButton = new QPushButton(LaunchGood);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 280, 101, 32));
        pushButton_2 = new QPushButton(LaunchGood);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 280, 112, 32));

        retranslateUi(LaunchGood);

        QMetaObject::connectSlotsByName(LaunchGood);
    } // setupUi

    void retranslateUi(QDialog *LaunchGood)
    {
        LaunchGood->setWindowTitle(QCoreApplication::translate("LaunchGood", "Launch", nullptr));
        label->setText(QCoreApplication::translate("LaunchGood", "Edit the information of the commodity you want to launch:", nullptr));
        label_2->setText(QCoreApplication::translate("LaunchGood", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("LaunchGood", "Price:", nullptr));
        label_4->setText(QCoreApplication::translate("LaunchGood", "Quantity:", nullptr));
        label_5->setText(QCoreApplication::translate("LaunchGood", "Description:", nullptr));
        pushButton->setText(QCoreApplication::translate("LaunchGood", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LaunchGood", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LaunchGood: public Ui_LaunchGood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHGOOD_H

/********************************************************************************
** Form generated from reading UI file 'addfunction.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNCTION_H
#define UI_ADDFUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFunction
{
public:

    void setupUi(QWidget *AddFunction)
    {
        if (AddFunction->objectName().isEmpty())
            AddFunction->setObjectName(QString::fromUtf8("AddFunction"));
        AddFunction->resize(400, 300);

        retranslateUi(AddFunction);

        QMetaObject::connectSlotsByName(AddFunction);
    } // setupUi

    void retranslateUi(QWidget *AddFunction)
    {
        AddFunction->setWindowTitle(QCoreApplication::translate("AddFunction", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFunction: public Ui_AddFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNCTION_H

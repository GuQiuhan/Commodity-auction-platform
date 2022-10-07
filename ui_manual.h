/********************************************************************************
** Form generated from reading UI file 'manual.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_H
#define UI_MANUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Manual
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *Manual)
    {
        if (Manual->objectName().isEmpty())
            Manual->setObjectName(QString::fromUtf8("Manual"));
        Manual->resize(598, 451);
        label = new QLabel(Manual);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 0, 201, 41));
        label->setStyleSheet(QString::fromUtf8("color:rgb(128, 0, 2);\n"
"font: 75 24pt \"Chalkboard SE\";"));
        textBrowser = new QTextBrowser(Manual);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 581, 391));
        pushButton = new QPushButton(Manual);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(491, 10, 91, 32));

        retranslateUi(Manual);
        QObject::connect(pushButton, SIGNAL(clicked()), Manual, SLOT(accept()));

        QMetaObject::connectSlotsByName(Manual);
    } // setupUi

    void retranslateUi(QDialog *Manual)
    {
        Manual->setWindowTitle(QCoreApplication::translate("Manual", "Manual", nullptr));
        label->setText(QCoreApplication::translate("Manual", "MANUAL  (*^\317\211^*)", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Manual", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hi~</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"tw-target-text\"></a><span style=\" font-family:'inherit'; color:#202124;\">I</span><span style=\" font-family:'inherit'; color:#202124;\">f you are a </span><span style=\" font-family:'inherit'; font-weight:600; color:#202124;\">new user</span><span sty"
                        "le=\" font-family:'inherit'; color:#202124;\"> of this app or encounter any </span><span style=\" font-family:'inherit'; font-weight:600; color:#202124;\">strange problems</span><span style=\" font-family:'inherit'; color:#202124;\"> during the usage, it is recommended to READ this manual first.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'inherit'; color:#202124;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"tw-target-text\"></a><span style=\" font-family:'inherit'; font-size:14pt; font-weight:600; color:#202124;\">O</span><span style=\" font-family:'inherit'; font-size:14pt; font-weight:600; color:#202124;\">perating environment:</span><span style=\" font-family:'inherit'; color:#202124;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0"
                        "px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">Windows, Linux, MacOS are all suitable, but Qt4.0 or above and g++ or clang++ compiler are in need.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'inherit'; color:#202124;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; font-size:14pt; font-weight:600; color:#202124;\">Language:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">English only.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'inherit'; color:#"
                        "202124;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; font-size:14pt; font-weight:600; color:#202124;\">Inialization:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">The administrator's account is exclusive: name:admin, pwd:123456.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; font-size:14pt; font-weight:600; color:#202124;\">Attention:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-in"
                        "dent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">DO NOT click the cross in the upper right corner of the window.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">MUST exit legally.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'inherit'; color:#202124;\">Three txts are empty. If you want to edit them, make sure the cursor is at the last word of text when you close them (That is to say NO EMPTY LINE!).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'inherit'; color:#202124;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px; font-family:'inherit'; color:#202124;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'inherit'; color:#202124;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Manual", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manual: public Ui_Manual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_H

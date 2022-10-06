#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include "register.h"
#include "adminui.h"
#include "userui.h"


namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr);
    ~LoginDlg();

private slots:
    void on_Login_pushButton_clicked();

    void on_Register_pushButton_clicked();

    void on_Manual_LinkButton_clicked();

private:
    Ui::LoginDlg *ui;
    Register r;
    AdminUI ad;


};


bool Check(QString name,QString pwd);//检查用户登陆

#endif // LOGINDLG_H

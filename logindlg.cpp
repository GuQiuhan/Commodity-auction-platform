#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include "manual.h"



//QString username; //声明一个全局变量用于窗体间传值
extern List<User> users; //调用全局变量


LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);


}

LoginDlg::~LoginDlg()
{
    delete ui;
}



void LoginDlg::on_Login_pushButton_clicked()//用户按下登录按钮
{
        if(ui->Username_lineEdit->text() == "admin"&&ui->Password_lineEdit->text()=="123456")//管理员登陆
        {
           QMessageBox::information(this, "Title", "Login Success!");//提示成功
           this->close();//关闭对话框，方便之后返回的时候再次打开
           ad.exec();//显示adminui

        }
        else if (Check(ui->Username_lineEdit->text(),ui->Password_lineEdit->text()))//用户登陆
        {
            QMessageBox::information(this, "Title", "Login Success!");//提示成功
           this->close();//关闭对话框，方便之后返回的时候再次打开

           //找到user,创建ui
           Node<User> *tmp=users.gethead();
           while(tmp)
           {
               if(tmp->t.getName()==ui->Username_lineEdit->text())
               {
                   if(tmp->t.getPwd()==ui->Password_lineEdit->text())
                   {
                       break;
                   }
               }
               tmp=tmp->next;
           }

            UserUI u(nullptr,tmp->t);
            u.exec();

        }

        else
        {
            //错误提示
           QMessageBox::warning(this, tr("Warning"), tr("Username or password error!"),QMessageBox::Ok);

           //清空，锁定光标
           ui->Username_lineEdit->clear();
           ui->Password_lineEdit->clear();
           ui->Username_lineEdit->setFocus();
        }
}

void LoginDlg::on_Register_pushButton_clicked()//用户按下注册按钮
{

    if(r.exec() == QDialog::Accepted) // 先执行register窗口,利用Accepted返回值判断按钮是否被按下，exec()表示模态对话框
    {
       r.close();
       // 程序一直执行，直到主窗口关闭
    }

}


bool Check(QString name,QString pwd)
{
    Node<User> *tmp=users.gethead();
    while(tmp)
    {
        if(tmp->t.getName()==name)
        {
            if(tmp->t.getPwd()==pwd)
            {
                return true;
            }
        }
        tmp=tmp->next;
    }
    return false;
}

void LoginDlg::on_Manual_LinkButton_clicked()
{
    Manual m;
    if(m.exec() == QDialog::Accepted) // 先执行register窗口,利用Accepted返回值判断按钮是否被按下，exec()表示模态对话框
    {
       m.close();
       // 程序一直执行，直到主窗口关闭
    }

}

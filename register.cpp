#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include "list.h"
#include "user.h"
#include <QDebug>
#include "test.h"

//全局变量
extern List<User> users;

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}


void Register::on_Register_pushButton_clicked()
{
    if(ui->Username_lineEdit->text()!=""&&ui->Password_lineEdit->text() ==ui->Password_lineEdit_2->text())//两次密码一致
    {

       User tmp(ui->Username_lineEdit->text(),ui->Password_lineEdit->text());//ok
       if(!Find(users,ui->Username_lineEdit->text()))//未重名
       {

           users.push_back(tmp);//no

           //加一个调试函数，输出所有users
           //PrintUsers(users);

           QMessageBox::information(this, "Title", "Success!");//提示成功
           ui->Username_lineEdit->clear();//清空，用于下一次注册
           ui->Password_lineEdit->clear();
           ui->Password_lineEdit_2->clear();
           ui->Username_lineEdit->setFocus();
           accept();
       }
       else
       {
           //名字已经存在
            QMessageBox::warning(this, tr("Warning"), tr("Username has existed!"),QMessageBox::Ok);
            ui->Username_lineEdit->clear();
            ui->Password_lineEdit->clear();
            ui->Password_lineEdit_2->clear();
            ui->Username_lineEdit->setFocus();
       }
    }
    else
    {
        //错误提示
       QMessageBox::warning(this, tr("Warning"), tr("Username or password error!"),QMessageBox::Ok);

       //清空，锁定光标
       ui->Username_lineEdit->clear();
       ui->Password_lineEdit->clear();
       ui->Password_lineEdit_2->clear();
       ui->Username_lineEdit->setFocus();
    }
}

 bool Register::Find(List<User>& l,QString name)//使用引用防止调用拷贝构造函数，拷贝list存在bug >_<
 {

     Node<User>* tmp(l.gethead());
     for(int i=0; i<l.getLen(); ++i)
     {
         if(tmp->t.getName()==name)
         {
             return true;

         }

         tmp=tmp->next;
     }
     return false;
 }

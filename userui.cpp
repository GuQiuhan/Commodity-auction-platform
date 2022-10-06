#include "userui.h"
#include "ui_userui.h"
#include "logindlg.h"
#include <QDebug>
extern List<User> users;

//extern QString username; //声明外部变量

UserUI::UserUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserUI)
{
    ui->setupUi(this);

    //ui->label_2->setText("Hello! "+ user.getName()+"!"); //对全局变量进行显示


}

UserUI::UserUI(QWidget *parent,User& u) :
    QDialog(parent),
    ui(new Ui::UserUI)
{
    ui->setupUi(this);

    user=u;

    ui->label_2->setText("Hello! "+ user.getName()+"!"); //对全局变量进行显示

    //qDebug()<<u.getSellerGood().getLen();
}

UserUI::~UserUI()
{
    delete ui;
}

void UserUI::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentText()== "I am a SELLER")
    {
        Seller seller;//卖家ui界面
        seller.Init(this->user.getName(),this->user);//填充数据
        seller.exec();
        //此界面未关闭，只是被覆盖了
        this->user=seller.getUser();//更新此界面的数据实体

    }
    else if(ui->comboBox->currentText()== "I am a BUYER")
    {
        Buyer buyer;//买家ui界面
        buyer.Init(this->user.getName(),this->user);
        buyer.exec();
        this->user=buyer.getUser();//更新此界面的数据实体

    }
    else if(ui->comboBox->currentText()== "Personal Info")
    {
        Info info;
        info.Init(this->user);
        info.exec();
        this->user.UpdateInfo(info.getName(),info.getAddr(),info.getContact(),info.getBal());//对本界面的数据实体更新
        //更新users
        users.update(user);

    }
    else if(ui->comboBox->currentText()== "Log Out")
    {
        LoginDlg d;
        this->close();
        d.exec();
    }


}



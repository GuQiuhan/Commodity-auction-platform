#include "info.h"
#include "ui_info.h"
#include <QMessageBox>
#include "recharge.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}


void Info::Init(User& u)
{
    this->u=u;//赋值数据实体
    //设置显示
    ui->name->setText(u.getName());
    ui->address->setText(u.getAddr());
    ui->contact->setText(u.getContact());
    ui->balance->setText(QString("%2").arg(u.getBal()));
    ui->balance->setReadOnly(true);//不允许编辑

}

void Info::on_pushButton_clicked()//change
{
    int ret = QMessageBox::question(this, "", "Are you sure to save the information?");
    if(ret == QMessageBox::StandardButton::Yes){
        QMessageBox::information(this, "Title", "Save Successfully!");//提示成功
        //数据统一在back的时候更新到userui.cpp
    }
    else{

    }


}

void Info::on_pushButton_2_clicked()//recharge
{
    Recharge r;
    int res=r.exec();
    if(res==QDialog::Accepted)//改变余额
    {
        float newBal=u.getBal()+r.getValue();

        ui->balance->setText(QString("%2").arg(newBal));
        //将数据返回userui
        //待写

    }

}


void Info::on_pushButton_3_clicked()//back
{
    this->close();
}

QString Info::getName()
{
    return ui->name->text();
}
QString Info::getAddr()
{
    return ui->address->text();
}
QString Info::getContact()
{
    return ui->contact->text();
}
QString Info::getBal()
{
    return ui->balance->text();
}

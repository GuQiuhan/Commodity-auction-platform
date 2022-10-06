#include "recharge.h"
#include "ui_recharge.h"
#include <QMessageBox>

Recharge::Recharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recharge)
{
    ui->setupUi(this);
}

Recharge::~Recharge()
{
    delete ui;
}

void Recharge::on_pushButton_clicked()//ok
{
    if(ui->doubleSpinBox->value()<=0)//判断数据是否合法
        QMessageBox::warning(this,"","Invalid Value!");
    else
    {
        QMessageBox::information(this, "Title", "Success!");//提示成功
        //将数据返回info界面
        this->accept();
    }
}

void Recharge::on_pushButton_2_clicked()//cancel
{
    this->reject();
}

float Recharge::getValue()
{
    return ui->doubleSpinBox->value();
}

#include "remove.h"
#include "ui_remove.h"
//QString removeContent;//全局变量，用来传输要删除的用户/商品

Remove::Remove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remove)
{
    ui->setupUi(this);
}

Remove::~Remove()
{
    delete ui;
}

void Remove::on_buttonBox_accepted()
{
    //removeContent=ui->lineEdit->text();
    this->close();
}

void Remove::on_buttonBox_rejected()
{
    this->close();
}

QString Remove::getRemoveContent()
{
    return ui->lineEdit->text();
}

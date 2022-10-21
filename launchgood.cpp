#include "launchgood.h"
#include "ui_launchgood.h"
#include <QMessageBox>

LaunchGood::LaunchGood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchGood)
{
    ui->setupUi(this);
    ui->price->setMaximum(100000000);
    ui->number->setMinimum(0);
    ui->price->setMinimum(0);
    ui->number->setMaximum(100000000);

}

LaunchGood::~LaunchGood()
{
    delete ui;
}

QString LaunchGood::getName()
{
    return ui->name->text();
}

QString LaunchGood::getDescription()
{
    return ui->description->toPlainText();
}
float LaunchGood::getPrice()
{
    return ui->price->value();
}
int LaunchGood::getNumber()
{
    return ui->number->value();
}

void LaunchGood::Refresh()
{
    ui->name->clear();
    ui->description->clear();
    ui->price->clear();
    ui->number->cleanText();
}

void LaunchGood::on_pushButton_2_clicked()
{
    this->reject();
}

void LaunchGood::on_pushButton_clicked()
{
    if(this->getName()==""||this->getNumber()==0||this->getPrice()<=0)
    {
        //输入不合法
        QMessageBox::warning(this, tr("Warning"), tr("Information error!"),QMessageBox::Ok);

    }
    else if(this->getName()!=""&&this->getNumber()!=0&&this->getPrice()>0) this->accept();
}

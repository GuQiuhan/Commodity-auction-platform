#include "prepare.h"
#include "ui_prepare.h"
#include <QMessageBox>

extern int mode;

Prepare::Prepare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prepare)
{
    ui->setupUi(this);
}

Prepare::~Prepare()
{
    delete ui;
}

void Prepare::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->checkState()) mode=1;
}



void Prepare::on_checkBox_2_stateChanged(int arg1)
{
    if(ui->checkBox_2->checkState()) mode=2;
}

void Prepare::on_commandLinkButton_clicked()
{
    if(ui->checkBox->checkState()&&!ui->checkBox_2->checkState())
    {
        mode=1;
        this->accept();
    }
    else if(ui->checkBox_2->checkState()&&!ui->checkBox->checkState())
    {
        mode=2;
        this->accept();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Must choose ONE combox!"),QMessageBox::Ok);
    }
}

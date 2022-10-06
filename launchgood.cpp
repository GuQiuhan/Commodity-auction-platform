#include "launchgood.h"
#include "ui_launchgood.h"

LaunchGood::LaunchGood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchGood)
{
    ui->setupUi(this);
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

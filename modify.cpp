#include "modify.h"
#include "ui_modify.h"
#include "list.h"
#include <QMessageBox>

extern List<Good> goods;

Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}


void Modify::Init(User& u)//初始化，添加选项
{
    this->u=u;

    Node<Good>* tmp=u.getSellerGood().gethead();

    ui->comboBox->addItem("Choose···");
    while(tmp!=NULL)
    {
        ui->comboBox->addItem(tmp->t.getID());
        tmp=tmp->next;
    }

    //qDebug()<<"init"<< endl;

}

void Modify::on_comboBox_currentTextChanged(const QString &arg1)//选择了一个要修改的商品
{
/**
  新技术！！可以主观设置窗口的部件中的内容
**/
    if(arg1!="Choose···")
    {
        Node<Good> * tmp=u.getSellerGood().gethead();
        while(1)
        {
            if(tmp->t.getID()==arg1) break;
            tmp=tmp->next;
        }
        ui->name->setText(tmp->t.getName());
        ui->price->setValue(tmp->t.getprice());
        ui->number->setValue(tmp->t.getNumber());
        ui->description->setText(tmp->t.getDescription());

    }
}

void Modify::on_pushButton_2_clicked()
{
    this->close();
}

void Modify::on_pushButton_clicked()
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "Tip", "Are you sure to modify?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    else
    {
        if(ui->name->text()==""||ui->price->value()<=0||ui->number->value()<=0)//修改不合法
        {
            QMessageBox::warning(this, tr("Warning"), tr("Information error!"),QMessageBox::Ok);


        }
        else
        {
            QMessageBox::information(this, "Title", "Modify Successfully!");//提示成功
            this->accept();//返回accepted值
        }
    }

}

QString Modify::getName()
{
    return ui->name->text();
}
float Modify::getPrice()
{
    return ui->price->value();
}
int Modify::getNumber()
{
    return ui->number->value();
}
QString Modify::getDescription()
{
    return ui->description->toPlainText();
}
QString Modify::getID()
{
    return ui->comboBox->currentText();
}

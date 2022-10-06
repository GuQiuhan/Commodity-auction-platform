#include "buyer.h"
#include "ui_buyer.h"
#include "list.h"
#include "search.h"
#include <QStandardItemModel>

extern List<Good> goods;
extern QString content;//全局变量，用来传输搜索框中的内容//这里可以改进,用函数调用来解决


Buyer::Buyer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);
}

Buyer::~Buyer()
{
    delete ui;
}

void Buyer::Init(QString name,User u)
{
    ui->label->setText(name+" as a BUYER:");
    this->u=u;

}

void Buyer::on_comboBox_currentTextChanged(const QString &arg1)
{
   if(ui->comboBox->currentText()=="Check Commodities")
    {
        this->checkCommodities();
    }
    else if(ui->comboBox->currentText()=="Buy Commodities")
    {
        this->buyCommodities();
    }
    else if(ui->comboBox->currentText()=="Search Commodities")
    {
        this->searchCommodities();
    }
    else if(ui->comboBox->currentText()=="Check My Orders")
    {
        this->checkOrders();
    }
    else if(ui->comboBox->currentText()=="Back")
    {
        //是否要在此时返回数据并保存文件？
        this->close();
    }
}

void Buyer::checkCommodities()
{

    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Good> * cur=goods.gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<goods.getLen();++i){
        if(cur->t.getState()==false) continue;//不在售的商品
        item = new QStandardItem(cur->t.getID());//括号里面是QString即可
        model->setItem(i,0,item);
        item = new QStandardItem(cur->t.getName());
        model->setItem(i,1,item);
        item = new QStandardItem(QString::number(cur->t.getprice(),'f',1));//float类型保留一位转为QString
        model->setItem(i,2,item);
        item = new QStandardItem(cur->t.getDate());//括号里面是QString即可
        model->setItem(i,3,item);
        item = new QStandardItem(cur->t.getSid());
        model->setItem(i,4,item);
        item = new QStandardItem(QString::number(cur->t.getNumber()));
        model->setItem(i,5,item);
        QString str=cur->t.getState()==1?"On Sale":"Off sale";
        item = new QStandardItem(str);
        model->setItem(i,6,item);
        cur=cur->next;
    }

    ui->tableView->setModel(model);
    ui->tableView->show();


}
void Buyer::checkOrders()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Order ID,Commodity ID,Price,Number,Trade Time,Seller ID,Buyer ID").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Order> * cur=this->u.getBuyerOrder().gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<this->u.getBuyerOrder().getLen();++i){
        item = new QStandardItem(cur->t.getOid());//括号里面是QString即可
        model->setItem(i,0,item);
        item = new QStandardItem(cur->t.getCid());
        model->setItem(i,1,item);
        item = new QStandardItem(QString::number(cur->t.getprice(),'f',1));//float类型保留一位转为QString
        model->setItem(i,2,item);
        item = new QStandardItem(QString::number(cur->t.getNumber()));//括号里面是QString即可
        model->setItem(i,3,item);
        item = new QStandardItem(cur->t.getDate());
        model->setItem(i,4,item);
        item = new QStandardItem(cur->t.getSid());
        model->setItem(i,5,item);
        item = new QStandardItem(cur->t.getBid());
        model->setItem(i,6,item);
        cur=cur->next;
    }


    ui->tableView->setModel(model);
    ui->tableView->show();

}


void Sear(List<Good>& ans, QString content)
{
    Node<Good>* cur=goods.gethead();
    for(int i=0; i<goods.getLen(); ++i)
    {
        if(Match(cur->t.getName(),content)&&cur->t.getState())//模糊搜索&判断是否在售
        {
            Good tmp(cur->t);
            ans.push_back(tmp);
        }
        cur=cur->next;
    }
}

void Buyer::searchCommodities()
{
    class Search s;
    s.exec();
    //两个窗口之间的传值content


    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    List<Good> result;
    Sear(result, content);//搜索，结果放在result里面

    Node<Good> * cur=goods.gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<result.getLen();++i){
        item = new QStandardItem(cur->t.getID());//括号里面是QString即可
        model->setItem(i,0,item);
        item = new QStandardItem(cur->t.getName());
        model->setItem(i,1,item);
        item = new QStandardItem(QString::number(cur->t.getprice(),'f',1));//float类型保留一位转为QString
        model->setItem(i,2,item);
        item = new QStandardItem(cur->t.getDate());//括号里面是QString即可
        model->setItem(i,3,item);
        item = new QStandardItem(cur->t.getSid());
        model->setItem(i,4,item);
        item = new QStandardItem(QString::number(cur->t.getNumber()));
        model->setItem(i,5,item);
        QString str=cur->t.getState()==1?"On Sale":"Off sale";
        item = new QStandardItem(str);
        model->setItem(i,6,item);
        cur=cur->next;
    }

    ui->tableView->setModel(model);
    ui->tableView->show();

}

void Buyer::buyCommodities()
{

}

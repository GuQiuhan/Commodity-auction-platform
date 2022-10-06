#include "buygood.h"
#include "ui_buygood.h"
#include <QStandardItemModel>
extern List<Good> goods;
extern List<Order> orders;
extern List<User> users;


BuyGood::BuyGood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyGood)
{
    ui->setupUi(this);
}

BuyGood::~BuyGood()
{
    delete ui;
}

void BuyGood::Init(User& u)
{
    this->u=u;
    ui->balance->setText("Your balance: "+QString("%1").arg(u.getBal()));

    //表格中展示商品
    this->checkCommodities();

    //下拉框中展示商品ID
    Node<Good>* tmp=goods.gethead();
    ui->comboBox->addItem("Choose···");
    while(tmp!=NULL)
    {
        if(tmp->t.getState()==false) continue;
        ui->comboBox->addItem(tmp->t.getID());
        tmp=tmp->next;
    }

}

void BuyGood::checkCommodities()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Good> * cur=goods.gethead();//买家只能看见所有在售的商品

    QStandardItem* item = 0;
    for(int i = 0;i<goods.getLen();++i){
        if(cur->t.getState()==false) continue;//不在售的商品不展示
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
        item = new QStandardItem(cur->t.getDescription());//加入描述
        model->setItem(i,6,item);
        QString str=cur->t.getState()==1?"On Sale":"Off sale";
        item = new QStandardItem(str);
        model->setItem(i,7,item);
        cur=cur->next;
    }

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


User& BuyGood::getUser()
{
    return this->u;
}

void BuyGood::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1!="Choose···")
    {
        //待写...
        Node<Good> * tmp=goods.gethead();
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

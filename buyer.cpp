#include "buyer.h"
#include "ui_buyer.h"
#include "list.h"
#include "search.h"
#include "buygood.h"
#include <QStandardItemModel>
#include "auctionbuygood.h"
#include <QTimer>

extern List<Good> goods;
extern List<User> users;

//extern QString content;//全局变量，用来传输搜索框中的内容//这里可以改进,用函数调用来解决


Buyer::Buyer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);
    //不断更新数据实体
    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(2000); // 每2s刷新一次
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
       //this->checkOrders();//更新订单
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
        //返回上一级时将数据实体更新给上一级
        this->close();
    }
}

void Buyer::checkCommodities()
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
void Buyer::checkOrders()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Order ID,Commodity ID,Price,Number,Trade Time,Seller ID,Buyer ID").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Order> * cur=this->u.getBuyerOrder().gethead();//买家只能看见自己购买的订单

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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


/**
 记录一下这里遇到的问题：
这里的函数不可以再命名为Search，为了防止和adminui.cpp中的search函数同名同参数而产生重复定义的问题
**/
void Sear(List<Good>& ans, QString content)//时刻注意要用引用！
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
    Sear(result, s.getContent());//搜索，结果放在result里面

    Node<Good> * cur=result.gethead();

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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void Buyer::buyCommodities()
{
    /**
    BuyGood bg;//增加一个抽象层专门用来买商品
    bg.Init(this->u);
    bg.exec();
    this->u=bg.getUser();//更新此数据实体
    **/
    AuctionBuyGood a;
    a.Init(this->u);
    //cout<< "here"<<endl;
    a.exec();
}


User& Buyer::getUser()
{
    return this->u;
}


void Buyer::handleTimeout()//不断更新数据实体
{
    Node<User>* tmp=users.gethead();
    while(tmp!=NULL)
    {
        if(tmp->t.getid()==this->getUser().getid())
        {
            break;
        }
        tmp=tmp->next;
    }

    this->u=tmp->t;

    cout<< "success update buyer.user"<<endl;
}


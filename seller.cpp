#include "seller.h"
#include "order.h"
#include "ui_seller.h"
#include "launchgood.h"
#include "modify.h"
#include "remove.h"
#include <QString>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTimer>

extern List<Good> goods;
extern List<User> users;
extern QString removeContent;//全局变量，此处表示要移除的商品id

Seller::Seller(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
    //不断更新数据实体
    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(2000); // 每2s刷新一次

}

Seller::~Seller()
{
    delete ui;
}

void Seller::Init(QString name,User& u)
{
    ui->label->setText(name +" as a SELLER:");
    this->u=u;
}

void Seller::on_comboBox_currentTextChanged(const QString &arg1)
{

/**
  新技术！！通过exec()来实现两个窗口之间的通信，窗口之间的数据传输可以通过子窗口的函数获取，主窗口只需要调用函数即可
**/
    if(ui->comboBox->currentText()== "Launch Commodities")
    {
        this->LaunchCommodities();
        this->checkCommodities();

    }
    else if(ui->comboBox->currentText()== "Check My Commodities")
    {
        this->checkCommodities();

    }
    else if(ui->comboBox->currentText()== "Modify My Commodities")
    {
        this->ModifyCommodities();
        this->checkCommodities();//modify之后重新check
    }
    else if(ui->comboBox->currentText()== "Remove Commodities")
    {
        this->removeCommodities();


    }
    else if(ui->comboBox->currentText()== "Check My Orders")
    {
        this->checkOrders();

    }
    else if(ui->comboBox->currentText()== "Back")
    {

        this->close();
    }

}

void Seller::LaunchCommodities()
{
    LaunchGood l;
    int res=l.exec();
    if(res==QDialog::Rejected) l.close();//不发布商品
    else
    {
        while(res==QDialog::Accepted)
        {
            if(l.getName()==""||l.getNumber()==0||l.getPrice()<=0)
            {
                //输入不合法
                QMessageBox::warning(this, tr("Warning"), tr("Information error!"),QMessageBox::Ok);
                res=l.exec();
                //清零
            }
            else
            {
                break;

            }

        }

        Good tmp(l.getName(),l.getPrice(),l.getNumber(),l.getDescription(),u.getid());
        u.addGood(tmp);//更新ui界面中的实体数据用户
        goods.push_back(tmp);//加入商品txt
        users.update(u);//更新用户链表
        QMessageBox::information(this, "Title", "Launch Successfully!");//提示成功
    }

}

void Seller::checkCommodities()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Good> * cur=this->u.getSellerGood().gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<this->u.getSellerGood().getLen();++i){
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
        item = new QStandardItem(cur->t.getDescription());
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

void Seller::checkOrders()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Order ID,Commodity ID,Price,Number,Trade Time,Seller ID,Buyer ID").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Order> * cur=this->u.getSellerOrder().gethead();

    //qDebug()<<this->u.getSellerGood().getLen()<< endl;

    QStandardItem* item = 0;
    for(int i = 0;i<this->u.getSellerOrder().getLen();++i){
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


void Seller::removeCommodities()
{
    //调用删除窗口
    Remove r;
    r.exec();

    if(r.getRemoveContent()!="")//说明不是取消键
    {
        //删除商品
        Node<Good>* tmp=this->u.getSellerGood().gethead();
        bool flag=false;
        for(int i=0; i<this->u.getSellerGood().getLen(); ++i)
        {
            if(tmp->t.getID()==r.getRemoveContent()&&tmp->t.getState())//找到了要删除的
            {
                flag=true;
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "", "Sure to remove?",QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    //更新数据实体
                    tmp->t.setRemoveState();
                    //更新users
                    users.update(this->u);
                    //更新goods
                    Node<Good>* x=goods.gethead();
                    while(x&&x->t.getID()!=tmp->t.getID()) x=x->next;
                    if(x) x->t.setRemoveState();//找到相应商品并下架,一般都能找到
                    QMessageBox::information(this, "Title", "Remove Successfully!");//提示成功

                    break;
                }
                else break;
            }
            else if(tmp->t.getID()==r.getRemoveContent()&&tmp->t.getState()==false)//商品已被下架
            {
                flag=true;
                QMessageBox::warning(this, tr("Warning"), tr("The commodity has been off sale!"),QMessageBox::Ok);
            }
            tmp=tmp->next;
        }

        if(!flag)
        {
            QMessageBox::warning(this, tr("Warning"), tr("The commodity ID doesn't exist!"),QMessageBox::Ok);
        }
    }
}

void Seller::ModifyCommodities()
{
    Modify m;
    //qDebug()<<"here!" << endl;
    m.Init(this->u);
    int res=m.exec();
    if(res==QDialog::Rejected) m.close();//不修改商品
    else
    {
        Node<Good> * tmp=u.getSellerGood().gethead();
        while(tmp)
        {
            if(tmp->t.getID()==m.getID()) break;
            tmp=tmp->next;
        }
        //更新数据实体

        tmp->t.modify(m.getName(),m.getPrice(),m.getNumber(),m.getDescription());
        this->u.UpdateSellGood(tmp->t);
        //修改users
        users.update(this->u);
        //修改goods
        goods.update(tmp->t);
    }
}


User& Seller::getUser()
{
    return this->u;
}


void Seller::handleTimeout()//不断更新数据实体
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

    cout<< "success update seller.user"<<endl;
}

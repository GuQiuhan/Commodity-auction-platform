#include "adminui.h"
#include "ui_adminui.h"
#include <QStandardItemModel>
#include "logindlg.h"
#include "search.h"
#include "list.h"
#include "user.h"
#include "good.h"
#include "order.h"
#include "search.h"
#include "remove.h"
#include <QMessageBox>

extern List<User> users;
extern List<Good> goods;
extern List<Order> orders;

//extern QString content;//全局变量，用来传输搜索框中的内容
//extern QString removeContent;//全局变量，用来传输要删除的用户/商品

AdminUI::AdminUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminUI)
{
    ui->setupUi(this);
}

AdminUI::~AdminUI()
{
    delete ui;
}

void AdminUI::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentText()== "Check Commodities")
    {

        this->checkCommodities();

    }
    else if(ui->comboBox->currentText()== "Check Users")
    {

        this->checkUsers();
    }
    else if(ui->comboBox->currentText()== "Check Orders")
    {

        this->checkOrders();

    }
    else if(ui->comboBox->currentText()== "Search Commodities")
    {

        this->searchCommodities();

    }
    else if(ui->comboBox->currentText()== "Remove Commodities")
    {

        this->removeCommodities();
        //重新展示商品
        this->checkCommodities();

    }

    else if(ui->comboBox->currentText()== "Remove Users")
    {

        this->removeUsers();
        //重新展示用户
        this->checkUsers();
    }
    else if(ui->comboBox->currentText()== "Log Out")
    {
        LoginDlg d;
        this->close();
        d.exec();

    }


}

void Search(List<Good>& ans, QString content)
{
    Node<Good>* cur=goods.gethead();
    for(int i=0; i<goods.getLen(); ++i)
    {
        if(Match(cur->t.getName(),content))//逐条判断
        {
            Good tmp(cur->t);
            ans.push_back(tmp);
        }
        cur=cur->next;
    }
}


void AdminUI::checkCommodities()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Good> * cur=goods.gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<goods.getLen();++i){
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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格不允许编辑


}
void AdminUI::checkUsers()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("User ID,Name,Contact,Address,Balance,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<User> * cur=users.gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<users.getLen();++i){
        item = new QStandardItem(cur->t.getid());//括号里面是QString即可
        model->setItem(i,0,item);
        item = new QStandardItem(cur->t.getName());
        model->setItem(i,1,item);
        item = new QStandardItem(cur->t.getContact());//float类型保留一位转为QString
        model->setItem(i,2,item);
        item = new QStandardItem(cur->t.getAddr());//括号里面是QString即可
        model->setItem(i,3,item);
        item = new QStandardItem(QString::number(cur->t.getBal(),'f',1));
        model->setItem(i,4,item);

        QString str=cur->t.getState()==1?"active":"inactive";
        item = new QStandardItem(str);

        model->setItem(i,5,item);
        cur=cur->next;
    }


    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void AdminUI::checkOrders()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Order ID,Commodity ID,Price,Number,Trade Time,Seller ID,Buyer ID").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Order> * cur=orders.gethead();

    QStandardItem* item = 0;
    for(int i = 0;i<orders.getLen();++i){
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

void AdminUI::searchCommodities()
{
    class Search s;
    s.exec();
    //两个窗口之间的传值content


    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    List<Good> result;
    Search(result, s.getContent());//搜索，结果放在result里面

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
void AdminUI::removeCommodities()
{
    //调用删除窗口
    Remove r;
    r.exec();

    if(r.getRemoveContent()!="")//说明不是取消键
    {
        //删除商品
        Node<Good>* tmp=goods.gethead();
        bool flag=false;
        for(int i=0; i<goods.getLen(); ++i)
        {
            if(tmp->t.getID()==r.getRemoveContent()&&tmp->t.getState())//找到了要删除的
            {
                flag=true;
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "", "Sure to remove?",QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    //修改goods
                    tmp->t.setRemoveState();
                    //修改users中的卖家
                    Node<User>* u=users.gethead();
                    while(u&&u->t.getid()!=tmp->t.getSid()) u=u->next;//找到卖家,一般都能找到
                    if(u) u->t.UpdateSellGood(tmp->t);//更新商品信息

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
void AdminUI::removeUsers()
{
    //调用删除窗口
    Remove r;
    r.exec();

    if(r.getFlag())
    {
        if(r.getRemoveContent()!="")//说明不是取消键
        {
            //删除用户
            Node<User>* tmp=users.gethead();
            bool flag=false;
            for(int i=0; i<users.getLen(); ++i)
            {
               // qDebug()<< tmp->t.getid()<< " "<< removeContent<< endl;

                if(tmp->t.getid()==r.getRemoveContent())//找到了要删除的
                {
                    flag=true;
                    QMessageBox::StandardButton reply;
                    reply = QMessageBox::question(this, "", "Sure to remove?",QMessageBox::Yes|QMessageBox::No);
                    if (reply == QMessageBox::Yes)
                    {
                        users.del(i);//删除pos==i的用户
                        //更新goods文件,下架相应商品
                        Node<Good>* g=goods.gethead();
                        while(g)
                        {
                            if(g->t.getSid()==tmp->t.getid())
                            {
                                g->t.setRemoveState();
                            }
                            g=g->next;
                        }

                        QMessageBox::information(this, "Title", "Remove Successfully!");//提示成功

                    }
                    break;
                }

                tmp=tmp->next;
            }

            if(!flag)
            {
                QMessageBox::warning(this, tr("Warning"), tr("The User ID doesn't exist!"),QMessageBox::Ok);
            }
        }
    }
}

#include "buygood.h"
#include "ui_buygood.h"
#include <QStandardItemModel>
#include <QMessageBox>
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


//此函数只实现基本的购买
void BuyGood::on_comboBox_currentTextChanged(const QString &arg1)//选择了一个商品，此时显示该商品的数量
{
    if(arg1!="Choose···")//选择了一个要买的商品
    {
        Node<Good> * tmp=goods.gethead();//在商品列表中找到要买的商品
        while(1)
        {
            if(tmp->t.getID()==arg1) break;
            tmp=tmp->next;
        }
        //显示该商品
        QStandardItemModel* model = new QStandardItemModel();
        QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
        model->setHorizontalHeaderLabels(labels);
        QStandardItem* item = 0;
        item = new QStandardItem(tmp->t.getID());//括号里面是QString即可
        model->setItem(0,0,item);
        item = new QStandardItem(tmp->t.getName());
        model->setItem(0,1,item);
        item = new QStandardItem(QString::number(tmp->t.getprice(),'f',1));//float类型保留一位转为QString
        model->setItem(0,2,item);
        item = new QStandardItem(tmp->t.getDate());//括号里面是QString即可
        model->setItem(0,3,item);
        item = new QStandardItem(tmp->t.getSid());
        model->setItem(0,4,item);
        item = new QStandardItem(QString::number(tmp->t.getNumber()));
        model->setItem(0,5,item);
        item = new QStandardItem(tmp->t.getDescription());//加入描述
        model->setItem(0,6,item);
        QString str=tmp->t.getState()==1?"On Sale":"Off sale";
        item = new QStandardItem(str);
        model->setItem(0,7,item);

        ui->tableView->setModel(model);
        ui->tableView->show();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格不允许编辑


        //设置数量
        ui->spinBox->setMaximum(tmp->t.getNumber());

    }
}

void BuyGood::on_pushButton_2_clicked()//确定修改
{
    if(ui->comboBox->currentText()!="Choose···"&&ui->spinBox->value()!=0)
    {
        Node<Good> * tmp=goods.gethead();//在商品列表中找到要买的商品
        while(1)
        {
            if(tmp->t.getID()==ui->comboBox->currentText()) break;
            tmp=tmp->next;
        }
        //检查余额是否够
        if(tmp->t.getprice()*ui->spinBox->value()>this->u.getBal())
        {
            QMessageBox::warning(this, tr("Warning"), tr("Balance not enough!"),QMessageBox::Ok);
        }
        else
        {

            //修改商品数量goods
            //此处已经保证了数量是一定够的
            tmp->t.decrease(ui->spinBox->value());

            //修改orders
            Order o(tmp->t.getID(),tmp->t.getprice(),ui->spinBox->value(),tmp->t.getSid(),this->u.getid());
            orders.push_back(o);

            //修改buyer信息
            this->u.addBuyGood(tmp->t);
            this->u.addBuyOrder(o);
            this->u.decreaseBal(tmp->t.getprice()*ui->spinBox->value());
            users.update(this->u);//修改users
            //修改seller信息,直接在users里修改
            Node<User> * s=users.gethead();//在商品列表中找到要买的商品
            while(1)
            {
                if(s->t.getid()==tmp->t.getSid()) break;
                s=s->next;
            }
            s->t.addSellOrder(o);
            s->t.inreaseBal(tmp->t.getprice()*ui->spinBox->value());


            if(tmp->t.getNumber()==0)//商品被买光了，要下架
            {
                //修改user
                s->t.delGood(tmp->t);
                users.update(u);
                //修改goods
                Node<Good> *g=goods.gethead();
                int i=0;
                for(; i<goods.getLen();g=g->next,i++)
                {
                    if(g->t==tmp->t) break;
                }
                goods.del(i);

            }

            //如果买的是自己的东西
            if(s->t.getid()==this->u.getid())
            {
                this->u.inreaseBal(tmp->t.getprice()*ui->spinBox->value());//本数据实体余额也要增加
                if(tmp->t.getNumber()==0)//商品被买光了，要下架
                {
                    //修改本数据实体
                    this->u.delGood(tmp->t);

                }
            }
            QMessageBox::information(this, "Title", "Buy Success!");//提示成功
            ui->balance->setText("Your balance: "+QString("%1").arg(u.getBal()));//重新展示余额
        }
        this->checkCommodities();//重新展示商品
        ui->spinBox->clear();//清空选项
        ui->comboBox->setCurrentIndex(0);




    }
}

void BuyGood::on_pushButton_clicked()
{
    this->close();
}

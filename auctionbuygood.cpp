#include "auctionbuygood.h"
#include "ui_auctionbuygood.h"
#include "addfunction.h"
#include <QStandardItemModel>
#include <QMessageBox>

extern List<Good> goods;
extern List<Order> orders;
extern List<User> users;
extern List<Auction> auctions;

AuctionBuyGood::AuctionBuyGood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuctionBuyGood)
{
    ui->setupUi(this);
    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(2000); // 每2s刷新一次
}

AuctionBuyGood::~AuctionBuyGood()
{
    delete ui;
}

void AuctionBuyGood::Init(User& u)
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
        if(!tmp->t.getState())
        {

            tmp=tmp->next;
            continue;
        }
        ui->comboBox->addItem(tmp->t.getID());
        tmp=tmp->next;
    }

}

void AuctionBuyGood::checkCommodities()
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Commodity ID,Name,Price,Launch Time,Seller ID,Number,Description,State").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Good> * cur=goods.gethead();//买家只能看见所有在售的商品
    int i=0;
    QStandardItem* item = 0;
    while(cur){
        if(cur->t.getState()==false)
        {
            cur=cur->next;
            continue;//不在售的商品不展示
        }
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
        i++;
    }

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

User& AuctionBuyGood::getUser()
{
    return this->u;
}

void AuctionBuyGood::on_comboBox_currentTextChanged(const QString &arg1)
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
        //设置报价区间
        ui->doubleSpinBox->setMinimum(tmp->t.getprice());
        ui->doubleSpinBox->setMaximum(1000000.0);
    }
}

void AuctionBuyGood::on_pushButton_clicked()
{
    this->close();
}

void AuctionBuyGood::on_pushButton_2_clicked()
{
    this->BuyGood();
}

void AuctionBuyGood::BuyGood()
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
            //创建竞拍订单
            //修改orders
            Order o(tmp->t.getID(),ui->doubleSpinBox->value(),ui->spinBox->value(),tmp->t.getSid(),this->u.getid());
            Auction a(o);
            auctions.push_back(a);

            //修改buyer信息
            this->u.decreaseBal(ui->doubleSpinBox->value()*ui->spinBox->value());
            users.update(this->u);//修改users

            QMessageBox::information(this, "Title", "Success! Please waiting for the auction's result!");//提示成功
            ui->balance->setText("Your balance: "+QString("%1").arg(u.getBal()));//重新展示余额
        }
        this->checkAuctions();//重新展示竞拍订单
        ui->spinBox->setValue(0);//清空选项
        ui->comboBox->setCurrentIndex(0);
        ui->doubleSpinBox->setValue(0);//清空选项




    }

}

void AuctionBuyGood::checkAuctions()//展示自己的拍卖记录
{
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Order ID,Commodity ID,Price,Number,Trade Time,Seller ID,Buyer ID,Auction Time").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    Node<Auction> * cur=auctions.gethead();//买家只能看见自己购买的订单

    QStandardItem* item = 0;
    int i=0;
    while(cur!=NULL)
    {
        if(cur->t.getOrder().getBid()==this->getUser().getid())
        {
            item = new QStandardItem(cur->t.getOrder().getOid());//括号里面是QString即可
            model->setItem(i,0,item);
            item = new QStandardItem(cur->t.getOrder().getCid());
            model->setItem(i,1,item);
            item = new QStandardItem(QString::number(cur->t.getOrder().getprice(),'f',1));//float类型保留一位转为QString
            model->setItem(i,2,item);
            item = new QStandardItem(QString::number(cur->t.getOrder().getNumber()));//括号里面是QString即可
            model->setItem(i,3,item);
            item = new QStandardItem(cur->t.getOrder().getDate());
            model->setItem(i,4,item);
            item = new QStandardItem(cur->t.getOrder().getSid());
            model->setItem(i,5,item);
            item = new QStandardItem(cur->t.getOrder().getBid());
            model->setItem(i,6,item);
            item = new QStandardItem(cur->t.getTime());
            model->setItem(i,7,item);
            i++;
        }
        cur=cur->next;
    }


    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);




}

void AuctionBuyGood::handleTimeout()//不断更新数据实体
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

    cout<< "success update buyer"<<endl;
}

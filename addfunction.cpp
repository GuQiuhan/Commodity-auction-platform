#include "addfunction.h"
#include "ui_addfunction.h"
#include <QTime>

extern List<Auction> auctions;
extern List<Good> goods;
extern List<Order> orders;
extern List<User> users;

#define AuctionTime 180  //规定的拍卖时间，单位：秒，180秒即3分钟

AddFunction::AddFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddFunction)
{
    //ui->setupUi(this);//不展示界面

    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(30000); // 300000毫秒，相当于30秒，竞拍计时器每隔30秒扫描一次
}

AddFunction::~AddFunction()
{
    //delete ui;
}

void AddFunction::handleTimeout()
{

    //反复扫描auctions结构，处理订单
    QDateTime currentTime= QDateTime::currentDateTime();//获取系统当前的时间
    Node<Auction>* tmp=auctions.gethead();
    while(tmp!=NULL)//挨个拍卖订单判断
    {
        bool delflag=true;
        QString cid=tmp->t.getOrder().getCid();
        //QString oid=tmp->t.getOrder().getOid();

        QDateTime beginTime;
        int number;
        Node<Good>* i;
        for(i=goods.gethead();i!=NULL; i=i->next)
        {
            if(i->t.getID()==cid)
            {
                beginTime=QDateTime::fromString(i->t.getDate(), "yyyy-MM-dd hh:mm:ss");
                number=i->t.getNumber();
                break;
            }
        }//找到此商品的发布日期和数量
        //qDebug()<<beginTime;
        //qDebug()<<currentTime;
        //qDebug()<<beginTime.secsTo(currentTime);

        if(beginTime.secsTo(currentTime)>AuctionTime)//超过了拍卖时间
        {
            qDebug()<< tmp->t.getOrder().getCid()<<" finish auction!";
            //找出所有这个商品的拍卖订单,
           Order final=tmp->t.getOrder();
           for(Node<Auction>* i=tmp;i!=NULL; i=i->next)//找出报价最高者
           {
               if(i->t.getOrder().getCid()==cid&&i->t.getOrder().getprice()>tmp->t.getOrder().getprice())//同一商品报价更高者
               {
                   final=i->t.getOrder();
                   delflag=false;
               }
               else if(i->t.getOrder().getCid()==cid&&i->t.getOrder().getprice()==tmp->t.getOrder().getprice())
               {
                   //报价相同的话则时间早的人
                   if(QDateTime::fromString(i->t.getTime(), "yyyy-MM-dd hh:mm:ss").secsTo(QDateTime::fromString(tmp->t.getTime(), "yyyy-MM-dd hh:mm:ss"))>0)
                   {
                       final=i->t.getOrder();
                       delflag=false;
                   }
               }

           }

           //将final加入订单
           orders.push_back(final);
           //修改seller信息
           Node<User> * s=users.gethead();//在商品列表中找到要买的商品
           while(1)
           {
               if(s->t.getid()==final.getSid()) break;
               s=s->next;
           }
           s->t.addSellOrder(final);
           s->t.inreaseBal(final.getprice()*final.getprice());

           //修改buyer信息
           Node<User> * b=users.gethead();//在商品列表中找到要买的商品
           while(1)
           {
               if(b->t.getid()==final.getBid()) break;
               b=b->next;
           }
           b->t.addBuyGood(i->t);
           b->t.addBuyOrder(final);
           //b->t.decreaseBal(final.getprice()*final.getprice());

           //修改good
           i->t.decrease(final.getNumber());

           //商品被卖光了
           if(i->t.getNumber()==0)
           {
               //修改user
               s->t.delGood(i->t);
               //修改goods
               Node<Good> *g=goods.gethead();
               int in=0;
               for(; in<goods.getLen();g=g->next,in++)
               {
                   if(g->t==i->t) break;
               }
               goods.del(in);
               break;
           }

           //删除所有的相关auction
           //先将tmp移动到安全位置
           while(tmp!=NULL&&tmp->t.getOrder().getCid()==cid) tmp=tmp->next;
           //删除所有
           int i=0;
           for(Node<Auction>* cur=auctions.gethead(); cur!=NULL;)
           {
               if(cur->t.getOrder().getCid()==cid)
               {
                   //将每个拍卖的钱都归还给用户
                   //修改buyer信息
                   Node<User> * b=users.gethead();//在商品列表中找到要买的商品
                   while(1)
                   {
                       if(b->t.getid()==cur->t.getOrder().getBid()) break;
                       b=b->next;
                   }
                   b->t.inreaseBal(cur->t.getOrder().getprice()*cur->t.getOrder().getprice());

                   cur=cur->next;
                   auctions.del(i);
               }
               else
               {
                   i++;
                   cur=cur->next;
               }
           }



        }

        else tmp=tmp->next;

    }

    cout<< "success scanf auction files"<<endl;
}

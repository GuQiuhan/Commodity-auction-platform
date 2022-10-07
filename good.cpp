#include "good.h"
#include "user.h"
#include <QTime>

extern QString GoodID_now;
extern List<Good> goods;

Good::Good()
{

}

Good::Good(const QString id,const QString na, const float p, const int n,const QString d, const QString sellerid,const QString ad,const bool s)
{
    this->ID=id;
    this->name=na;
    this->price=p;
    this->state=s;
    this->number=n;
    this->addDate=ad;
    this->SellerID=sellerid;
    this->description=d;


}

Good::Good(const QString name, const float price,const int number,const QString description,const QString sellerid)//用于发布商品时创建
{
    this->name=name;
    this->price=price;
    this->number=number;
    this->description=description;

    GoodID_now=Add(GoodID_now);

    this->ID="M"+GoodID_now;
    this->SellerID=sellerid;

    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    this->addDate= dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间

    this->state=true;//发布商品时状态是true
}

QString Good::getID()
{
    return this->ID;
}
QString Good::getName()
{
    return this->name;
}

float Good::getprice()
{
    return this->price;
}

int Good::getNumber()
{
    return this->number;
}

QString Good::getSid()
{
    return this->SellerID;

}
QString Good::getDate()
{
    return this->addDate;
}
bool Good::getState()
{
    return this->state;
}

QString Good::getDescription()
{
    return this->description;
}

void Good::modify(QString name, float price, int number, QString des)
{
    this->name=name;
    this->price=price;
    this->number=number;
    this->description=des;

}

bool Good::operator==(const Good& u)//等于操作符重载函数，只要id相同即视为相同
{
    if (u.ID==this->ID)
    {
        return true;
    }
    return false;
}




void Good::operator=(Good const& u)
{
    this->ID=u.ID;
    this->name=u.name;
    this->price=u.price;
    this->state=u.state;
    this->number=u.number;
    this->addDate=u.addDate;
    this->SellerID=u.SellerID;
    this->description=u.description;
}



void Good::setRemoveState()
{
    this->state=false;
}

void Good::decrease(int num)
{
    this->number-=num;
}

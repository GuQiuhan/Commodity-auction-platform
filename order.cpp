#include "order.h"
#include "user.h"
extern QString OrderID_now;
#include <QTime>

Order::Order()
{

}

Order::Order(const QString oid,const QString cid, const float uprice,const int num,QString d,const QString sid,const QString bid)
{
    this->date=d;
    this->number=num;
    this->buyerID=bid;
    this->orderID=oid;
    this->sellerID=sid;
    this->unitPrice=uprice;
    this->commdityID=cid;

}


Order::Order(const QString cid, const float uprice,const int num,const QString sid,const QString bid)
{
    OrderID_now=Add(OrderID_now);
    this->orderID="T"+OrderID_now;

    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    this->date= dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间

    this->number=num;
    this->buyerID=bid;
    this->sellerID=sid;
    this->unitPrice=uprice;
    this->commdityID=cid;

}





void Order::operator=(Order const& u)
{
    this->date=u.date;
    this->number=u.number;
    this->buyerID=u.buyerID;
    this->orderID=u.orderID;
    this->sellerID=u.sellerID;
    this->unitPrice=u.unitPrice;
    this->commdityID=u.commdityID;
}


QString Order::getOid()
{
    return this->orderID;
}
QString Order::getCid()
{
    return this->commdityID;
}
float Order::getprice()
{
    return this->unitPrice;
}
int Order::getNumber()
{
    return this->number;
}
QString Order::getDate()
{
    return this->date;
}
QString Order::getSid()
{
    return this->sellerID;
}
QString Order::getBid()
{
    return this->buyerID;
}

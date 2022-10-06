#include "order.h"

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

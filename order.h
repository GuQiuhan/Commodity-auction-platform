#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QDebug>


class Order
{
private:
    QString orderID;
    QString commdityID;
    float unitPrice;
    int number;
    QString date;
    QString sellerID;
    QString buyerID;

public:
    Order();
    //orderID,commodityID,unitPrice,number,date,sellerID,buyerID
    Order(const QString oid,const QString cid, const float uprice,const int num,QString d,const QString sid,const QString bid);
    Order(const QString cid, const float uprice,const int num,const QString sid,const QString bid);//购买时创建订单


    QString getOid();
    QString getCid();
    float getprice();
    int getNumber();
    QString getDate();
    QString getSid();
    QString getBid();

    void operator=(Order const& u);

    void Print(){}
    void setNumber(int n);
};

#endif // ORDER_H

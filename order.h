#ifndef ORDER_H
#define ORDER_H

#include <QString>


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

    QString getOid();
    QString getCid();
    float getprice();
    int getNumber();
    QString getDate();
    QString getSid();
    QString getBid();

    void operator=(Order const& u);

};

#endif // ORDER_H

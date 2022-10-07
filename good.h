#ifndef GOOD_H
#define GOOD_H
#include <QString>
#include <QDebug>
using namespace std;


class Good
{

private:
    QString ID;
    QString name;
    float price;//精确到小数点后一位
    int number;
    QString description;
    QString SellerID;
    QString addDate;
    bool state;//0表示下架，1表示在售

public:
    Good();
    Good(const QString id,const QString na, const float p, const int n,const QString d, const QString sellerid,const QString ad,const bool s);//用于读入文件时创建
    Good(const QString name, const float price,const int number,const QString description,const QString sellerid);//用于发布商品时创建

    QString getID();
    QString getName();
    float getprice();
    int getNumber();
    QString getSid();
    QString getDate();
    bool getState();
    QString getDescription();
    void modify(QString name, float price, int number, QString des);
    //void remove();//包括文件的修改
    void setRemoveState();//不包括文件的修改
    void decrease(int num);//被买了之后数量减少

    void operator=(Good const& u);
    bool operator==(const Good& u);

    void Print(){qDebug()<<this->ID;}


};

#endif // GOOD_H

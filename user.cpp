#include "user.h"
#include <QString>
#include <QDebug>
extern QString UserID_now;


User::User(const QString n, const QString p)//用于register
{
    UserID_now=Add(UserID_now);

    ID="U"+UserID_now;
    name=n;
    pwd=p;
    balance=0.0;//保留一位小数
    state=0;//初始创建时都为0
    //缺少phoneNumber和address
}

User::User(const QString id, const QString n, const QString p)
{
    ID=id;
    name=n;
    pwd=p;
    balance=0.0;
    state=0;
}

User::User(const QString id,const QString n,const QString p, const QString phone,const QString a,const float b)//用于文件读写
{
    ID=id;
    name=n;
    pwd=p;
    phoneNum=phone;
    addr=a;
    balance=b;
    state=0;
}
void User::operator=(User const& u)//赋值构造函数，有用！
{

    this->ID=u.ID;
    this->pwd=u.pwd;
    this->addr=u.addr;
    this->name=u.name;
    this->state=u.state;
    this->balance=u.balance;
    this->sell=u.sell;
    this->buy=u.buy;
    this->sellOrder=u.sellOrder;
    this->buyOrder=u.buyOrder;
}


bool User::operator==(const User& u)//自定义等于操作符重载，在这里只要求ID一致就可以，用于update函数
{
    if (u.ID==this->ID)
    {
        return true;
    }
    return false;
}

QString Add(QString id)//输出加1的三位数
{
    int num=id.toInt();
    num++;
    QString newID=QString::number(num);
    if(newID.size()==1) newID="00"+newID;//凑成三位数
    else if (newID.size()==2) newID="0"+newID;

    return newID;


}


void User::updateBalance(const float bal)
{
    balance=bal;
}
void User::updatePhonenumber(const QString number)
{
    phoneNum=number;
}
void User::updateAddrees(const QString a)
{
    addr=a;
}

QString User::getName()
{
    return name;
}

QString User::getPwd()
{
    return this->pwd;
}


QString User::getid()
{
    return this->ID;

}
QString User::getContact()
{
    return this->phoneNum;
}
QString User::getAddr()
{
    return this->addr;
}
float User::getBal()
{
    return this->balance;
}
bool User::getState()
{
    return this->state;
}

List<Good>& User::getSellerGood()
{
    return this->sell;
}

List<Good>& User::getBuyerGood()
{
    return this->buy;
}
List<Order>& User::getSellerOrder()
{
    return this->sellOrder;
}
List<Order>& User::getBuyerOrder()
{
    return this->buyOrder;
}


User::User(const User& u)
{
    this->ID=u.ID;
    this->pwd=u.pwd;
    this->addr=u.addr;
    this->name=u.name;
    this->state=u.state;
    this->balance=u.balance;

}

void User::addGood(Good& tmp)//新发布商品
{
    sell.push_back(tmp);
}

void User::UpdateSellGood(Good& g)
{
    this->sell.update(g);
    //同时在list里更新
    //待写
}


void User::UpdateInfo(QString name,QString addr, QString contact,QString bal)
{
    this->name=name;
    this->addr=addr;
    this->balance=bal.toFloat();
    this->phoneNum=contact;
    //同时在list里更新
    //待写
}

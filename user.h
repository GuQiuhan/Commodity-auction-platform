#ifndef USER_H
#define USER_H
#include <QString>
#include "list.h"
#include "good.h"
#include "order.h"
using namespace std;

QString Add(QString id);


class User
{
private:
    QString ID;
    QString name;
    QString pwd;
    QString phoneNum;
    QString addr;
    float balance;//保留一位小数
    bool state;//0表示inactive，1表示active

    List<Good> sell;//作为卖家售卖的商品
    List<Good> buy;//作为买家买的商品
    List<Order> sellOrder;//作为卖家的订单
    List<Order> buyOrder;//作为买家的订单

public:

    User(){};
    User(const QString n, const QString p);
    User(const QString id, const QString n, const QString p);
    User(const QString id,const QString n,const QString p, const QString phone,const QString a,const float b);//用于文件读写的构造函数
    User(const User& u);
    ~User(){};

    void updateBalance(const float bal);
    void updatePhonenumber(const QString number);
    void updateAddrees(const QString a);

    QString getName();
    QString getPwd();
    QString getid();
    QString getContact();
    QString getAddr();
    float getBal();
    bool getState();


    void operator=(User const& u);
    bool operator==(const User& u);

    void addGood(Good& tmp);//新发布商品
    void addBuyGood(Good& tmp);//新买的商品
    void addBuyOrder(Order& tmp);//新买的订单
    void addSellOrder(Order& tmp);//新卖的订单

    List<Good>& getSellerGood();
    List<Good>& getBuyerGood();
    List<Order>& getSellerOrder();
    List<Order>& getBuyerOrder();

    void UpdateSellGood(Good& g);//更新修改后的发布商品
    void UpdateInfo(QString name,QString addr, QString contact,QString bal);



};

#endif // USER_H

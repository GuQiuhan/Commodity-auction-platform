#ifndef ADDFUNCTION_H
#define ADDFUNCTION_H

#include <QWidget>
#include <QTimer>
#include "list.h"
#include "order.h"
#include "user.h"
#include <QDateTime>


class Auction
{
private:
    Order o;//订单
    QString time;//时间

public:
    Auction(){}
    Auction(Order& tmp)
        :o(tmp)
    {
        QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
        this->time= dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间

    }

    Auction(Order& tmp,QString t)
        :o(tmp),time(t)
    {

    }

    Order& getOrder()
    {
        return o;
    }

    QString getTime()
    {
        return time;
    }
};



namespace Ui {
class AddFunction;
}

class AddFunction : public QWidget
{
    Q_OBJECT

public:
    explicit AddFunction(QWidget *parent = nullptr);
    ~AddFunction();

private:
    Ui::AddFunction *ui;
    QTimer* timer;
public slots:
    void handleTimeout();  //超时处理函数

};

#endif // ADDFUNCTION_H

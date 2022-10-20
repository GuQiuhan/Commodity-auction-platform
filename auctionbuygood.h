#ifndef AUCTIONBUYGOOD_H
#define AUCTIONBUYGOOD_H

#include <QDialog>
#include "user.h"

namespace Ui {
class AuctionBuyGood;
}

class AuctionBuyGood : public QDialog
{
    Q_OBJECT

public:
    explicit AuctionBuyGood(QWidget *parent = nullptr);
    ~AuctionBuyGood();

    void Init(User& u);
    void checkCommodities();
    void checkAuctions();
    User& getUser();
    //void PureBuyGood();
    void BuyGood();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
public slots:
    void handleTimeout();  //超时处理函数

private:
    Ui::AuctionBuyGood *ui;
    User u;//数据实体
    QTimer* timer;//计时器，不断更新数据实体信息
};

#endif // AUCTIONBUYGOOD_H

#ifndef BUYGOOD_H
#define BUYGOOD_H

#include <QDialog>
#include "user.h"

namespace Ui {
class BuyGood;
}

class BuyGood : public QDialog
{
    Q_OBJECT

public:
    explicit BuyGood(QWidget *parent = nullptr);
    ~BuyGood();
    void Init(User& u);
    void checkCommodities();
    User& getUser();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::BuyGood *ui;
    User u;//数据实体
};

#endif // BUYGOOD_H

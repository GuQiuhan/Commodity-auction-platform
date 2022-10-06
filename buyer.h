#ifndef BUYER_H
#define BUYER_H

#include <QDialog>
#include <QString>
#include "user.h"

namespace Ui {
class Buyer;
}

class Buyer : public QDialog
{
    Q_OBJECT

public:
    explicit Buyer(QWidget *parent = nullptr);
    ~Buyer();
    void Init(QString name,User u);
    void checkCommodities();
    void checkOrders();
    void buyCommodities();
    void searchCommodities();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Buyer *ui;
    User u;
};

void Sear(List<Good>& ans, QString content);

#endif // BUYER_H

#ifndef SELLER_H
#define SELLER_H

#include <QDialog>
#include <QString>
#include "user.h"

namespace Ui {
class Seller;
}

class Seller : public QDialog
{
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr);
    ~Seller();
    void Init(QString name,User u);

    void checkCommodities();
    void checkOrders();
    void removeCommodities();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Seller *ui;
    User u;
};

#endif // SELLER_H
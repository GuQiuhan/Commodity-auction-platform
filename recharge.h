#ifndef RECHARGE_H
#define RECHARGE_H

#include <QDialog>

namespace Ui {
class Recharge;
}

class Recharge : public QDialog
{
    Q_OBJECT

public:
    explicit Recharge(QWidget *parent = nullptr);
    ~Recharge();

    float getValue();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Recharge *ui;
};

#endif // RECHARGE_H

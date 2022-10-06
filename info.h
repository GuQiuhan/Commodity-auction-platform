#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include "user.h"

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();
    void Init(User& u);
    QString getName();
    QString getAddr();
    QString getContact();
    QString getBal();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Info *ui;
    User u;//数据实体
};

#endif // INFO_H

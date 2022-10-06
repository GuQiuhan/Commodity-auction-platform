#ifndef USERUI_H
#define USERUI_H

#include <QDialog>
#include <QString>
#include "user.h"
#include "seller.h"
#include "buyer.h"
#include "info.h"


namespace Ui {
class UserUI;
}

class UserUI : public QDialog
{
    Q_OBJECT

public:
    explicit UserUI(QWidget *parent = nullptr);
    ~UserUI();
    UserUI(QWidget *parent,User& u);//创建含有user实体数据的ui

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);
    //void receiveData(QString data);  //用来接受传递的信号

private:
    Ui::UserUI *ui;//ui界面
    User user;//数据实体



};

#endif // USERUI_H

#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include "list.h"
#include "user.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    bool Find(List<User>& l,QString name);//用于注册时查找是否重名，是返回true




private slots:
    void on_Register_pushButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H

#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include <user.h>

namespace Ui {
class Modify;
}

class Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();

    void Init(User& u);
    QString getName();
    float getPrice();
    int getNumber();
    QString getDescription();
    QString getID();


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Modify *ui;
    User u;
};

#endif // MODIFY_H

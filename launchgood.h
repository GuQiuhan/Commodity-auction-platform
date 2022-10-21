#ifndef LAUNCHGOOD_H
#define LAUNCHGOOD_H

#include <QDialog>
#include <QString>

namespace Ui {
class LaunchGood;
}

class LaunchGood : public QDialog
{
    Q_OBJECT

public:
    explicit LaunchGood(QWidget *parent = nullptr);
    ~LaunchGood();

    QString getName();
    QString getDescription();
    float getPrice();
    int getNumber();

    void Refresh();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::LaunchGood *ui;
};

#endif // LAUNCHGOOD_H

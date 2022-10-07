#ifndef REMOVE_H
#define REMOVE_H

#include <QDialog>

namespace Ui {
class Remove;
}

class Remove : public QDialog
{
    Q_OBJECT

public:
    explicit Remove(QWidget *parent = nullptr);
    ~Remove();
    QString getRemoveContent();
    bool getFlag();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Remove *ui;
    bool flag;
};

#endif // REMOVE_H

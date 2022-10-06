#ifndef ADMINUI_H
#define ADMINUI_H

#include <QDialog>
#include "list.h"
#include "good.h"

namespace Ui {
class AdminUI;
}

class AdminUI : public QDialog
{
    Q_OBJECT

public:
    explicit AdminUI(QWidget *parent = nullptr);
    ~AdminUI();

    void checkCommodities();
    void checkUsers();
    void checkOrders();
    void searchCommodities();
    void removeCommodities();
    void removeUsers();


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::AdminUI *ui;
};

void Search(List<Good>& ans, QString);


#endif // ADMINUI_H

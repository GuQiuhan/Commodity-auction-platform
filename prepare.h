#ifndef PREPARE_H
#define PREPARE_H

#include <QDialog>

namespace Ui {
class Prepare;
}

class Prepare : public QDialog
{
    Q_OBJECT

public:
    explicit Prepare(QWidget *parent = nullptr);
    ~Prepare();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_commandLinkButton_clicked();

private:
    Ui::Prepare *ui;
};

#endif // PREPARE_H

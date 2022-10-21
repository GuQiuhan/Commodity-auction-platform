#include "userui.h"
#include "ui_userui.h"
#include "logindlg.h"
#include <QDebug>
extern List<User> users;

//extern QString username; //声明外部变量

UserUI::UserUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserUI)
{
    ui->setupUi(this);

    //不断更新数据实体
    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    cout << "here"<<endl;
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(2000); // 每2s刷新一次

    //ui->label_2->setText("Hello! "+ user.getName()+"!"); //对全局变量进行显示


}

UserUI::UserUI(QWidget *parent,User& u) :
    QDialog(parent),
    ui(new Ui::UserUI)
{
    ui->setupUi(this);

    user=u;

    ui->label_2->setText("Hello! "+ user.getName()+"!"); //对全局变量进行显示

    //不断更新数据实体
    timer = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout())); // SLOT填入一个槽函数
    timer->start(2000); // 每2s刷新一次

}

UserUI::~UserUI()
{
    delete ui;
}

void UserUI::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentText()== "I am a SELLER")
    {
        Seller seller;//卖家ui界面
        seller.Init(this->user.getName(),this->user);//填充数据
        seller.exec();
        //此界面未关闭，只是被覆盖了
        this->user=seller.getUser();//更新此界面的数据实体

    }
    else if(ui->comboBox->currentText()== "I am a BUYER")
    {
        Buyer buyer;//买家ui界面
        buyer.Init(this->user.getName(),this->user);
        buyer.exec();
        this->user=buyer.getUser();//更新此界面的数据实体

    }
    else if(ui->comboBox->currentText()== "Personal Info")
    {
        Info info;
        info.Init(this->user);
        info.exec();
        this->user.UpdateInfo(info.getName(),info.getAddr(),info.getContact(),info.getBal());//对本界面的数据实体更新
        //更新users
        //qDebug() << "hereinfo"<<endl;
        //qDebug()<<user.getid()<<endl;

        //debug:展示users的内容
        /**Node<User>* de=users.gethead();
        while(de)
        {
            qDebug()<<de->t.getid();
            qDebug()<<de->t.getName();
            de=de->next;
        }**/

        users.update(this->user);

        //debug:再次展示users的内容
        /** de=users.gethead();
        while(de)
        {
            qDebug()<<de->t.getid();
            qDebug()<<de->t.getName();
            de=de->next;
        }**/

        //qDebug()<<user.getid()<<endl;

    }
    else if(ui->comboBox->currentText()== "Log Out")
    {
        LoginDlg d;
        this->close();
        d.exec();
    }


}

User& UserUI::getUser()
{
    return this->user;
}



void UserUI::handleTimeout()//不断更新数据实体
{
    Node<User>* tmp=users.gethead();
    while(tmp!=NULL)
    {
        if(tmp->t.getid()==this->getUser().getid())
        {
            break;
        }
        tmp=tmp->next;
    }

    if(tmp!=NULL) this->user=tmp->t;

    cout<< "success update userui.user"<<endl;
}

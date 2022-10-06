#include "search.h"
#include "ui_search.h"

QString content;//全局变量，用于传输输入的值

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}


void Search::on_buttonBox_accepted()
{
    content=ui->lineEdit->text();
    this->close();
}



void Search::on_buttonBox_rejected()
{
    content=ui->lineEdit->text();
    this->close();
}

bool Match(QString key,QString content)//用于查询商品的模糊搜索
{
    //将key的子字符串逐个与content对比
    return key.contains(content,Qt::CaseInsensitive);//不区分大小写
}

QString Search::getContent()
{
    return content=ui->lineEdit->text();
}



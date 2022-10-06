#include "file.h"


List<User>  WriteOutUser(const char* path)
{

    List<User> l;
    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << endl;

    string buf;
    getline(fin,buf);//跳过第一行表头

    //buf: ID name pwd phonenumber addr balance userstate

    while (getline(fin, buf))
    { //切片


        string delimiter=",";//文件以英英文逗号为分隔符
        size_t pos=0;

        pos=buf.find(delimiter);
        string s=buf.substr(0,pos);
        QString id = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString name= QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString pwd = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString phonenumber = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString addr = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        string bal=buf.substr(0,pos);
        float balance=std::stof(bal);
        buf.erase(0,pos+delimiter.length());
        //程序启动写入文件时，状态都为0（inactive）

      //创建对象  
        User tmp(id,name,pwd,phonenumber,addr,balance);
        l.push_back(tmp);


    }

    //cout<< "ok to user.txt";

    return l;

}


List<Good>  WriteOutGood(const char* path)//传入路径
{
    List<Good> l;

    /**
    QString ID;
    QString name;
    float price;//精确到小数点后一位
    int number;
    QString description;
    QString SellerID;
    QString addDate;
    bool state;//0表示下架，1表示在售
**/
    //commodityID,name,price,number,description,sellerID,addedDate,state
    //Good(const QString id,const QString na, const float p, const int n,const QString d, const QString sellerid,const QString ad,const bool s)

    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << endl;

    string buf;
    getline(fin,buf);//跳过第一行表头

    //buf: commonsityID commodityName price number description sellerID addDate state

    while (getline(fin, buf))
    { //切片
        string delimiter=",";
        size_t pos=0;

        pos=buf.find(delimiter);
        string s=buf.substr(0,pos);
        QString id = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString name= QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        float price = std::stof(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        int number = stoi(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString description = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString sellerID = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString addDate = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        s=buf;//只剩一个state
        bool state=(s=="0")?0:1;

        Good tmp(id,name, price, number,description, sellerID,addDate,state);
        l.push_back(tmp);






    }
    //cout << "ok to good.txt" << endl;

    return l;
}

List<Order> WriteOutOrder(const char* path)
{
    List<Order> l;
    //orderID,commodityID,unitPrice,number,date,sellerID,buyerID
    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << endl;

    string buf;
    getline(fin,buf);//跳过第一行表头

    while (getline(fin, buf))
    { //切片
        string delimiter=",";
        size_t pos=0;

        pos=buf.find(delimiter);
        string s=buf.substr(0,pos);
        QString oid = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString cid= QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        float unitprice = std::stof(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        int number = stoi(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString date = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());

        pos=buf.find(delimiter);
        s=buf.substr(0,pos);
        QString sellerID = QString::fromStdString(s);
        buf.erase(0,pos+delimiter.length());


        QString buyerID = QString::fromStdString(buf);


        Order tmp(oid,cid,unitprice,number,date,sellerID,buyerID);
        l.push_back(tmp);

    }
    //cout << "ok to order.txt" << endl;

    return l;
}


void WriteInUser(const char* path)
{

}
void WriteInGood(const char* path)
{

}
void WriteInOrder(const char* path)
{

}


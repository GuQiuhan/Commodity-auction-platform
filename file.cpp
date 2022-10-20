#include "file.h"

extern List<Good> goods;
extern List<Order> orders;
extern List<User> users;
extern List<Auction> auctions;
extern QString UserID_now;//只是数字，前面要加上字母
extern QString GoodID_now;//只是数字，前面要加上字母
extern QString OrderID_now;//只是数字，前面要加上字母

List<User>  WriteOutUser(const char* path)
{
//创建users对象的时候要用到goods和orders两个已经创建好的数据结构
    List<User> l;
    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << path <<endl;

    else{
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

            //调整全局变量id的初始化
            if(id.mid(1).toInt()>UserID_now.toInt())
            {
                UserID_now=id.mid(1);
                //qDebug()<<"change:"<< UserID_now<<endl;
            }

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
           //加入good和order
            Node<Good> *x=goods.gethead();
            while(x!=NULL)
            {
                if(x->t.getSid()==id) tmp.addGood(x->t);//卖的商品
                else if(x->t.getID()==id) tmp.addBuyGood(x->t);//买的商品
                x=x->next;
            }

            //qDebug()<<name << tmp.getSellerGood().getLen();

            Node<Order>* y=orders.gethead();
            while(y!=NULL)
            {
                if(y->t.getBid()==id) tmp.addBuyOrder(y->t);
                else if(y->t.getSid()==id) tmp.addSellOrder(y->t);
                y=y->next;
            }

            l.push_back(tmp);
        }

        //cout<< "ok to user.txt";
        fin.close();
    }
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
    if (!fin.is_open())  cout << "Fail to read the file:" << path <<endl;

    else{
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

            if(id.mid(1).toInt()>GoodID_now.toInt()) GoodID_now=id;

            //cout << buf <<endl;
            pos=buf.find(delimiter);
            s=buf.substr(0,pos);
            QString name= QString::fromStdString(s);
            buf.erase(0,pos+delimiter.length());

            //qDebug() << name << endl;

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

        fin.close();
    }
    return l;
}

List<Order> WriteOutOrder(const char* path)
{
    List<Order> l;
    //orderID,commodityID,unitPrice,number,date,sellerID,buyerID
    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << path<<endl;
    else{

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

            if(oid.mid(1).toInt()>OrderID_now.toInt()) OrderID_now=oid;

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

        fin.close();
    }
    return l;
}


void WriteInUser(const char* path)
{
    ofstream fout( path);
    if ( ! fout) cout << "Fail to write the file:" <<path <<endl;
    else
    {
        // 输出到磁盘文件
        fout << "userID,username,password,phoneNumber,address,balance,userState"<< endl;
        Node<User>* tmp=users.gethead();
        if(tmp==NULL)
        {
            fout.close();
            return;
        }
        while(tmp->next!=NULL)
        {
            fout<< tmp->t.getid().toStdString()<<",";
            fout<<tmp->t.getName().toStdString()<<",";
            fout<<tmp->t.getPwd().toStdString()<<",";
            fout<< tmp->t.getContact().toStdString()<<",";
            fout <<tmp->t.getAddr().toStdString()<<",";
            fout << tmp->t.getBal()<<",";
            fout<<"inactive";//关闭程序时都是不活跃
            fout <<endl;
            tmp=tmp->next;
        }
        //最后一个不需要回车符
        fout<< tmp->t.getid().toStdString()<<",";
        fout<<tmp->t.getName().toStdString()<<",";
        fout<<tmp->t.getPwd().toStdString()<<",";
        fout<< tmp->t.getContact().toStdString()<<",";
        fout <<tmp->t.getAddr().toStdString()<<",";
        fout << tmp->t.getBal()<<",";
         fout<<"inactive";
        //fout <<endl;

        //保证最后一行没有回车符,即最后光标停留在最后一行的最后!!否则读文件会出错
        //关闭文件输出流
        fout.close();
    }
}
void WriteInGood(const char* path)
{
    ofstream fout( path);
    if ( ! fout) cout << "Fail to write the file:" <<path <<endl;
    else
    {
        // 输出到磁盘文件
        fout << "commodityID,name,price,number,description,sellerID,addedDate,state"<< endl;
        Node<Good>* tmp=goods.gethead();
        if(tmp==NULL)
        {
            fout.close();
            return;
        }
        while(tmp->next!=NULL)
        {
            fout<< tmp->t.getID().toStdString()<<",";
            fout<<tmp->t.getName().toStdString()<<",";
            fout<<tmp->t.getprice()<<",";
            fout<< tmp->t.getNumber()<<",";
            fout <<tmp->t.getDescription().toStdString()<<",";
            fout << tmp->t.getSid().toStdString()<<",";
            fout << tmp->t.getDate().toStdString()<<",";
            if(tmp->t.getState()) fout<< "On Sale";
            else fout<<"Off Sale";
            fout <<endl;
            tmp=tmp->next;
        }
        //最后一个不需要回车符
        fout<< tmp->t.getID().toStdString()<<",";
        fout<<tmp->t.getName().toStdString()<<",";
        fout<<tmp->t.getprice()<<",";
        fout<< tmp->t.getNumber()<<",";
        fout <<tmp->t.getDescription().toStdString()<<",";
        fout << tmp->t.getSid().toStdString()<<",";
        fout << tmp->t.getDate().toStdString()<<",";
        if(tmp->t.getState()) fout<< "1";//good文件中以0/1存储状态
        else fout<<"0";
        //fout <<endl;

        //保证最后一行没有回车符,即最后光标停留在最后一行的最后!!否则读文件会出错
        //关闭文件输出流
        fout.close();
    }
}
void WriteInOrder(const char* path)
{
    //cout<< "write out order"<<endl;
    ofstream fout( path);
    if ( ! fout) cout << "Fail to write the file:" <<path <<endl;
    else
    {
        // 输出到磁盘文件
        fout << "orderID,commodityID,unitPrice,number,date,sellerID,buyerID"<< endl;
        Node<Order>* tmp=orders.gethead();
        if(tmp==NULL)
        {
            fout.close();
            return;
        }
        while(tmp->next!=NULL)
        {
            fout<< tmp->t.getOid().toStdString()<<",";
            fout<<tmp->t.getCid().toStdString()<<",";
            fout<<tmp->t.getprice()<<",";
            fout<< tmp->t.getNumber()<<",";
            fout <<tmp->t.getDate().toStdString()<<",";
            fout << tmp->t.getSid().toStdString()<<",";
            fout << tmp->t.getBid().toStdString();
            fout <<endl;
            tmp=tmp->next;
        }
        //最后一个不需要回车符
        fout<< tmp->t.getOid().toStdString()<<",";
        fout<<tmp->t.getCid().toStdString()<<",";
        fout<<tmp->t.getprice()<<",";
        fout<< tmp->t.getNumber()<<",";
        fout <<tmp->t.getDate().toStdString()<<",";
        fout << tmp->t.getSid().toStdString()<<",";
        fout << tmp->t.getBid().toStdString();

        //保证最后一行没有回车符,即最后光标停留在最后一行的最后!!否则读文件会出错
        //关闭文件输出流
        fout.close();
    }
}

List<Auction> WriteOutAuction(const char* path)
{
    List<Auction> l;
    //orderID,commodityID,unitPrice,number,date,sellerID,buyerID,time
    ifstream fin;
    fin.open(path,ios::in); //打开文件
    if (!fin.is_open())  cout << "Fail to read the file" << path<<endl;
    else{

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

            //if(oid.mid(1).toInt()>OrderID_now.toInt()) OrderID_now=oid;

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

            pos=buf.find(delimiter);
            s=buf.substr(0,pos);
            QString buyerID = QString::fromStdString(s);
            buf.erase(0,pos+delimiter.length());


            QString time = QString::fromStdString(buf);


            Order tmp(oid,cid,unitprice,number,date,sellerID,buyerID);
            Auction a(tmp,time);
            l.push_back(a);

        }
        //cout << "ok to order.txt" << endl;

        fin.close();
    }
    return l;
}

void WriteInAuction(const char* path)
{

    //cout<<"writing"<<endl;
    ofstream fout( path);
    if ( ! fout) cout << "Fail to write the file:" <<path <<endl;
    else
    {
        // 输出到磁盘文件
        fout << "orderID,commodityID,unitPrice,number,date,sellerID,buyerID,time"<< endl;
        Node<Auction>* tmp=auctions.gethead();
        if(tmp==NULL)
        {
            fout.close();
            return;
        }
        while(tmp->next!=NULL)
        {
            fout<< tmp->t.getOrder().getOid().toStdString()<<",";
            fout<<tmp->t.getOrder().getCid().toStdString()<<",";
            fout<<tmp->t.getOrder().getprice()<<",";
            fout<< tmp->t.getOrder().getNumber()<<",";
            fout <<tmp->t.getOrder().getDate().toStdString()<<",";
            fout << tmp->t.getOrder().getSid().toStdString()<<",";
            fout << tmp->t.getOrder().getBid().toStdString()<<",";
            fout<<tmp->t.getTime().toStdString();
            fout <<endl;
            tmp=tmp->next;
        }
        //最后一个不需要回车符
        fout<< tmp->t.getOrder().getOid().toStdString()<<",";
        fout<<tmp->t.getOrder().getCid().toStdString()<<",";
        fout<<tmp->t.getOrder().getprice()<<",";
        fout<< tmp->t.getOrder().getNumber()<<",";
        fout <<tmp->t.getOrder().getDate().toStdString()<<",";
        fout << tmp->t.getOrder().getSid().toStdString()<<",";
        fout << tmp->t.getOrder().getBid().toStdString()<<",";
        fout<<tmp->t.getTime().toStdString();

        //保证最后一行没有回车符,即最后光标停留在最后一行的最后!!否则读文件会出错
        //关闭文件输出流
        fout.close();
    }
}



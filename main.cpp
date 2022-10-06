#include "mainwindow.h"

#include <QApplication>
#include "logindlg.h"
#include <iostream>
#include <QString>
#include "user.h"
#include "list.h"
#include "good.h"
#include "order.h"
#include "file.h"
using namespace std;

//全局变量
QString UserID_now;//只是数字，前面要加上字母
QString GoodID_now;//只是数字，前面要加上字母
QString OrderID_now;//只是数字，前面要加上字母
List<User> users;
List<Good> goods;
List<Order> orders;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDlg dlg;   // 建立自己新建的类的对象dlg

    //初始化全局变量
    UserID_now="000";
    GoodID_now="000";
    OrderID_now="000";

    //TODO: 以下文件存储路径需要根据实际环境修改
    char* user_path=(char *)"/Users/pro/Desktop/proj1/user.txt";
    char* good_path=(char *)"/Users/pro/Desktop/proj1/good.txt";//待创建
    char* order_path=(char *)"/Users/pro/Desktop/proj1/order.txt";//待创建

    //一定要先读goods和orders文件,因为创建users的时候也需要用到读好的前两个文件
    goods=WriteOutGood(good_path); //用于存储商品文件
    orders=WriteOutOrder(order_path); ; //用于存储订单文件
    users=WriteOutUser(user_path); // 用于存储用户文件


    dlg.exec();

    //写入文件
    WriteInUser(user_path);
    WriteInGood(good_path);
    WriteInOrder(order_path);
    return a.exec();
}

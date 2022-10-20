#ifndef FILE_H
#define FILE_H

#include "list.h"
//#include "list.cpp"
#include "user.h"
#include "good.h"
#include "order.h"
#include "addfunction.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
using namespace std;

//将文件读入到数据结构当中
List<User>  WriteOutUser(const char* path);//返回读好的数据结构
List<Good>  WriteOutGood(const char* path);
List<Order> WriteOutOrder(const char* path);
List<Auction> WriteOutAuction(const char* path);

//void UpdateUser(const char* path);
//void UpdateGood(const char* path);
//void UpdateOrder(const char* path);

//将数据结构读出到文件中
void WriteInUser(const char* path);
void WriteInGood(const char* path);
void WriteInOrder(const char* path);
void WriteInAuction(const char* path);


#endif // FILE_H


#ifndef FILE_H
#define FILE_H

#include "list.h"
//#include "list.cpp"
#include "user.h"
#include "good.h"
#include "order.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
using namespace std;

List<User>  WriteOutUser(const char* path);
List<Good>  WriteOutGood(const char* path);
List<Order> WriteOutOrder(const char* path);

//void UpdateUser(const char* path);
//void UpdateGood(const char* path);
//void UpdateOrder(const char* path);
void WriteInUser(const char* path);
void WriteInGood(const char* path);
void WriteInOrder(const char* path);


#endif // FILE_H


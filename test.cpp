#include "test.h"
#include <QDebug>


void PrintUsers(List<User>& u)
{
    Node<User>* tmp=u.gethead();
    qDebug() << "users:" << endl;

    while(tmp)
    {
        qDebug()<< tmp->t.getName() << endl;
        tmp=tmp->next;

    }
}

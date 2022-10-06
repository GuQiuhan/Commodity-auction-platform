#include "list.h"
#include <iostream>
using namespace std;
/**
template<class T>
List<T>::List()
{
    head =new Node<T>;
    head->next=NULL;
    tail=head;
    len=0;
}


template <class  T>
List<T>::~List()
{
    Node<T> *tmp = NULL;

    while (head) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

template <class T>
void List<T>::clear()
{
    ~List();
    List();
}

template <class T>
void List<T>::insert(T &t, int pos)//在第pos个节点后面插入节点
{
    Node<T> *cur = NULL;

    // 对pos的容错处理
    if (pos >= len) {
        pos = len;
    }

    cur = head;
    for (int i = 0; i < pos; ++i) {
        cur = cur->next;
    }

    // 把上层应用的t结点缓存到容器中
    Node<T> *node = new Node < T > ;
    node->next = NULL;
    node->t = t; // 把t缓存到容器中

    node->next = cur->next;
    cur->next = node;

    ++len;

}

template <class T>
void List<T>::get(int pos, T &t)
{
    Node<T> *cur = NULL;

    if (pos >= len) {
        ;
    }

    cur = head;
    for (int i = 0; i < pos; ++i) {
        cur = cur->next;
    }

    t = cur->next->t; // 把pos位置的结点赋值给t

    //return 0;
}

template <class T>
void List<T>::del(int pos, T &t)
{
    Node<T> *cur = NULL;

    if (pos >= len) {
        //return -1;
    }

    cur = head;
    for (int i = 0; i < pos; ++i) {
        cur = cur->next;
    }
    Node<T> *ret = NULL;
    ret = cur->next;
    t = ret->t; // 把缓存的结点给上层应用t

    // 删除操作
    cur->next = ret->next;
    --len;
    delete ret; // 注意释放内存，因为insert的时候new Node<T>

    //return 0;
}

template <class T>
int List<T>::getLen()
{
    return len;
}

template <class T>
void List<T>::push_back(T t)//加入一个节点
{
    Node<T> *tmp=new Node<T>;
    tmp->t=t;
    tmp->next=NULL;//创建一个节点

    tail->next=tmp;//从尾部加入
    tail=tmp;

}
**/

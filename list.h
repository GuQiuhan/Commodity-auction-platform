#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
#include <QDebug>

/**
记录一下这里使用模版类产生的错误：
C++程序中非专用模板的实现必须对使用它的翻译单元可见。编译器必须能够查看实现，以便为代码中的所有特化生成代码。
所以当模块中用到非专用模版时，有两种解决方法

1.直接在主函数中 include “list.cpp”。这个方法会产生重复定义的问题，即文件之间的包含牵扯不清，所以建议使用第二种方法
2.将模板的实现部分写到 list.h 里

**/
//List类模版
//模仿vector
template <class T>
struct Node
{
    T t;
    Node * next=NULL;
    Node<T>* operator =(Node<T>* tmp)
    {
        &(this->t)=&(tmp->t);
        this->next=tmp->next;
    }
};

template <class T>
class List
{
private:
    Node<T>* head;
    int len;
    Node<T>* tail;

public:
    List()//构造函数
    {
        head =NULL;//初始时为空指针
        tail=NULL;
        len=0;
    }
    ~List()
    {
        Node<T> *tmp = NULL;

        while (head) {
            tmp = head->next;
            delete head;
            head = tmp;
        }
    }

    List(List& l)//拷贝构造函数
    {
        if(l.len==0)
        {
            head=NULL;
            tail=NULL;
            len=0;
        }
        else
        {
            head=new Node<T>;
            head->t=l.head->t;
            head->next=NULL;

            tail=new Node<T>;
            tail=head;

            Node<T>* cur=new Node<T>;//l链表上的指针
            cur=l.head->next;

            while(cur)
            {
                Node<T>* tmp=new Node<T>;
                tmp->t=cur->t;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
                cur=cur->next;
            }
            len=l.len;
        }
    }


    void del(int pos)//删除第pos个位置的节点，头节点pos为0
    {
        Node<T> *cur = NULL;

        if(len==0) return;//空链表，没啥好删的
        if(pos==0&&len!=1)
        {
            cur=head;
            head=head->next;
            len--;
            delete cur;
            return;
        }

        if(pos==0&&len==1)//只有一个节点并删除
        {
            cur=head;
            head=head->next;
            tail=head;
            len--;
            delete cur;
            return;
        }

        if (pos <len)
        {
            qDebug()<<pos<<len;
            cur = head;
            Node<T>* pre=head;
            for (int i = 0; i < pos-1; ++i) pre = pre->next;//找到要删的节点的前面一个节点
            for (int i = 0; i < pos; ++i)
            {
               // cur->t.Print();

                cur = cur->next;//找到要删除掉的cur
            }

            if(cur==tail) tail=pre;
            //if(cur==NULL) {qDebug()<<"NULL";}
           // cur->t.Print();
            //pre->t.Print();

            pre->next=cur->next;
            cur->next=NULL;
            --len;
            delete cur; // 注意释放内存，因为insert的时候new Node<T>
        }
    }

    int getLen()
    {
        return len;
    }

    Node<T>* gethead()
    {
        //Node<T>* cur=new Node<T>;
        //cur=head;
        //return cur;
        return head;
    }

    void push_back(T& t)
    {
        Node<T> *tmp=new Node<T>;
        tmp->t=t;//要求每一个T都必须有一个赋值操作符重载函数！！！
        tmp->next=NULL;//创建一个节点


        if(head==NULL) //链表为空
        {
            head=tmp;
            tail=head;

        }

        else
        {
            tail->next=tmp;//从尾部加入

            tail=tmp;

        }


        len++;

    }

    void update(T& t)//找到t并更新t，需要在三个类里增加等于操作符重载函数！！
    {
        //qDebug()<<"into update "<<endl;

        Node<T>* tmp=head;

        while(tmp!=NULL)
        {
            //tmp->t.Print();
            if(tmp->t==t)//找到t，需要对每个模版t重载等于操作符！！
                break;
            tmp=tmp->next;//救命！！！这个bug卡了我一个小时！！一定要记得移动指针啊！
        }

        if(tmp!=NULL)//在此程序中一般都应该能找到
        {
           // qDebug()<<"change list here" <<endl;
            tmp->t=t;//替换
        }

    }

    //赋值操作符重载
    void operator=(List<T> const& l)
    {
        head=new Node<T>;
        tail=new Node<T>;
        this->len=l.len;
        if(len==0)
        {
            head=tail=NULL;
        }

        else
        {
            head->t=l.head->t;
            head->next=NULL;

            tail=new Node<T>;
            tail=head;

            Node<T>* cur=new Node<T>;//l链表上的指针
            cur=l.head->next;

            while(cur)
            {
                Node<T>* tmp=new Node<T>;
                tmp->t=cur->t;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
                cur=cur->next;
            }
        }
    }


};

#endif // LIST_H



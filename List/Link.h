//
// Created by Jeza on 2017/9/13.
//

#ifndef LIST_LINK_H
#define LIST_LINK_H

#include "List.h"
#include <iostream>
#define LinkPosi(T) Link<T>*
using namespace std;
template<typename T>
class Link //单向链表节点
{
public:
    T data;
    Link* next;

    Link(const T& _data,Link<T>* next_pointer=NULL):data(_data),next(next_pointer) {}
    Link(Link<T>* next_pointer=NULL):next(next_pointer) {}
};

template<typename T>
class Llist:public List<T>
{
private:
    LinkPosi(T) head;
    LinkPosi(T) tail;
    LinkPosi(T) curr;
    int listSize; //表长

    void initialize()
    {
        curr=tail=head=new Link<T>();
        listSize=0;
    }

    void removeAll()
    {
         //delete all elements
        LinkPosi(T) h=head;LinkPosi(T) r;
        while(h)  //一重循环删除
        {
            r=h;
            h=h->next;
            delete r;
            r=NULL;
        }
    }
};

#endif //LIST_LINK_H

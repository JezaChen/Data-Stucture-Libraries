//
// Created by Jeza on 2017/9/13.
//

#ifndef LIST_LINK_H
#define LIST_LINK_H

#include "List.h"
#include <iostream>
#define LinkPosi(T) Link<T>*
#define defaultSize 200
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

    void removeAll();
public:
    Llist(int size=defaultSize) {initialize();} //defaultSize有啥用处
    ~Llist() {removeAll();}

    void trav()const; //遍历链表
    void clear() {removeAll();initialize();}
    void insert(const T& x); //插入
    void append(const T& x); //追加
    T remove(); //删除

    //位置操作
    void removeToStart();
    void removeToEnd();
    void prev();
    void next();
    void moveToPosi(int newPosi);
    int currPosi();
    const T& getValue();

};

#endif //LIST_LINK_H

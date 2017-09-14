//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_DOUBLY_LINKED_LIST_H
#define LIST_DOUBLY_LINKED_LIST_H
#define LinkPosi(T) Link<T>*
#define defaultSize 100
#include <iostream>
#include "List.h"

template<typename T>
class Link
{
public:
    T data;
    LinkPosi(T) next;
    LinkPosi(T) prev;
    static LinkPosi(T) freeList;

    //Constructor
    Link(T _data,LinkPosi(T) _prev=NULL,LinkPosi(T) _next=NULL):data(_data),prev(_prev),next(_next) {}
    Link(LinkPosi(T) _prev=NULL,LinkPosi(T) _next=NULL):prev(_prev),next(_next) {}

    void* operator new(size_t)
    {
        if(freeList==NULL) return ::new Link<T>;
        LinkPosi(T) temp=freeList;
        freeList=freeList->next;
        temp->next=NULL;
        return temp;
    }

    void operator delete(void* ptr)
    {
        ((LinkPosi(T)) ptr)->next=freeList;
        freeList=(LinkPosi(T)) ptr;
    }
};

template<typename T>
class Llist:public List<T>
{
private:
    LinkPosi(T) head;
    LinkPosi(T) tail;
    LinkPosi(T) curr;//当前位置，指针表示
    int currPosition; //当前位置，数字表示
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
    int currentPosi();
    const T& getValue();
};


#endif //LIST_DOUBLY_LINKED_LIST_H

//
// Created by Jeza on 2017/9/14.
//

#include "Link.h"
template<typename T>
void Llist<T>::removeAll()
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

template<typename T>
void Llist<T>::insert(const T &x)
{
    curr->next=new Link(x,curr->next);
    if(curr==tail) tail=tail->next; //如有必要，需要更新尾节点的位置
    listSize++; //更新表长
}
template<typename T>
void Llist<T>::append(const T &x)
{
    tail=tail->next=new Link(x,NULL);
    listSize++;
}
template<typename T>
T Llist<T>::remove()
{
    if(curr->next==NULL)
    {
        //TODO::处理异常状况
    }
    else
    {
        LinkPosi(T) target=curr->next;
        T r=target->data;
        curr->next=target->next;
        delete target;
        return r;
    }
}

//位置操作
template<typename T>
void Llist<T>::prev()
{
    //TODO:处理异常情况
    LinkPosi(T) r=head;
    while(r->next!=curr)
        r=r->next;
    curr=r;
    currPosition--;
}
template<typename T>
void Llist<T>::next()
{
    //TODO:处理异常情况
    curr=curr->next;
    currPosition++;
}
template<typename T>
void Llist<T>::moveToPosi(int newPosi)
{
    //TODO:处理异常
    if(newPosi>=currPosition)
    {
        //直接后移即可
        for(int i=0;i<newPosi-currPosition;i++)
            curr=curr->next;
        return;
    }
    else
    {
        LinkPosi(T) r=head;
        for(int i=0;i<newPosi;i++)   curr=curr->next;
        return ;
    }
}
template<typename T>
int Llist<T>::currentPosi()
{
    return currPosition;
}
template<typename T>
void Llist<T>::removeToStart()
{
    curr=head;
    currPosition=0;
}
template<typename T>
void Llist<T>::removeToEnd()
{
    curr=tail;
    currPosition=listSize;
}
template<typename T>
const T& Llist<T>::getValue()
{
    //TODO:处理异常
    return curr->next->data;
}
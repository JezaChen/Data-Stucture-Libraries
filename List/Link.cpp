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
template<typename T>
void Llist<T>::prev()
{
    //TODO:处理异常情况
    LinkPosi(T) r=head;
    while(r->next!=curr)
        r=r->next;
    curr=r;
}
template<typename T>
void Llist<T>::next()
{
    curr=curr->next;
}
template<typename T>
void Llist<T>::moveToPosi(int newPosi)
{

}
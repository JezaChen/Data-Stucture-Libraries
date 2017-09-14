//
// Created by Jeza on 2017/9/14.
//

//
// Created by Jeza on 2017/9/14.
//
#include "Doubly_Linked_List.h"
#include "../Common/Exception_Handler.h"

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
    curr->next=curr->next->prev=new Link(x,curr,curr->next);
    if(curr==tail) tail=tail->next; //如有必要，需要更新尾节点的位置
    listSize++; //更新表长
}
template<typename T>
void Llist<T>::append(const T &x)
{
    tail=tail->next=new Link(x,tail,NULL);
    listSize++;
}
template<typename T>
T Llist<T>::remove()
{
    if (curr->next == NULL)
        throw nullPointer_Exception(); //抛出空指针异常
    else
    {
        LinkPosi(T) target=curr->next;
        T r=target->data;
        curr->next=target->next;
        target->next->prev=curr;
        delete target;
        return r;
    }
}

//位置操作
template<typename T>
void Llist<T>::prev()
{
    if(curr==head)
        throw outOfBounds_Exception(OVERFLOWED); //抛出出界异常
    curr=curr->prev;
}
template<typename T>
void Llist<T>::next()
{
    if(curr==tail)
        throw outOfBounds_Exception(UNDERFLOWED); //抛出出界异常
    curr=curr->next;
    currPosition++;
}
template<typename T>
void Llist<T>::moveToPosi(int newPosi)
{
    if(newPosi<0) throw outOfBounds_Exception(OVERFLOWED);
    if(newPosi>listSize) throw outOfBounds_Exception(UNDERFLOWED);
    if(newPosi>=currPosition)
    {
        //后移
        for(int i=0;i<newPosi-currPosition;i++)
            curr=curr->next;
        return;
    }
    else
    {
        //前移
        for(int i=0;i<currPosition-newPosi;i++)
            curr=curr->prev;
        return;
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
    if(curr==head)
        throw nullPointer_Exception();  //抛出空指针异常
    return curr->next->data;
}

template <typename T>
T& Llist<T>::operator[](int posi)
{
    moveToPosi(posi);
    return curr->data;
}
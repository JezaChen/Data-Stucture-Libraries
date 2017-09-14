//
// Created by Jeza on 2017/9/14.
//
#include "Array_Based_Queue.h"

template <typename T>
void AQueue<T>::clear()
{
    rear=0; head=1;
}

template<typename T>
T AQueue<T>::dequeue()
{
    //TODO: 处理异常情况
    T temp=listArray[front];
    head=(head+1)%capacity; //记得要取余数
    return temp;
}

template<typename T>
void AQueue<T>::enqueue(const T &e)
{
    //TODO: 处理异常情况
    if((rear+2)%capacity==head) {}
    //else
    rear=(rear+1)%capacity;
    listArray[rear]=e;
}
template <typename T>
const T& AQueue<T>::front() const
{
    //TODO: 处理异常情况
    return listArray[head];
}

template <typename T>
int AQueue<T>::size()const
{
    return (rear-head+1-capacity)%capacity; //记得取余
}
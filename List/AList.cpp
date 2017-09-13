//
// Created by Jeza on 2017/9/12.
//
#include "AList.h"

template<typename T>
void Alist<T>::clear()
{
    delete[] data;
    listSize=0; currPosi=0;
    data=new T[opacity];
}

template<typename T>
void Alist<T>::append(const T &x)
{
    data[listSize++]=x;
}

template <typename T>
void Alist<T>::insert(const T &x)
{
    //腾出空间
    for(int i=listSize;i>currPosi;i--)
        data[i]=data[i-1];
    data[currPosi]=x;
    listSize++;
}

template<typename T>
T Alist<T>::remove()
{
    //TODO：处理异常情况
    T target=data[currPosi];
    //向左腾空间
    for(int i=currPosi;i<listSize-1;i++)
       data[i]=data[i+1]; //向左覆盖
    listSize--;
    return target; //返回删除的对象
}

//位置操作
template<typename T>
void Alist<T>::moveToStart()
{
    currPosi=0;
}

template<typename T>
void Alist<T>::moveToEnd()
{
    currPosi=listSize;
}

template<typename T>
void Alist<T>::next()
{
    //TODO:处理异常情况
    currPosi++;
}
template<typename T>
void Alist<T>::prev()
{
    //TODO:处理异常情况
    currPosi--;
}
template<typename T>
void Alist<T>::moveToPosi(int posi)
{
    //TODO:处理异常情况
    currPosi=posi;
}

template <typename T>
const T& Alist<T>::getValue()
{
   //TODO:处理异常情况
    return data[currPosi];
}

template <typename T>
int Alist<T>::currentPosi()
{
    return currPosi;
}

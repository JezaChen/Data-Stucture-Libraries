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
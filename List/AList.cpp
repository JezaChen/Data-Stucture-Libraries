//
// Created by Jeza on 2017/9/12.
//
#include "AList.h"
#include "Exception_Handler.h"

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
    if(currPosi>=listSize) throw nullPointer_Exception();

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
    if(currPosi==listSize-1)
        throw outOfBounds_Exception(UNDERFLOWED); //抛出出界异常
    currPosi++;
}
template<typename T>
void Alist<T>::prev()
{
    if(currPosi==0)
        throw outOfBounds_Exception(OVERFLOWED); //抛出出界异常
    currPosi--;
}
template<typename T>
void Alist<T>::moveToPosi(int posi)
{
    if(posi<0) throw outOfBounds_Exception(OVERFLOWED);
    if(posi>=listSize) throw outOfBounds_Exception(UNDERFLOWED);
    currPosi=posi;
}

template <typename T>
const T& Alist<T>::getValue()
{
    return data[currPosi];
}

template<typename T>
T& Alist<T>::operator[](int posi)
{
    if(posi<0) throw outOfBounds_Exception(OVERFLOWED);
    if(posi>=listSize) throw outOfBounds_Exception(UNDERFLOWED);

    currPosi=posi; //当前位置更新
    return data[currPosi]; //返回该元素的引用
}
template <typename T>
int Alist<T>::currentPosi()
{
    return currPosi;
}

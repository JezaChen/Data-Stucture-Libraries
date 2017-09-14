//
// Created by Jeza on 2017/9/14.
//

#include "Array_Based_Stack.h"

template <typename T>
void AStack<T>::clear()
{
    _size=0; //_size=0即可
}

template <typename T>
void AStack<T>::push(const T &e)
{
    //TODO:处理异常情况
    listArray[_size++]=e;
}

template<typename T>
T AStack<T>::pop()
{
    //TODO:处理异常情况
    T temp=listArray[(_size--)-1];
    return temp;
}

template<typename T>
T AStack<T>::top()
{
    return listArray[_size-1];
}

template <typename T>
int AStack<T>::size()
{
    return _size;
}

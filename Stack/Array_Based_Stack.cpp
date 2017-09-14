//
// Created by Jeza on 2017/9/14.
//

#include "Array_Based_Stack.h"
#include "../Common/Exception_Handler.h"
template <typename T>
void AStack<T>::clear()
{
    _size=0; //_size=0即可
}

template <typename T>
void AStack<T>::push(const T &e)
{
    if(_size==opacity) throw arrayFull_Exception("stack");
    listArray[_size++]=e;
}

template<typename T>
T AStack<T>::pop()
{
    if(!_size) throw stackEmpty_Exception(); //抛出空战异常
    T temp=listArray[(_size--)-1];
    return temp;
}

template<typename T>
T AStack<T>::top()
{
    if(!_size) throw stackEmpty_Exception();
    return listArray[_size-1];
}

template <typename T>
int AStack<T>::size()
{
    return _size;
}

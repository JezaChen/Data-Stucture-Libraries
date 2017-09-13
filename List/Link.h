//
// Created by Jeza on 2017/9/13.
//

#ifndef LIST_LINK_H
#define LIST_LINK_H

#include "List.h"
#include <iostream>

using namespace std;
template<typename T>
class Link //单向链表节点
{
public:
    T data;
    Link* next;

    Link(const T& _data,Link<T>* next_pointer=NULL):data(_data),next(next_pointer) {}
    Link(Link<T>* next_pointer=NULL):next(next_pointer) {}
};

template<typename T>
class Llist:public List<T>
{
private:

};

#endif //LIST_LINK_H

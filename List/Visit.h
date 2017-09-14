//
// Created by Jeza on 2017/9/14.
//
// 访问器
#ifndef LIST_VISIT_H
#define LIST_VISIT_H

#include <iostream>
using namespace std;

template<typename T>
class PRINTER
{
    void operator () (const T& x)
    {
        cout<<x<<' ';
    }
};
#endif //LIST_VISIT_H

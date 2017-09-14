//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_VISIT_H
#define LIST_VISIT_H

#include <iostream>
using namespace std;

// 访问器
template<typename T>
class PRINTER
{
    void operator () (const T& x)
    {
        cout<<x<<' ';
    }
};
#endif //LIST_VISIT_H

//安全释放器
template<typename T>
void release(T* x) {if(x) delete x;}
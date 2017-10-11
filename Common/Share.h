//
// Created by Jeza on 2017/9/18.
//

#ifndef COMMON_SHARE_H
#define COMMON_SHARE_H
//
// Created by Jeza on 2017/9/14.
//

#include <iostream>
#include "../uniPRINTER/print.h"
using namespace std;
namespace DSLibrary {
// 访问器
    template<typename T>
    class PRINTER {
        void operator()(const T &x) {
            //cout << x << ' ';
            print(x);
        }
    };

//安全释放器
    template<typename T>
    void release(T *x) { if (x) delete x; }

//判等器、比较器
    template<typename T> static bool lt (const T& a,const T& b) {return  a<b;}
    template<typename T> static bool lt (const T* a,const T* b) {return  lt(*a,*b);}
    template<typename T> static bool rt (const T& a,const T& b) {return  a>b;}
    template<typename T> static bool rt (const T* a,const T* b) {return  rt(*a,*b);}
    template<typename T> static bool eq (const T& a,const T& b) {return a==b;}
    template<typename T> static bool eq (const T* a, const T* b) {return eq(*a,*b);}

    template<typename T>
    class COMPARE_LESS
    {
    public:
        bool priority (const T& a, const T& b)
        {
            return lt(a,b);
        }
    };

    template<typename T>
    class COMPARE_MORE
    {
    public:
        bool priority (const T&a, const T& b)
        {
            return rt(a,b);
        }
    };
}
#endif //LIST_VISIT_H

//
// Created by Jeza on 2017/9/14.
//


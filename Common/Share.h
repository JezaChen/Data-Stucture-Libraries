//
// Created by Jeza on 2017/9/18.
//

#ifndef COMMON_SHARE_H
#define COMMON_SHARE_H
//
// Created by Jeza on 2017/9/14.
//

#include <iostream>
using namespace std;
namespace DSLibrary {
// 访问器
    template<typename T>
    class PRINTER {
        void operator()(const T &x) {
            cout << x << ' ';
        }
    };

//安全释放器
    template<typename T>
    void release(T *x) { if (x) delete x; }

//判等器、比较器
    template<typename T> static bool lt (T& a, T& b) {return  a<b;}
    template<typename T> static bool lt (T* a, T* b) {return  lt(*a,*b);}
    template<typename T> static bool rt (T& a, T& b) {return  a>b;}
    template<typename T> static bool rt (T* a, T* b) {return  rt(*a,*b);}
    template<typename T> static bool eq (T& a, T& b) {return a==b;}
    template<typename T> static bool eq (T* a ,T* b) {return eq(*a,*b);}
}
#endif //LIST_VISIT_H

//
// Created by Jeza on 2017/9/14.
//


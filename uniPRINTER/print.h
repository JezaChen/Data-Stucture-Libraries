//
// Created by Jeza on 2017/9/15.
//
/***************************************************
 * 统一打印接口  Universal Printer
 * Ver 0.1
 * *************************************************/
#ifndef UNIPRINTER_PRINT_H
#define UNIPRINTER_PRINT_H

#include <iostream>
#include <cstdio>

#include "../List/AList.h"
#include "../List/Link.h"
#include "../List/Doubly_Linked_List.h"


using namespace std;

namespace DSLibrary {
    //内接口
    class UNI_PRINTER //统一输出类
    {
        //基本类型打印
        static void p(const int &);
        static void p(const float &);
        static void p(const double &);
        static void p(const char &);

        //复杂数据结构的打印输出
        template<typename T> static void p(List &);  //表
    };

    //对外接口
    template<typename T> static void print(T* x) {x?print(*x):printf("<NULL>");} //指针访问
    //引用访问
    template<typename T> static void print(T& x) {UNI_PRINTER::p(x);}
    template<typename T> static void print(const T&x) {UNI_PRINTER::p(x);}
}
#endif //UNIPRINTER_PRINT_H

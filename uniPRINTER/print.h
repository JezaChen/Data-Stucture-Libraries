//
// Created by Jeza on 2017/9/15.
//
/***************************************************
 * 统一打印接口  Universal Printer
 * Ver 0.1
 * *************************************************/
#pragma once
#ifndef UNIPRINTER_PRINT_H
#define UNIPRINTER_PRINT_H

#include <iostream>
#include <cstdio>

#include "../List/AList.h"
#include "../List/Link.h"
#include "../List/List.h"
#include "../List/Doubly_Linked_List.h"


using namespace std;

namespace DSLibrary {

    template<typename T> static void print(T* x);
    template<typename T> static void print(T& x);
    template<typename T> static void print(const T&x);

    //内接口
    class UNI_PRINTER //统一输出类
    {
    public:
        //基本类型打印
        static void p(const int &x) {printf("%d  ",x);}
        static void p(const float &x) {printf("%.2f  ",x);}
        static void p(const double &x) {printf("%2f  ",x);}
        static void p(const char &x) {printf ( " %c",(31<x)&&(x<128)?x:'$');}

        //复杂数据结构的打印输出
        template<typename T> static void p(List<T>& list)
        {
            list.trav(print);
        }

    };

    //对外接口的实现
    template<typename T> static void print(T* x)
    {
        if(x) print(*x);
        else printf("<NULL>");
    } //指针访问
    //引用访问
    template<typename T> static void print(T& x) {UNI_PRINTER::p(x);}
    template<typename T> static void print(const T&x) {UNI_PRINTER::p(x);}

}
#endif //UNIPRINTER_PRINT_H

//
// Created by Jeza on 2017/9/18.
//

#ifndef COMMON_SHARE_H
#define COMMON_SHARE_H

#include <iostream>
#include "../uniPRINTER/print.h"

using namespace std;
namespace DSLibrary
{

    // 访问器
    template<typename T>
    class PRINTER
    {
    public:
        void operator()(T &x)
        {
            //cout << x << ' ';
            print(x);
        }
    };


    //安全释放器
    template<typename T>
    inline void release(T *x)
    { if (x) delete x; }



//判等器、比较器
    template<typename T>
    static bool lt(const T &a, const T &b)
    { return a < b; }

    template<typename T>
    static bool lt(const T *a, const T *b)
    { return lt(*a, *b); }

    template<typename T>
    static bool rt(const T &a, const T &b)
    { return a > b; }

    template<typename T>
    static bool rt(const T *a, const T *b)
    { return rt(*a, *b); }

    template<typename T>
    static bool eq(const T &a, const T &b)
    { return a == b; }

    template<typename T>
    static bool eq(const T *a, const T *b)
    { return eq(*a, *b); }

    template<typename T>
    class COMPARE_LESS
    {
    public:
        bool priority(const T &a, const T &b)
        {
            return lt(a, b);
        }
    };

    template<typename T>
    class COMPARE_MORE
    {
    public:
        bool priority(const T &a, const T &b)
        {
            return rt(a, b);
        }
    };

    template<typename T>
    class Array_Implement //数组操作类
    {
        static void arrayCopy(T *ansArray,
                              const T *&targetArray,
                              const int &ansArraySize,
                              const int targetArraySize)
        {
            int i, j;
            for (int i = 0, j = 0; i < ansArraySize && j < targetArraySize; i++, j++)
            {
                ansArray[i] = targetArray[j];
            }
            return;
        }

        static void arrayCopy(T *ansArray,
                              const T *&targetAns,
                              const int &ansArraySize,
                              const int &lo,
                              const int &hi)
        {
            for (int i = 0, j = lo; i < ansArraySize && j < hi; i++, j++)
            {
                ansArray[i] = targetAns[j];
            }
        }

        static void arrayFill(T *targetArray, int targetNum, const int &size)
        {
            for (int i = 0; i < size; i++) targetArray[i] = targetNum;
        }

        static void arrayZero(T *targetArray, const int &size)
        {
            arrayFill(targetArray, 0, size);
        }


    };
}
#endif //COMMON_SHARE_H



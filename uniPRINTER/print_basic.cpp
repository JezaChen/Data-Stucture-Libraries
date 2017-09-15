//
// Created by Jeza on 2017/9/15.
//
#include "print.h"
#include "cstdio"
using namespace std;

namespace DSLibrary{
    //基本类型统一六位右对齐
    void UNI_PRINTER::p(const int&x)  {printf(" %6d",x);}
    void UNI_PRINTER::p(const float &x) {printf(" %6.2f",x);}
    void UNI_PRINTER::p(const double &x) {printf(" %6.2f",x);}
    void UNI_PRINTER::p(const char &x) {printf ( " %c",(31<x)&&(x<128)?x:'$');}
}
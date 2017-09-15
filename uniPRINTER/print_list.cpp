//
// Created by Jeza on 2017/9/15.
//

#include "print.h"

namespace DSLibrary{
    template<typename T>
    void UNI_PRINTER::p(List &List)
    {
        List.trav(print); //利用虚函数的特性统一规范接入打印函数
    }

}
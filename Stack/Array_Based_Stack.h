//
// Created by Jeza on 2017/9/14.
//

#ifndef STACK_ARRAY_BASED_STACK_H
#define STACK_ARRAY_BASED_STACK_H
#include "Stack_common.h"
#define defaultSize 250
template <typename T>
class AStack:public Stack<T>
{
private:
    int opacity; //最大容量
    int _size; //当前容量
    T* listArray;
public:
    AStack(int op=defaultSize):opacity(op) {}
    ~AStack() {delete[] listArray;}
    void clear();
    void push(const T& e);
    T pop();
    T top();
    int size();
};
#endif //STACK_ARRAY_BASED_STACK_H

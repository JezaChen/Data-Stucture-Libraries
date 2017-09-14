//
// Created by Jeza on 2017/9/14.
//

#ifndef STACK_LINKED_STACK_H
#define STACK_LINKED_STACK_H
#define defualtSize 250

#include  "Stack_common.h"
#include "../List/Link.h" //引入链表头文件



template<typename T>
class LStack:public Stack<T>
{
private:
    LinkPosi(T) _top;
    int _size;
public:
    LStack(int s=defaultSize):_size(s) {}
    ~LStack() {clear();}

    void clear();
    void push(const T& e);
    T pop();
    T top();
    int size();
};

#endif //STACK_LINKED_STACK_H

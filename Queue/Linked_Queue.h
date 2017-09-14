//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_LINKED_QUEUE_H
#define QUEUE_LINKED_QUEUE_H

#include "Queue.h"
#include "../List/Link.h" //引入链表头文件

template <typename T>
class LQueue:public Queue<T>
{
private:
    LinkPosi(T) head;
    LinkPosi(T) rear;
    int _size;
public:
    LQueue() {_size=0;head=rear=new Link<T>;} //init
    ~LQueue() {clear();} //TODO

    void clear();
    void enqueue(const T& e);
    T dequeue();
    const T& front()const;
    int size()const;
};
#endif //QUEUE_LINKED_QUEUE_H

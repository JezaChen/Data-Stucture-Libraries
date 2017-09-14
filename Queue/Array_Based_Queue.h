//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_ARRAY_BASED_QUEUE_H
#define QUEUE_ARRAY_BASED_QUEUE_H
#include "Queue.h"

template<typename T>
class AQueue:public Queue<T>
{
private:
    int capacity; //最大容量
    int head;
    int rear;
    T* listArray;
public:
    AQueue
};
#endif //QUEUE_ARRAY_BASED_QUEUE_H

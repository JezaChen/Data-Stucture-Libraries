//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_ARRAY_BASED_QUEUE_H
#define QUEUE_ARRAY_BASED_QUEUE_H
#include "Queue.h"
#define defaultSize 100
template<typename T>
class AQueue:public Queue<T>
{
private:
    int capacity; //最大容量
    int head;
    int rear;
    T* listArray;
public:
    AQueue(int size=defaultSize):capacity(size+1)
    {
        head=1; rear=0;
        listArray=new T[capacity];
    }

    ~AQueue()
    {
        delete[] listArray;
    }
    void clear();
    void enqueue(const T& e);
    T dequeue();
    const T& front()const;
    int size()const;
};
#endif //QUEUE_ARRAY_BASED_QUEUE_H

//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_ARRAY_BASED_QUEUE_H
#define QUEUE_ARRAY_BASED_QUEUE_H
#include "Queue.h"

#ifndef defaultSize
#define defaultSize 100
#endif

namespace DSLibrary{
template<typename T>
class AQueue : public Queue<T> {
private:
    int capacity; //最大容量
    int head;
    int rear;
    T *listArray;
public:
    AQueue(int size = defaultSize) : capacity(size + 1) {
        head = 1;
        rear = 0;
        listArray = new T[capacity];
    }

    ~AQueue() {
        delete[] listArray;
    }

    void clear()
    {
        rear = 0;
        head = 1;
    }
    void enqueue(const T &e)
    {
        if ((rear + 2) % capacity == head)
            throw arrayFull_Exception("queue"); //抛出队空异常
        //else
        rear = (rear + 1) % capacity;
        listArray[rear] = e;

    }
    T dequeue()
    {
        if (size() == 0)
            throw queueEmpty_Exception(); //抛出队空异常
        T temp = listArray[head];
        head = (head + 1) % capacity; //记得要取余数
        return temp;
    }
    const T &front() const
    {
        if (size() == 0)
            throw queueEmpty_Exception(); //抛出队空异常
        return listArray[head];
    }
    int size() const  {  return (rear - head + 1 + capacity) % capacity; } //记得取余
};

}
#endif //QUEUE_ARRAY_BASED_QUEUE_H

//
// Created by Jeza on 2017/9/14.
//
#include "Array_Based_Queue.h"
#include "../Common/Exception_Handler.h"
namespace DSLibrary {
    template<typename T>
    void AQueue<T>::clear() {
        rear = 0;
        head = 1;
    }

    template<typename T>
    T AQueue<T>::dequeue() {
        if (size() == 0)
            throw queueEmpty_Exception(); //抛出队空异常
        T temp = listArray[front];
        head = (head + 1) % capacity; //记得要取余数
        return temp;
    }

    template<typename T>
    void AQueue<T>::enqueue(const T &e) {
        if ((rear + 2) % capacity == head)
            throw arrayFull_Exception("queue"); //抛出队空异常
        //else
        rear = (rear + 1) % capacity;
        listArray[rear] = e;
    }

    template<typename T>
    const T &AQueue<T>::front() const {
        if (size() == 0)
            throw queueEmpty_Exception(); //抛出队空异常
        return listArray[head];
    }

    template<typename T>
    int AQueue<T>::size() const {
        return (rear - head + 1 - capacity) % capacity; //记得取余
    }
}
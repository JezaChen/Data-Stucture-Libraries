//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
namespace DSLibrary {
//ADT
    template<typename T>
    class Queue {
    public:
        Queue() {}

        virtual ~Queue() {}

        virtual void clear()=0;
        virtual void enqueue(const T &e)=0; //入队
        virtual T dequeue()=0; //出队
        virtual const T &front() const =0;

        virtual int size() const =0; //队的长度
    };
}
#endif //QUEUE_QUEUE_H

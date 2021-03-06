//
// Created by Jeza on 2017/9/14.
//

#ifndef STACK_STACK_COMMON_H
#define STACK_STACK_COMMON_H
namespace DSLibrary {
    template<typename T>
    class Stack {
    public:
        Stack() {}

        virtual ~Stack() {}

        void operator = (const Stack& ) = delete;
        Stack(const Stack& ) = delete;

        virtual void clear()=0;//清空函数
        virtual void push(const T &e)=0; //插入函数
        virtual T pop()=0;
        virtual T top()=0;
        virtual int size()=0;
        virtual bool empty()=0; //判空
    };
}
#endif //STACK_STACK_COMMON_H

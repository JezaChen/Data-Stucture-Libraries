//
// Created by Jeza on 2017/9/12.
//
#pragma once
#ifndef LIST_LIST_H
#define LIST_LIST_H
namespace DSLibrary {
    template<typename T>
    class List {

    public:
        List() {}

        virtual ~List() {}

        void operator=(const List& ) = delete; //不允许赋值

        List(const List& ) = delete; //不允许复制构造

        virtual void clear()=0; //清空操作
        virtual void append(const T &x)=0; //追加操作
        virtual void insert(const T &x)=0; //插入操作
        virtual T remove()=0; //删除操作

        //位置操作
        virtual void moveToStart()=0; //移到最前端
        virtual void moveToEnd()=0; //移到最后端
        virtual void prev()=0; //向前走一位
        virtual void next()=0; //向后走一位
        virtual void moveToPosi(int posi)=0; //移动到某个位置

        virtual const T &getValue()=0; //获取当前位置的值
        virtual T &operator[](int posi)=0; //重载访问运算符，以便直接使用某个元素
        virtual int currentPosi()const=0; //返回当前位置
        virtual int size() const =0; //表的长度

        //遍历操作
       // virtual void trav(VST& visit)=0; //遍历访问，用于全局性修改，利用函数对象特性
        virtual void trav(void ( *visit )(T&))=0; //遍历访问，作局部性地修改，利用函数指针特性
    };


}
#endif //LIST_LIST_H

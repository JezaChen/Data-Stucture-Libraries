//
// Created by Jeza on 2017/9/12.
//
#pragma once

#ifndef LIST_ALIST_H
#define LIST_ALIST_H

#include "List.h"
#include "../Common/Exception_Handler.h"

namespace DSLibrary
{

    template<typename T>
    class Alist : public List<T>
    {
    private:
        int capacity; //最大承载容量
        int listSize; //当前长度
        int currPosi; //当前位置
        T *data; //储存列表数据的数组
    public:

        Alist(int s = 250) : capacity(s), currPosi(0), listSize(0)
        {
            data = new T[s];
        }

        ~Alist()
        {
            if (data)
                delete[] data;
            capacity = listSize = currPosi = 0;
        }

        Alist(const Alist<T> &target, int lo, int hi)
        {
            data = new T[target.size() * 2];
            if (lo > hi || hi >= target.size() || lo < 0) return;
            this->moveToStart();
            int posiTemp = target.currentPosi();
            target.moveToPosi(lo);
            while (target.currentPosi() != hi + 1)
            {
                this->append(target.getValue());
                target.next();
            }
            target.moveToPosi(posiTemp);
        }


        void clear(); //清空
        void append(const T &x); //追加
        void insert(const T &x); //插入
        T remove(); //删除

        //位置操作
        void moveToStart()
        { currPosi = 0; }   //移到最前端
        void moveToEnd()
        { currPosi = listSize; }   //移到最后端
        void prev() //向前走一位
        {
            if (currPosi == 0)
                throw outOfBounds_Exception(UPPER_BOUND); //抛出出界异常
            currPosi--;
        }

        void next()   //向后走一位
        {
            if (currPosi >= listSize)
                throw outOfBounds_Exception(LOWER_BOUND); //抛出出界异常
            currPosi++;
        }

        void moveToPosi(int posi)   //移动到某个位置
        {
            if (posi < 0) throw outOfBounds_Exception(UPPER_BOUND);
            if (posi >= listSize) throw outOfBounds_Exception(LOWER_BOUND);
            currPosi = posi;
        }

        const T &getValue()  //获取当前位置的值
        {
            if (listSize == 0) throw listEmpty_Exception(); //list为空，抛出空list异常
            else if (currPosi == listSize) throw nullPointer_Exception();
            return data[currPosi];
        }

        T &operator[](int posi)
        {
            if (posi < 0) throw outOfBounds_Exception(UPPER_BOUND);
            if (posi >= listSize) throw outOfBounds_Exception(LOWER_BOUND);

            currPosi = posi; //当前位置更新
            return data[currPosi]; //返回该元素的引用
        }

        int currentPosi()const
        { return currPosi; } //返回当前位置
        int size() const
        { return listSize; }  //表的长度
        bool empty() const
        { return !listSize; }   //表是否为空

        //遍历操作
        template<typename VST>
        void trav(VST &visit);

        void trav(void ( *visit )(T &));
    };


    template<typename T>
    void Alist<T>::clear()
    {
        delete[] data;
        listSize = 0;
        currPosi = 0;
        data = new T[capacity];
    }

    template<typename T>
    void Alist<T>::append(const T &x) //追加
    {
        if (listSize == capacity) throw arrayFull_Exception("list");
        data[listSize++] = x;
    }

    template<typename T>
    void Alist<T>::insert(const T &x) //插入
    {
        if (listSize == capacity) throw arrayFull_Exception("list");
        //腾出空间
        for (int i = listSize; i > currPosi; i--)
            data[i] = data[i - 1];
        data[currPosi] = x;
        listSize++;
    }

    template<typename T>
    T Alist<T>::remove() //删除
    {
        if (currPosi >= listSize) throw nullPointer_Exception();

        T target = data[currPosi];
        //向左腾空间
        for (int i = currPosi; i < listSize - 1; i++)
            data[i] = data[i + 1]; //向左覆盖
        listSize--;
        return target; //返回删除的对象
    }

    template<typename T>
    template<typename VST>
    void Alist<T>::trav(VST &visit)
    {
        for (int i = 0; i < listSize; i++)
        {
            visit(data[i]);
        }
    }

    template<typename T>
    void Alist<T>::trav(void ( *visit )(T &))
    {
        for (int i = 0; i < listSize; i++)
        {
            visit(data[i]);
        }
    }

}
#endif //LIST_ALIST_H

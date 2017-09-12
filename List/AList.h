//
// Created by Jeza on 2017/9/12.
//
#include "List.h"

#ifndef LIST_ALIST_H
#define LIST_ALIST_H

template<typename T>
class Alist:public List<T>
{
private:
    int opacity; //最大承载容量
    int listSize; //当前长度
    int currPosi; //当前位置
    T* data; //储存列表数据的数组
public:
    void clear(); //清空
    void append(const T&); //追加
    void insert(const T&); //插入
    T remove(); //删除

    //位置操作
    void moveToStart(); //移到最前端
    void moveToEnd(); //移到最后端
    void prev(); //向前走一位
    void next(); //向后走一位

    void moveToPosi(int posi); //移动到某个位置
    const T& getValue(); //获取当前位置的值
    int currentPosi(); //返回当前位置

    int length() const; //表的长度
};


#endif //LIST_ALIST_H

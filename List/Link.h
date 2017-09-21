//
// Created by Jeza on 2017/9/13.
//
#pragma once
#ifndef LIST_LINK_H
#define LIST_LINK_H

#include "List.h"
#include <iostream>
#include "../Common/Exception_Handler.h"
#ifndef defaultSize
#define defaultSize 200
#endif

#define LinkPosi(T) Link<T>*

namespace DSLibrary
{

    namespace Single_Linked
    {
        using namespace std;

        template<typename T>
        class Link //单向链表节点
        {
        public:
            T data;
            Link *next;
            static LinkPosi(T)freeList;

            Link(const T &_data, Link<T> *next_pointer = NULL) : data(_data), next(next_pointer) {}
            Link(Link<T> *next_pointer = NULL) : next(next_pointer) {}

            void *operator new(size_t) {
                if (freeList == NULL) return ::new Link<T>;
                LinkPosi(T)temp = freeList;
                freeList = freeList->next;
                temp->next = NULL;
                return temp;
            }

            void operator delete(void *ptr) {
                ((LinkPosi(T)) ptr)->next = freeList;
                freeList = (LinkPosi(T)) ptr;
            }
        };
        template<typename T> LinkPosi(T)Link<T>::freeList = NULL;


        template<typename T>
        class Llist : public List<T> {
        private:
            LinkPosi(T)head;
            LinkPosi(T)tail;
            LinkPosi(T)curr;//当前位置，指针表示
            int currPosition; //当前位置，数字表示
            int listSize; //表长
            void initialize() {
                curr = tail = head = new Link<T>();
                listSize =currPosition=0;
            }

            void removeAll()
            {
                //delete all elements
                LinkPosi(T)h = head;
                LinkPosi(T)r;
                while (h)  //一重循环删除
                {
                    r = h;
                    h = h->next;
                    delete r;
                    r = NULL;
                }
            }
        public:
            Llist(int size = defaultSize) { initialize(); } //defaultSize有啥用处
            ~Llist() { removeAll(); }

            void clear() {
                removeAll();
                initialize();
            }

            int length()const {return listSize;}
            void insert(const T &x) //插入
            {
                curr->next = new Link<T>(x, curr->next);
                if (curr == tail) tail = tail->next; //如有必要，需要更新尾节点的位置
                listSize++; //更新表长
            }
            void append(const T &x) //追加
            {
                tail = tail->next = new Link<T>(x, NULL);
                listSize++;
            }
            T remove() //删除
            {
                if (curr->next == NULL)
                    throw nullPointer_Exception(); //抛出空指针异常
                else {
                    LinkPosi(T)target = curr->next;
                    T r = target->data;
                    curr->next = target->next;
                    delete target;
                    return r;
                }
            }

            //位置操作
            void moveToStart()
            {
                curr = head;
                currPosition = 0;
            }
            void moveToEnd()
            {
                curr = tail;
                currPosition = listSize;
            }
            void prev()
            {
                if (curr == head)
                    throw outOfBounds_Exception(OVERFLOWED); //抛出出界异常
                LinkPosi(T)r = head;
                while (r->next != curr)
                    r = r->next;
                curr = r;
                currPosition--;
            }
            void next()
            {
                if (curr == tail)
                    throw outOfBounds_Exception(UNDERFLOWED); //抛出出界异常
                curr = curr->next;
                currPosition++;
            }
            void moveToPosi(int newPosi)
            {
                if (newPosi < 0) throw outOfBounds_Exception(OVERFLOWED);
                if (newPosi > listSize) throw outOfBounds_Exception(UNDERFLOWED);

                if (newPosi >= currPosition) {
                    //直接后移即可
                    for (int i = 0; i < newPosi - currPosition; i++)
                        curr = curr->next;
                    return;
                } else {
                    LinkPosi(T)r = head;
                    for (int i = 0; i < newPosi; i++) curr = curr->next;
                    return;
                }
            }
            int currentPosi()  { return currPosition;}
            const T &getValue()
            {
                if (curr == head)
                    throw nullPointer_Exception();  //抛出空指针异常
                return curr->next->data;
            }
            T &operator[](int posi)
            {
                moveToPosi(posi);
                return curr->data;
            }

            //遍历操作
            template<typename VST> void trav(VST& visit)
            {
                LinkPosi(T)p = head->next;
                while (p) {
                    visit(p);  //线性访问
                    p = p->next;
                }
            }
            void trav(void ( *visit )(T&))
            {
                LinkPosi(T)p = head->next;
                while (p)
                {
                    visit(p->data);  //线性访问
                    p = p->next;
                }
            }
        };
    }
}

#endif //LIST_LINK_H
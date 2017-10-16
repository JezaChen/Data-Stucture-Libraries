//
// Created by Jeza on 2017/9/14.
//

#pragma once
#ifndef LIST_DOUBLY_LINKED_LIST_H
#define LIST_DOUBLY_LINKED_LIST_H
#define LinkPosi(T) Link<T>*

#ifndef defaultSize
#define defaultSize 100
#endif
#include <iostream>
#include "List.h"
#include "../Common/Exception_Handler.h"
#include "../Common/Share.h"


namespace DSLibrary {
    namespace Double_Linked {

        template<typename T>
        class Link {
        public:
            T data;
            LinkPosi(T)next;
            LinkPosi(T)prev;
            static LinkPosi(T) freeList;

            //Constructor
            Link(T _data, LinkPosi(T)_prev = NULL, LinkPosi(T)_next = NULL) : data(_data), prev(_prev), next(_next) {}
            Link(LinkPosi(T)_prev = NULL, LinkPosi(T)_next = NULL) : prev(_prev), next(_next) {}

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
                listSize = 0;
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

            int size()const {return listSize;}
            void clear() {
                removeAll();
                initialize();
            }

            void insert(const T &x) //插入
            {
                if(curr==tail) {append(x); return;}
                curr->next = curr->next->prev = new Link<T>(x, curr, curr->next);
                if (curr == tail) tail = tail->next; //如有必要，需要更新尾节点的位置
                listSize++; //更新表长
            }
            void append(const T &x) //追加
            {
                tail = tail->next = new Link<T>(x, tail, NULL);
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
                    target->next->prev = curr;
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
                curr = curr->prev;
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
                    //后移
                    for (int i = 0; i < newPosi - currPosition; i++)
                        curr = curr->next;
                    return;
                } else {
                    //前移
                    for (int i = 0; i < currPosition - newPosi; i++)
                        curr = curr->prev;
                    return;
                }
            }
            int currentPosi() { return currPosition; }
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
                LinkPosi(T) p=head->next;
                while(p)
                {
                    visit(p->data);  //线性访问
                    p=p->next;
                }
            }
            void trav(void ( *visit )(T&))
            {
                LinkPosi(T) p=head->next;
                while(p)
                {
                    visit(p->data);  //线性访问
                    p=p->next;
                }
            }
        };
    }
}
#endif //LIST_DOUBLY_LINKED_LIST_H
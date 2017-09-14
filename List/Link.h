//
// Created by Jeza on 2017/9/13.
//

#ifndef LIST_LINK_H
#define LIST_LINK_H

#include "List.h"
#include <iostream>
#define LinkPosi(T) Link<T>*
#define defaultSize 200

namespace DSLibrary {
    namespace Single_Linked {
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
                listSize = 0;
            }

            void removeAll();
        public:
            Llist(int size = defaultSize) { initialize(); } //defaultSize有啥用处
            ~Llist() { removeAll(); }

            template<typename VST> void trav(VST &visit) const; //遍历链表
            void clear() {
                removeAll();
                initialize();
            }

            void insert(const T &x); //插入
            void append(const T &x); //追加
            T remove(); //删除

            //位置操作
            void removeToStart();

            void removeToEnd();

            void prev();

            void next();

            void moveToPosi(int newPosi);

            int currentPosi();

            const T &getValue();

            T &operator[](int posi);
        };
    }
}
#endif //LIST_LINK_H

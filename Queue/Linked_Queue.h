//
// Created by Jeza on 2017/9/14.
//

#ifndef QUEUE_LINKED_QUEUE_H
#define QUEUE_LINKED_QUEUE_H

#include "Queue.h"
#include "../List/Link.h" //引入链表头文件
namespace DSLibrary {
    namespace Single_Linked {

        template<typename T>
        class LQueue : public Queue<T> {
        private:
            LinkPosi(T)head;
            LinkPosi(T)rear;
            int _size;
        public:
            LQueue() {
                _size = 0;
                head = rear = new Link<T>;
            } //init
            ~LQueue() {
                clear();
                delete head;
            } //TODO

            void clear()
            {
                while (head->next) {
                    rear = head;
                    head = head->next;
                    release(rear);
                }
                rear = head;
                _size = 0;
            }
            void enqueue(const T &e)
            {
                    rear = rear->next = new Link<T>(e, NULL);
                    _size++;
            }
            T dequeue()
            {
                if (_size == 0)
                    throw queueEmpty_Exception(); //抛出队空异常
                //else
                LinkPosi(T)temp = head->next;
                T data_temp = temp->data;
                if (temp == rear)
                    rear = head;
                head->next = head->next->next; //并不用else
                release(temp);
                _size--;
                return data_temp;
            }
            const T &front() const
            {
                if (_size == 0)
                    throw queueEmpty_Exception(); //抛出队空异常
                if (_size == 0) {}
                return head->next->data;
            }
            int size() const
            {
                return _size;
            }
        };
    }
}
#endif //QUEUE_LINKED_QUEUE_H

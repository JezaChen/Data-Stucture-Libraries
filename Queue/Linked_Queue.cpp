//
// Created by Jeza on 2017/9/14.
//
#include"Linked_Queue.h"
#include "../Common/Share.h"
#include "../Common/Exception_Handler.h"

namespace DSLibrary {
    namespace Single_Linked {

        template<typename T>
        void LQueue<T>::clear() {
            while (head->next) {
                rear = head;
                head = head->next;
                release(rear);
            }
            rear = head;
            _size = 0;
        }

        template<typename T>
        void LQueue<T>::enqueue(const T &e) {
            rear = rear->next = new Link<T>(e, NULL);
            _size++;
        }

        template<typename T>
        T LQueue<T>::dequeue() {
            if (_size == 0)
                throw queueEmpty_Exception(); //抛出队空异常
            //else
            LinkPosi(T)temp = head->next;
            T data_temp = temp->data;
            if (temp == rear)
                rear = head;
            head->next = head->next->next; //并不用else
            delete temp;
            _size--;
            return data_temp;
        }

        template<typename T>
        T LQueue<T>::front() const {
            if (_size == 0)
                throw queueEmpty_Exception(); //抛出队空异常
            if (_size == 0) {}
            return head->next->data;
        }

        template<typename T>
        int LQueue<T>::size() const {
            return _size;
        }
    }
}
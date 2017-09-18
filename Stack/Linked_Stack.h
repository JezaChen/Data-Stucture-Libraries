//
// Created by Jeza on 2017/9/14.
//

#ifndef STACK_LINKED_STACK_H
#define STACK_LINKED_STACK_H
#define defualtSize 250

#include  "Stack_common.h"
#include "../List/Link.h" //引入链表头文件

namespace DSLibrary {
    namespace Single_Linked {

        template<typename T>
        class LStack : public Stack<T> {
        private:
            LinkPosi(T)_top;
            int _size;
        public:
            LStack(int s = defaultSize) : _size(s) {}

            ~LStack() { clear(); }

            void clear()
            {
                while (_top) {
                    LinkPosi(T)t = _top;
                    release(t);
                    _top = _top->next;
                }
                _size = 0; //记得要置零长度
            }
            void push(const T &e)
            {
                _top = new Link<T>(e, _top);
                _size++;
            }
            T pop()
            {
                if (!_size) throw stackEmpty_Exception(); //这时候抛出空战异常吧
                T data_temp = _top->data;
                LinkPosi(T)pointer_temp = _top;
                _top = _top->next;
                release(pointer_temp);
                _size--;
                return data_temp;
            }
            T top()
            {
                if (!_size) throw stackEmpty_Exception();
                return _top->data;
            }
            int size() {  return _size; }
        };
    }
}
#endif //STACK_LINKED_STACK_H

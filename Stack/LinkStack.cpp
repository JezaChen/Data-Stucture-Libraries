//
// Created by Jeza on 2017/9/14.
//

#include "Linked_Stack.h"
#include "../Common/Share.h"
#include "../Common/Exception_Handler.h"
namespace DSLibrary {
    namespace Single_Linked {

        template<typename T>
        void LStack<T>::clear() {
            while (_top) {
                LinkPosi(T)t = _top;
                release(t);
                _top = _top->next;
            }
            _size = 0; //记得要置零长度
        }

        template<typename T>
        void LStack<T>::push(const T &e) {
            _top = new Link<T>(e, _top);
            _size++;
        }
        template<typename T>
        T LStack<T>::pop() {
            if (!_size) throw stackEmpty_Exception(); //这时候抛出空战异常吧
            T data_temp = _top->data;
            LinkPosi(T)pointer_temp = _top;
            _top = _top->next;
            release(pointer_temp);
            _size--;
            return data_temp;
        }
        template<typename T>
        T LStack<T>::top() {
            if (!_size) throw stackEmpty_Exception();
            return _top->data;
        }
        template<typename T>
        int LStack<T>::size() {
            return _size;
        }
    }
}
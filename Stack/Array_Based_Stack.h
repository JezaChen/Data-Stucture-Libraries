//
// Created by Jeza on 2017/9/14.
//

#ifndef STACK_ARRAY_BASED_STACK_H
#define STACK_ARRAY_BASED_STACK_H
#include "Stack_common.h"
#define defaultSize 250
namespace DSLibrary {
    template<typename T>
    class AStack : public Stack<T> {
    private:
        int capacity; //最大容量
        int _size; //当前容量
        T *listArray;
    public:
        AStack(int op = defaultSize) : capacity(op) { listArray = new T[capacity]; }

        ~AStack() { delete[] listArray; }

        void clear()
        {
            _size = 0; //_size=0即可
        }
        void push(const T &e)
        {
            if (_size == capacity) throw arrayFull_Exception("stack");
            listArray[_size++] = e;
        }
        T pop()
        {
            if (!_size) throw stackEmpty_Exception(); //抛出空战异常
            T temp = listArray[(_size--) - 1];
            return temp;
        }
        T top()
        {
            if (!_size) throw stackEmpty_Exception();
            return listArray[_size - 1];
        }
        int size() { return _size; }
    };
}
#endif //STACK_ARRAY_BASED_STACK_H

//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_EXCEPTION_HANDLER_H
#define LIST_EXCEPTION_HANDLER_H

#include <iostream>
using namespace std;

namespace DSLibrary {
    enum OUT_OF_BOUNDS_STATUS {
        OVERFLOWED = 0, UNDERFLOWED = 1
    };

    class outOfBounds_Exception {
    private:
        OUT_OF_BOUNDS_STATUS status;
    public:
        outOfBounds_Exception(OUT_OF_BOUNDS_STATUS s) : status(s) {}

        void print() {
            cerr << "Position out of range: ";
            if (status == OVERFLOWED) cerr << "overflowed." << endl;
            else cerr << "underflowed" << endl;
        }
    };

    class arrayFull_Exception {
    private:
        char *name;
    public:
        arrayFull_Exception(char *target_name) : name(target_name) {}

        void print() {
            cerr << "The " << name << " is too full to insert any elements!" << endl;
        }
    };

    class nullPointer_Exception {
    public:
        nullPointer_Exception() {}

        void print() {
            cerr << "No elements!" << endl;
        }
    };

    class stackEmpty_Exception //栈空异常
    {
    public:
        stackEmpty_Exception() {}

        void print() {
            cerr << "The Stack is EMPTY!" << endl;
        }
    };

    class queueEmpty_Exception //队空异常
    {
    public:
        queueEmpty_Exception() {}

        void print() {
            cerr << "The Queue is EMPTY!" << endl;
        }
    };
}
#endif //LIST_EXCEPTION_HANDLER_H

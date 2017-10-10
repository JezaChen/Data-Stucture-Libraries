//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_EXCEPTION_HANDLER_H
#define LIST_EXCEPTION_HANDLER_H

#include <iostream>
#include <cstring>

using namespace std;

namespace DSLibrary
{
    enum OUT_OF_BOUNDS_STATUS
    {
        OVERFLOWED = 0, UNDERFLOWED = 1
    };

    class outOfBounds_Exception
    {
    private:
        OUT_OF_BOUNDS_STATUS status;
    public:
        outOfBounds_Exception(OUT_OF_BOUNDS_STATUS s) : status(s) {}

        void print()
        {
            cerr << "Position out of range: ";
            if (status == OVERFLOWED) cerr << "overflowed." << endl;
            else cerr << "underflowed" << endl;
        }
    };

    class arrayFull_Exception
    {
    private:
        char *name;
    public:
        arrayFull_Exception(char *target_name) {strcpy(name,target_name);}

        void print()
        {
            cerr << "The " << name << " is too full to insert any elements!" << endl;
        }
    };

    class nullPointer_Exception //空指针异常
    {
    public:
        nullPointer_Exception() {}

        void print()
        {
            cerr << "nullPointer!" << endl;
        }
    };

    class stackEmpty_Exception //栈空异常
    {
    public:
        stackEmpty_Exception() {}

        void print()
        {
            cerr << "The Stack is EMPTY!" << endl;
        }
    };

    class queueEmpty_Exception //队空异常
    {
    public:
        queueEmpty_Exception() {}

        void print()
        {
            cerr << "The Queue is EMPTY!" << endl;
        }
    };

    class binTreeEmpty_Exception //空树异常
    {
    public:
        binTreeEmpty_Exception() {}

        void print()
        {
            cerr<<"The tree is empty! "<<endl;
        }
    };

    class heapEmpty_Exception
    {
    public:
        heapEmpty_Exception() {}

        void print()
        {
            cerr<<"The heap is empty!"<<endl;
        }
    };
}
#endif //LIST_EXCEPTION_HANDLER_H

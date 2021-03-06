//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_EXCEPTION_HANDLER_H
#define LIST_EXCEPTION_HANDLER_H

#include <iostream>
#include <string>

using namespace std;

namespace DSLibrary
{
    enum OUT_OF_BOUNDS_STATUS
    {
        LOWER_BOUND,UPPER_BOUND
    };

    class outOfBounds_Exception
    {
    private:
        OUT_OF_BOUNDS_STATUS status;
    public:
        outOfBounds_Exception(OUT_OF_BOUNDS_STATUS s) : status(s) {}

        void print()
        {
            cerr << "Position has reached the ";
            if (status == UPPER_BOUND) cerr << "upper bound." << endl;
            else cerr << "lower bound." << endl;
        }
    };

    class arrayFull_Exception
    {
    private:
        string name;
    public:
        arrayFull_Exception(const string& target_name) {name=target_name;}

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

    class listEmpty_Exception
    {
    public:
        listEmpty_Exception() {}
        void print()
        {
            cerr << "The list is EMPTY!"<<endl;
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

    class hashDictKeyCollision_Exception
    {
    public:
        hashDictKeyCollision_Exception() {}

        void print()
        {
            cerr<<"The Key Collision Occurs!"<<endl;
        }
    };

    class hashDictFull_Exception
    {
    public:
        hashDictFull_Exception() {}

        void print()
        {
            cerr<<"The Hash Table is full!"<<endl;
        }
    };

    class hashDictEmpty_Exception
    {
    public:
        hashDictEmpty_Exception() {}

        void print()
        {
            cerr<<"The Hash Dict is EMPTY!"<<endl;
        }
    };
}
#endif //LIST_EXCEPTION_HANDLER_H

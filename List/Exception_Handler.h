//
// Created by Jeza on 2017/9/14.
//

#ifndef LIST_EXCEPTION_HANDLER_H
#define LIST_EXCEPTION_HANDLER_H
#include <iostream>
using namespace std;

enum OUT_OF_BOUNDS_STATUS {OVERFLOWED=0,UNDERFLOWED=1};

class outOfBounds_Exception
{
private:
    OUT_OF_BOUNDS_STATUS status;
public:
    outOfBounds_Exception(OUT_OF_BOUNDS_STATUS s):status(s) {}
    void print()
    {
        cerr<<"Position out of range: ";
        if(status==OVERFLOWED) cerr<<"overflowed."<<endl;
        else cerr<<"underflowed"<<endl;
    }
};

class listFull_Exception
{
public:
    listFull_Exception() {}
    void print()
    {
        cerr<<"The list is too full to insert any elements!"<<endl;
    }
};

class nullPointer_Exception
{
public:
    nullPointer_Exception() {}
    void print()
    {
        cerr<<"No elements!"<<endl;
    }
};
#endif //LIST_EXCEPTION_HANDLER_H

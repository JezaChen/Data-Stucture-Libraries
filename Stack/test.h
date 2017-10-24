//
// Created by Jeza on 2017/9/22.
//
#pragma once
#ifndef DSL_STACK_TEST_H
#define DSL_STACK_TEST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Stack_common.h"
#include "Linked_Stack.h"
#include "Array_Based_Stack.h"
#include "../Common/Exception_Handler.h"
#include "uniPRINTER/print.h"

using namespace DSLibrary;

void stack_all_functions()
{
    cout.setf(ios::left);
    cout<<setw(20)<<"push (num)"<<setw(30)<<"push the element"<<endl;
    cout<<setw(20)<<"pop"<<setw(30)<<"pop the element"<<endl;
    cout<<setw(20)<<"top"<<setw(30)<<"get the top element of the stack"<<endl;
    cout<<setw(20)<<"size"<<setw(30)<<"get the size of the stack"<<endl;
    cout<<setw(20)<<"clear "<<setw(30)<<"delete all elements in the stack"<<endl;
}

void stack_test()
{
    int choice;
    cout<<"Select one of the following data structures for test"<<endl;
    cout<<"1.Linked Stack   2.Array Based Stack"<<endl;
    cin>>choice;

    stack_all_functions();

    Stack<int>* S;
    if(choice==1) S=new Single_Linked::LStack<int>();
    if(choice==2) S=new AStack<int>();
    string order;
    while(cin>>order)
    {
        if(order=="push")
        {
            try
            {
                int target;  cin>>target;
                S->push(target);
                cout<<"Succeed. "<<endl;
                continue;
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                continue ;
            }
        }
        if(order=="pop")
        {
            try
            {
                cout<<S->pop()<<endl;
                continue;
            }
            catch(stackEmpty_Exception& e)
            {
                e.print();  continue;
            }
        }
        if(order=="top")
        {
            try
            {
                cout<<S->top()<<endl;
                continue;
            }
            catch(stackEmpty_Exception& e)
            {
                e.print();  continue;
            }
        }
        if(order=="size")
        {
            cout<<S->size()<<endl; continue;
        }
        if(order=="clear")
        {
            S->clear();
            cout<<"Succeed. "<<endl; continue;
        }
        if(order=="end")  { break;}
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
            cin.ignore(100,'\n');
        }
    }
    release(S);
}
#endif //DSL_STACK_TEST_H

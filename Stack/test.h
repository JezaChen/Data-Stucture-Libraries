//
// Created by Jeza on 2017/9/22.
//

#ifndef DSL_TEST_H
#define DSL_TEST_H
#include <iostream>
#include <string>
#include "Stack_common.h"
#include "Linked_Stack.h"
#include "Array_Based_Stack.h"
#include "../Common/Exception_Handler.h"
#include "uniPRINTER/print.h"

using namespace DSLibrary;

void stack_test()
{
    int choice;
    cout<<"Select one of the following data structure for test"<<endl;
    cout<<"1.Linked Stack   2.Array Based Stack"<<endl;
    cin>>choice;
    cout<<"You can do something in the following examples: push, pop, top, size, clear"<<endl;
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
                //TODO:需要扩容操作
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
                e.print();
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
                e.print();
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
        if(order=="end")  {break;}
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
        }
    }
}
#endif //DSL_TEST_H

//
// Created by Jeza on 2017/9/22.
//
#pragma once
#ifndef DSL_LIST_TEST_H
#define DSL_LIST_TEST_H
#include <iostream>
#include <iomanip>
#include "List.h"
#include "AList.h"
#include "Link.h"
#include "Doubly_Linked_List.h"
#include "Exception_Handler.h"

using namespace DSLibrary;

void list_all_functions()
{
    cout.setf(ios::left);
    cout<<setw(20)<<"moveToStart"<<setw(30)<<"move the barrier to start"<<endl;
    cout<<setw(20)<<"moveToEnd"<<setw(30)<<"move the barrier to end"<<endl;
    cout<<setw(20)<<"prev"<<setw(30)<<"move the barrier to the previous position"<<endl;
    cout<<setw(20)<<"next"<<setw(30)<<"move the barrier to the next position"<<endl;
    cout<<setw(20)<<"moveToPosi (num)"<<setw(30)<<"move the barrier to the position you want"<<endl;
    cout<<setw(20)<<"insert (num)"<<setw(30)<<"insert a number after the barrier"<<endl;
    cout<<setw(20)<<"remove"<<setw(30)<<"delete the element which is the first one after the barrier"<<endl;
    cout<<setw(20)<<"append (num)"<<setw(30)<<"append a number"<<endl;
    cout<<setw(20)<<"get"<<setw(30)<<"get the element which is the first one after the barrier"<<endl;
    cout<<setw(20)<<"print"<<setw(30)<<"print the list"<<endl;
}
void list_test(int choice)
{
    list_all_functions();
    List<int>* test;
    if(choice==1) test=new Alist<int>();
    else if(choice==2) test=new Single_Linked::Llist<int>();
    else test=new Double_Linked::Llist<int>();
    string order;
    int target;
    while(cin>>order)
    {
        if(order=="insert")
        {
            cin>>target;
            try
            {
                test->insert(target);
                cout<<"insert "<<target<<" successfully."<<endl;
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="remove")
        {
            try
            {

                int r=test->remove();
                cout<<"Now you have removed the element "<<r<<endl;
            }
            catch(nullPointer_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="append")
        {
            cin>>target;
            try
            {
                test->append(target);
                cout<<"append "<<target<<" successfully."<<endl;
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="get")
        {
            try
            {
                cout<<test->getValue()<<endl;
            }
            catch(nullPointer_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="moveToStart")
        {
            test->moveToStart();
        }
        else if(order=="moveToEnd")
        {
            test->moveToEnd();
        }
        else if(order=="prev")
        {
            try
            {
                test->prev();
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="next")
        {
            try
            {
                test->next();
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="moveToPosi")
        {
            cin>>target;
            try
            {
                test->moveToPosi(target);
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        else if(order=="print")
        {
            print(test);
            printf("\n");
        }
        else if(order=="end")
        {
            break;
        }
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
            cin.ignore(100,'\n');
        }
    }
    release(test);
}

#endif //DSL_LIST_TEST_H

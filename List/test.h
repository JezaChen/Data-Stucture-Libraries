//
// Created by Jeza on 2017/9/22.
//
#pragma once
#ifndef DSL_LIST_TEST_H
#define DSL_LIST_TEST_H
#include <iostream>
#include "List.h"
#include "AList.h"
#include "Link.h"
#include "Doubly_Linked_List.h"
#include "Exception_Handler.h"
using namespace DSLibrary;
void list_test(int choice)
{
    cout<<"Tips: now you can do something just like insert, remove..."<<endl;
    //1. moveToStart 2. moveToEnd 3. prev 4.next 5.moveToPosi 6.insert 7.delete 8.append 9.get 10.trav
    List<int>* test;
    if(choice==1) test=new Alist<int>();
    else if(choice==2) test=new Single_Linked::Llist<int>();
    else test=new Double_Linked::Llist<int>();
    string order;
    while(cin>>order)
    {
        if(order=="insert")
        {
            int target; cin>>target;
            try
            {
                test->insert(target);
                cout<<"succeed"<<endl;
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
            int target; cin>>target;
            try
            {
                test->append(target);
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
            int target; cin>>target;
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
            if(choice==1) print((Alist<int>*) test);
            else if(choice==2) print((Single_Linked::Llist<int>*) test);
            else print((Double_Linked::Llist<int>*) test);
            printf("\n");
        }
        else if(order=="end")
        {
            break;
        }
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
        }
    }

}

#endif //DSL_LIST_TEST_H
